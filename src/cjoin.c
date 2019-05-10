/**
 * Implementation of CThread's cjoin function, including supporting functions.
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
//                                         CJOIN
// ======================================================================================

/**
 * Interrupt execution until another thread finishes.
 * 
 * @param tid Identifier of thread to wait for.
 * @return 0 if successful, -1 otherwise.
 */
int cjoin(int tid) {

	JoinBlocked *new_join = (JoinBlocked*)malloc(sizeof(JoinBlocked));;
	TCB_t *executing_t;
	TCB_t *next;
	extern FILA2 exec;

	if(init_scheduler() != 0)
		return -1;

	if(search_tid(tid) == 0)
	{	
		new_join->tid = tid;

		if(FirstFila2(&exec) != 0)
			return -2;
		executing_t = which_executing_t();

		if(DeleteAtIteratorFila2(&exec) != 0)
			return -3;
		executing_t->state = PROCST_BLOQ;

		new_join->blocked_t = executing_t;

		if(join_block_t(new_join) != 0)
			return -4;

		next = exec_next();
	
		swapcontext(&executing_t->context, &next->context);
	}
	return 0;
}
