/**
 * Implementation of CThread's cwait function, including supporting functions.
 *
 * @author Renan Kummer
 */
#include "../include/constants.h"
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"

#include <stdio.h>

// ======================================================================================
//                            SUPPORT FUNCTIONS - DECLARATION
// ======================================================================================

int cwait_insert_to_queue(csem_t *sem);
int cwait_find_position_to_insert(PFILA2 *semaphore_queue, Priority priority);


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
int cwait(csem_t *sem) {

    sem -> count--;
    if (sem->count <= 0)
        return cwait_insert_to_queue(sem);
    else
        return CTHREAD_SUCCESS;
}


// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

int cwait_insert_to_queue(csem_t *sem)
{
    TCB_t* current_thread = NULL;

    int return_code = InsertAfterIteratorFila2(sem->fila, current_thread);

    if (return_code != CTHREAD_SUCCESS)
        return CTHREAD_FAILURE;
    else
        return CTHREAD_SUCCESS;

}

int cwait_find_position_to_insert(PFILA2 *semaphore_queue, Priority priority)
{
    if (semaphore_queue == NULL)
        return CTHREAD_FAILURE;

    int result_code;
    switch (priority)
    {
        case LOW:
            result_code = LastFila2(*semaphore_queue);
            break;

        case MEDIUM:

            break;

        case HIGH:
            result_code = FirstFila2(*semaphore_queue);
            if (result_code == CTHREAD_SUCCESS)
            {
                TCB_t *thread = (TCB_t*) GetAtNextIteratorFila2(*semaphore_queue);

                while (thread != NULL && thread->prio == HIGH)
                {
                    NextFila2(*semaphore_queue);
                    thread = (TCB_t*) GetAtNextIteratorFila2(*semaphore_queue);
                }
            }
            break;
    }
}
