/**
 * Implementation of CThread's csignal function, including supporting functions.
 * 
 * @author Marlize Ramos
 */
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"

#include <stdio.h>

// ======================================================================================
//                            SUPPORT FUNCTIONS - DECLARATION
// ======================================================================================

/**
 * Sample of support function. It uses csignal prefix to avoid naming conflicts.
 */ 
void csignal_hello_world();


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
	return -1;
}


// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

void csignal_hello_world()
{
    printf("Hello world!\n");
}
