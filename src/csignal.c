/**
 * Implementation of CThread's csignal function, including supporting functions.
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
//                                        CSIGNAL
// ======================================================================================

/**
 * Release a resource managed by a semaphore variable.
 * 
 * @param sem   Pointer to semaphore variable that manages the released resource.
 * @return 0 if successful, -1 otherwise.
 */
int csignal(csem_t *sem) {
	return CTHREAD_NOT_IMPLEMENTED;
}


// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

