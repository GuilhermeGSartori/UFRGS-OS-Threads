/**
 * Implementation of CThread's csem_init function, including supporting functions.
 * 
 * @author Renan Kummer
 */
#include "../include/constants.h"
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/scheduler.h"
#include <stdlib.h>

// ======================================================================================
//                                       CSEM_INIT
// ======================================================================================

/**
 * Initialize a semaphore variable.
 * 
 * @param sem   Pointer to semaphore variable to initialize.
 * @param count Quantity of resources managed by semaphore.
 * @return 0 if successful, -1 otherwise.
 */
int csem_init(csem_t *sem, int count) 
{
    if (sem == NULL || count <= 0)
        return CTHREAD_FAILURE;

    //if(init_scheduler() != 0)
     //   return CTHREAD_FAILURE;

    int result_code = CreateFila2(sem->fila);
    if (result_code != CTHREAD_SUCCESS)
        return CTHREAD_FAILURE;
    
    sem->count = count;
	return CTHREAD_SUCCESS;

}
