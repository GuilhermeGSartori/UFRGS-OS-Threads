/**
 * Implementation of CThread's cwait function, including supporting functions.
 *
 * @author Renan Kummer
 */
#include "../include/constants.h"
#include "../include/scheduler.h"
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/scheduler.h"
#include <stdio.h>

// ======================================================================================
//                                    GLOBAL VARIABLES
// ======================================================================================

extern FILA2 ready_low;
extern FILA2 ready_mid;
extern FILA2 ready_high;
extern FILA2 exec;


// ======================================================================================
//                            SUPPORT FUNCTIONS - DECLARATION
// ======================================================================================

/**
 * Insert current running thread in the semaphore queue at the end of the queue.
 * 
 * @param sem The semaphore.
 * @return CTHREAD_SUCCESS if successful, CTHREAD_FAILURE otherwise.
 */
ResultCode cwait_insert_to_queue(csem_t *sem);

/**
 * Clear EXEC queue since the running thread has been blocked waiting for a resource.
 * 
 * @return CTHREAD_SUCCESS if successful, CTHREAD_FAILURE otherwise.
 */
ResultCode cwait_clear_exec();

/**
 * Execute highest priority thread in APTO queues.
 * 
 * @return CTHREAD_SUCCESS if successful, CTHREAD_FAILURE otherwise.
 */
ResultCode cwait_run_highest_priority_thread();


// ======================================================================================
//                                         CWAIT
// ======================================================================================

/**
 * Request access to a resource managed by a semaphore variable. May block the thread
 * until the resource is available.
 *
 * @param sem   Pointer to semaphore variable that manages the requested resource.
 * @return 0 if successful, -1 otherwise.
 */
int cwait(csem_t *sem) 
{
    if (sem == NULL)
        return CTHREAD_FAILURE;

    if(init_scheduler() != 0)
        return CTHREAD_FAILURE;

    sem -> count--;
    if (sem->count <= 0)
    {
        if (cwait_insert_to_queue(sem) == CTHREAD_FAILURE)
            return CTHREAD_FAILURE;

       // if (cwait_run_highest_priority_thread() == CTHREAD_FAILURE)
         //   return CTHREAD_FAILURE;
    }

    return CTHREAD_SUCCESS;
}


// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

ResultCode cwait_insert_to_queue(csem_t *sem)
{
    TCB_t* current_thread = which_executing_t();
    current_thread->state = PROCST_BLOQ;

    if (AppendFila2(sem->fila, current_thread) == CTHREAD_SUCCESS)
        return CTHREAD_SUCCESS;
    else
        return CTHREAD_FAILURE;
}

ResultCode cwait_clear_exec()
{
    if (FirstFila2(&exec) == CTHREAD_SUCCESS)
    {
        if (DeleteAtIteratorFila2(&exec) == CTHREAD_SUCCESS)
            return CTHREAD_SUCCESS;
        else
            return CTHREAD_FAILURE;
    }

    return CTHREAD_SUCCESS;
}

ResultCode cwait_run_highest_priority_thread()
{

    TCB_t* current_thread = which_executing_t();
    cwait_clear_exec();
    
    TCB_t* next_thread = get_most_prio_t();
    if (AppendFila2(&exec, next_thread) == CTHREAD_SUCCESS)
    {
     
        next_thread->state = PROCST_EXEC;
     
        swapcontext(&current_thread->context, &next_thread->context);   
        return CTHREAD_SUCCESS;
    }

    return CTHREAD_FAILURE;
}