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
TCB_t *running_thread = NULL;
TCB_t *running_thread2 = NULL;
FILA2 ready_low;
FILA2 ready_mid;
FILA2 ready_high;


int init_scheduler()
{
	if(!__scheduler_init)
	{
		init_main();
		init_queues();
		
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

		__queu_init = 1;
	}

	return 0;
}

int init_main()
{
	if(!__tcb_main_init)
	{

		main_t = (TCB_t*)malloc(sizeof(TCB_t));
		running_thread = (TCB_t*)malloc(sizeof(TCB_t));
		running_thread2 = (TCB_t*)malloc(sizeof(TCB_t));
		getcontext(&(main_t->context));
		//initialiaze context space for the TCB thread (logicly defined to the main thread)
		//the actual PC, SP and etc from the main is only saved when swapcontext is used!
		//then, when evoked again, recovering the main context from the main, it continues
		//after the swap!
		//since the main is already executing, it doesnt need the "makecontext"
		main_t->tid = TID;
		main_t->state = PROCST_EXEC;
		main_t->prio = 2;
		running_thread = main_t;

		__tcb_main_init = 1;
	}

	return 0;
}