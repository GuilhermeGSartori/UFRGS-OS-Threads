/**
 * Implementation of CThread's cyield function, including supporting functions.
 * 
 * @author Guilherme Sartori
 */
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/scheduler.h"
#include "ucontext.h"

#include <stdio.h>

// ======================================================================================
//                                         CYIELD
// ======================================================================================

/**
 * Voluntarily releases the CPU for other threads.
 * 
 * @return 0 if successful, -1 otherwise.
 */
int cyield(void) {

	TCB_t *next;
	TCB_t *executing_t;//since its a pointer, it is goint the use the context in the same address
	extern FILA2 exec;

	if(init_scheduler() != 0)
		return -1;

	if(FirstFila2(&exec) != 0)
		return -2;
	executing_t = which_executing_t();

	if(set_as_ready(executing_t) != 0)
		return -3;
	if(DeleteAtIteratorFila2(&exec) != 0)
		return -4;
	executing_t->state = PROCST_APTO;

	next = exec_next();
	
	swapcontext(&executing_t->context, &next->context);

	return 0;
}

