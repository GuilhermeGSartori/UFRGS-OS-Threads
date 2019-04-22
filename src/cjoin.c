/**
 * Implementation of CThread's cjoin function, including supporting functions.
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
 * Sample of support function. It uses cjoin_ prefix to avoid naming conflicts.
 */ 
void cjoin_hello_world();


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
	return -1;
}


// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

void cjoin_hello_world()
{
    printf("Hello world!\n");
}
