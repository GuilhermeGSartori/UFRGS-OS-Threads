/**
 * Implementation of CThread's cidentify function, including supporting functions.
 * 
 * @author Renan Kummer
 */
#include "../include/result_code.h"
#include "../include/cthread.h"
#include <stdlib.h>
#include <string.h>


// =============================================================================================
//                                           CONSTANTS
// =============================================================================================
#define CIDENTIFY_MINIMUM_SIZE 98


// ======================================================================================
//                            SUPPORT FUNCTIONS - DECLARATION
// ======================================================================================

/**
 * Clear the contents of string.
 * 
 * @param string A string to be cleared.
 */ 
void cidentify_clear(char* string);

/**
 * Set names and university IDs of students in the development group.
 * 
 * @param array An array to write the string to.
 */
void cidentify_set_identification(char* array);

/**
 * Get names and university IDs of students in the development group.
 * 
 * @return A string containing the names and university IDs of students in the 
 *         development group.
 */
char* cidentify_get_identification();


// ======================================================================================
//                                       CIDENTIFY
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
	if (name == NULL)
		return CTHREAD_FAILURE;
	if (size < CIDENTIFY_MINIMUM_SIZE)
		return CTHREAD_FAILURE;

	cidentify_set_identification(name);
	return CTHREAD_SUCCESS;
}


// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

void cidentify_clear(char* string)
{
    if (string != NULL)
		string[0] = '\0';
}

void cidentify_set_identification(char* array)
{
	if (array != NULL) 
	{
		cidentify_clear(array);
		strcpy(array, cidentify_get_identification());
	}
}

char* cidentify_get_identification()
{
	return "Guilherme Girotto Sartori 00274713\nMarlize Ramos Batista 00274703\nRenan Kummer de Jesus 00208946\n";
}
