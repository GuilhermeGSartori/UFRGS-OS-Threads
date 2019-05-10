/**
 * Implementation of CThread's ccreate function, including supporting functions.
 * 
 * @author Guilherme Sartori
 */
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/scheduler.h"
#include "ucontext.h"

#include <stdio.h>
#include <stdlib.h>



// ======================================================================================
//                                        CCREATE
// ======================================================================================

/**
 * Create a new thread.
 * 
 * @param start Pointer to function to run in new thread.
 * @param arg   Parameter to pass to new thread.
 * @param prio  Priority of new thread
 *                0 = HIGH
 *                1 = MEDIUM
 *                2 = LOW
 * @return The thread identifier (tid) when successful, -1 otherwise.
 */
int ccreate(void* (*start)(void*), void *arg, int prio) {

	int tid_r;
	extern int TID;
	extern ucontext_t *end_context;
	extern FILA2 tid_list;

	if(prio < 0 || prio > 2)
		return -1;


	if(init_scheduler() != 0)
		return -2;

	TCB_t* new_thread = (TCB_t*)malloc(sizeof(TCB_t));

	getcontext(&(new_thread->context));
	new_thread->tid = ++TID;
	if(AppendFila2(&tid_list, &new_thread->tid) != 0)
		return -1;
	new_thread->prio = prio;
	new_thread->context.uc_link = end_context;
	new_thread->context.uc_stack.ss_sp = (char*)malloc(STACK_SIZE);
	new_thread->context.uc_stack.ss_size = STACK_SIZE;
	makecontext(&(new_thread->context), (void(*)(void))start, HOW_MANY_ARGS, (void *)arg);

	tid_r = TID;


	if(set_as_ready(new_thread) != 0)
		return -3;


	return tid_r;
	
}
