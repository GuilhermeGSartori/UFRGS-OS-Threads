/**
 * Implementation of CThread's cyield function, including supporting functions.
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
 * Sample of support function. It uses cyield_ prefix to avoid naming conflicts.
 */ 
void cyield_hello_world();


// ======================================================================================
//                                         CYIELD
// ======================================================================================

/**
 * Voluntarily releases the CPU for other threads.
 * 
 * @return 0 if successful, -1 otherwise.
 */
int cyield(void) {
	return -1;
}


// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

void cyield_hello_world()
{
    printf("Hello world!\n");
}
