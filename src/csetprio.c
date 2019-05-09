/**
 * Implementation of CThread's csetprio function, including supporting functions.
 *
 * @author Marlize Ramos
 */
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/constants.h"   //precisa mudar para constants.h
#include "../include/scheduler.h"

#include <stdio.h>

// ======================================================================================
//                                        CSETPRIO
// ======================================================================================

/**
 * Modify the priority of a thread.
 *
 * @param tid  Identifier of thread to modify --> always NULL
 * @param prio Priority to set.
 * @return 0 if successful, -1 otherwise.
 */
int csetprio(int tid, int prio) {
    if(prio < 0 || prio > 2)
        return CTHREAD_FAILURE;

    if(init_scheduler() != 0)
        return CTHREAD_FAILURE;

    TCB_t *executing_t = which_executing_t();
    if(executing_t == NULL)
        return CTHREAD_FAILURE;

    else
    {
        executing_t->prio = prio;
        executing_t->state = PROCST_EXEC;

        return CTHREAD_SUCCESS;
    }
}


