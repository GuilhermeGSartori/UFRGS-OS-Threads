/**
 * Implementation of CThread's csetprio function, including supporting functions.
 * 
 * @author Renan Kummer
 */
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"

#include <stdio.h>

// ======================================================================================
//                            SUPPORT FUNCTIONS - DECLARATION
// ======================================================================================

/**
 * Sample of support function. It uses csetprio_ prefix to avoid naming conflicts.
 */ 
void csetprio_hello_world();


// ======================================================================================
//                                        CSETPRIO
// ======================================================================================

/**
 * Modify the priority of a thread.
 * 
 * @param tid  Identifier of thread to modify.
 * @param prio Priority to set.
 * @return 0 if successful, -1 otherwise.
 */
int csetprio(int tid, int prio) {
	return -1;
}


// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

void csetprio_hello_world()
{
    printf("Hello world!\n");
}
