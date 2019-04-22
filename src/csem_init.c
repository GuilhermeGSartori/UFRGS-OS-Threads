/**
 * Implementation of CThread's csem_init function, including supporting functions.
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
 * Sample of support function. It uses csem_init prefix to avoid naming conflicts.
 */ 
void csem_init_hello_world();


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
int csem_init(csem_t *sem, int count) {
	return -1;
}


// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

void csem_init_hello_world()
{
    printf("Hello world!\n");
}
