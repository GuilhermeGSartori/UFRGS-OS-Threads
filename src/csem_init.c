/**
 * Implementation of CThread's csem_init function, including supporting functions.
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
	return CTHREAD_NOT_IMPLEMENTED;
}


// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

