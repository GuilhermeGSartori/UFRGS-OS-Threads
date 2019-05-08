/** sheduler file:
// includes: Auxiliar functions
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/scheduler.h"
#include "../include/support.h"
#include "../include/cdata.h"
#include "ucontext.h"

/*
 * Global Variables Declaration
 * When used, they need to be declares in the files
 * that require them. Using "extern <type> <name>"
*/

int TID = 0;
_Bool __tcb_main_init = 0;
_Bool __queu_init = 0;
_Bool __scheduler_init = 0;
TCB_t *main_t = NULL;
ucontext_t *end_context = NULL;
FILA2 ready_low;
FILA2 ready_mid;
FILA2 ready_high;
FILA2 block_join;
FILA2 exec;

int init_scheduler()
{
	if(!__scheduler_init)
	{
		init_queues();
		init_main();

		
		if(!__tcb_main_init || !__queu_init)
			return -1;
		
		__scheduler_init = 1;	
	}

	return 0;
}

int init_queues()
{
	if(!__queu_init)
	{
		if(CreateFila2(&ready_low) != 0)
			return -1;
		if(CreateFila2(&ready_mid) != 0)
	 		return -2;
		if(CreateFila2(&ready_high) != 0)
			return -3;
		if(CreateFila2(&block_join) != 0)
			return -4;
		if(CreateFila2(&exec) != 0)
			return -5;
	

		__queu_init = 1;
	}

	return 0;
}

int init_main()
{
	if(!__tcb_main_init)
	{

		main_t = (TCB_t*)malloc(sizeof(TCB_t));
		end_context = (ucontext_t*)malloc(sizeof(ucontext_t));

		/*
		 *creates context for the "end of thread" function.
		 *this context is called when a thread ends (uc_link)
		 */
		getcontext(end_context);
		end_context->uc_link = NULL;
		end_context->uc_stack.ss_sp = (char*)malloc(20000);
		end_context->uc_stack.ss_size = 20000;
		makecontext(end_context, (void(*)(void))finish_thread, 0);

		/*
		 *initialiaze context space for the TCB thread (logicly defined to the main thread)
		 *the actual PC, SP and etc from the main is only saved when swapcontext is used!
		 *then, when evoked again, recovering the main context from the main, it continues
		 *after the swap!
		 *since the main is already executing, it doesnt need the "makecontext"
		 */
		main_t->tid = TID;
		main_t->state = PROCST_EXEC;
		main_t->prio = 2;
		
		getcontext(&(main_t->context));
		main_t->context.uc_link = NULL;
		main_t->context.uc_stack.ss_sp = (char*)malloc(20000);
		main_t->context.uc_stack.ss_size = 20000;
		
		
		if(AppendFila2(&exec, main_t) != 0)
			return -1;


		__tcb_main_init = 1;
	}

	return 0;
}

int finish_thread()
{
	TCB_t *executing;
	TCB_t *next;

	if(FirstFila2(&exec) != 0)
		return -1;
	executing = which_executing_t();

	if(DeleteAtIteratorFila2(&exec) != 0)
		return -2;

	executing->state = PROCST_TERMINO;
	
	if(check_if_join(executing->tid) != 0)
		return -3;
	
	free(executing->context.uc_stack.ss_sp);
	free(executing);
	
	next = get_most_prio_t();

	if(next == NULL)
		return 0;

	next->state = PROCST_EXEC;

	if(AppendFila2(&exec, next) != 0)
		return -4;	


	setcontext(&next->context);
	
	return 0;
}

int set_as_ready(TCB_t *thread)
{
	if(thread->prio == 2)
	{
		if(AppendFila2(&ready_low, thread) != 0)
			return -1;
		thread->state = PROCST_APTO;
		return 0;
	}

	else if(thread->prio == 1)
	{
		if(AppendFila2(&ready_mid, thread) != 0)
			return -1;
		thread->state = PROCST_APTO;
		return 0;
	}

	else if(thread->prio == 0)
	{
		if(AppendFila2(&ready_high, thread) != 0)
			return -1;
		thread->state = PROCST_APTO;	
		return 0;
	}
	return -2;
}

TCB_t *get_most_prio_t()
{
	TCB_t *most_wanted;

	if(FirstFila2(&ready_high) == 0)
	{
		most_wanted = GetAtIteratorFila2(&ready_high);
		
		if(DeleteAtIteratorFila2(&ready_high) != 0)
			return NULL;
		
		return most_wanted;
	}

	else if(FirstFila2(&ready_mid) == 0)
	{
		most_wanted = GetAtIteratorFila2(&ready_mid);
		
		if(DeleteAtIteratorFila2(&ready_mid) != 0)
			return NULL;
		
		return most_wanted;
	}
	else if(FirstFila2(&ready_low) == 0)
	{
		most_wanted = GetAtIteratorFila2(&ready_low);
		
		if(DeleteAtIteratorFila2(&ready_low) != 0)
			return NULL;
		
		return most_wanted;
	}

	return NULL;
}


TCB_t *which_executing_t()
{
	if(FirstFila2(&exec) == 0)
	{
		return GetAtIteratorFila2(&exec);
	}
	return NULL;
}

TCB_t *exec_next()
{
	TCB_t *next;

	next = get_most_prio_t();

	if(FirstFila2(&exec) != 0)
	{
		if(AppendFila2(&exec, next) != 0)
			return NULL;
		next->state = PROCST_EXEC;
	}
	else
		return NULL;

	return next;
}

int join_block_t(JoinBlocked *blocked)
{
	if(AppendFila2(&block_join, blocked) != 0)
		return -1;
	return 0;
}

int check_if_join(int tid)
{
	int queue_end;
	JoinBlocked *current;
	TCB_t *desblock;

	queue_end = FirstFila2(&block_join);

	while(queue_end == 0)
	{
		current = GetAtIteratorFila2(&block_join);
		if(current->tid == tid)
		{
			desblock = current->blocked_t;
			if(set_as_ready(desblock) != 0)
				return -1;
			desblock->state = PROCST_APTO;
			if(DeleteAtIteratorFila2(&block_join) != 0)
				return -2;
			queue_end = 1;
		}
		else
		{
			if(NextFila2(&block_join) != 0)
				queue_end = -1;	
		}
	}

	return 0;
}