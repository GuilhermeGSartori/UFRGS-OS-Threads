/**
 * Implementation of CThread's ccreate function, including supporting functions.
 * 
 * @author Guilherme Sartori
 */
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"

#include <stdio.h>

// ======================================================================================
//                            SUPPORT FUNCTIONS - DECLARATION
// ======================================================================================

/**
 * Sample of support function. It uses ccreate_ prefix to avoid naming conflicts.
 */ 
void ccreate_hello_world();


// ======================================================================================
//                                        CCREATE
// ======================================================================================

/**
 * Create a new thread.
 * 
 * @param start Pointer to function to run in new thread.
 * @param arg   Parameter to pass to new thread.
 * @param prio  Priority of new thread
 *                0 = HIGH
 *                1 = MEDIUM
 *                2 = LOW
 * @return The thread identifier (tid) when successful, -1 otherwise.
 */
int ccreate(void* (*start)(void*), void *arg, int prio) {
	return -1;
}


// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

void ccreate_hello_world()
{
    printf("Hello world!\n");
}
