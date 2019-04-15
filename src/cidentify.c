/**
 * Implementation of CThread's cidentify function, including supporting functions.
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
 * Sample of support function. It uses cidentify prefix to avoid naming conflicts.
 */ 
void cidentify_hello_world();


// ======================================================================================
//                                        CSIGNAL
// ======================================================================================

/**
 * Identify the developers of CThread library.
 * 
 * @param name Pointer to a region in memory where the developer names and university IDs
 *             must be written.
 * @param size Size of memory available to write.
 * @return 0 if successful, -1 otherwise.
 */
int cidentify (char *name, int size) {
	strncpy (name, "Sergio Cechin - 2017/1 - Teste de compilacao.", size);
	return 0;
}


// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

void cidentify_hello_world()
{
    printf("Hello world!\n");
}
