/**
 * Test suite to test the functionality provided by csem_init function.
 *
 * @author Marlize Ramos
 */
#include "../include/csem_init_test.h"
#include "../../include/constants.h"
#include "../../include/cthread.h"
#include <stdlib.h>

// =============================================================================================
//                                       GLOBAL VARIABLES
// =============================================================================================
csem_t* semaphore;


// =============================================================================================
//                                       CONTEXT FUNCTIONS
// =============================================================================================

/**
 * Set up test suite context (e.g. global variables). Run only once before all test cases.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void set_up_CSemInit()
{
	semaphore = (csem_t*) malloc(sizeof(csem_t));
}

/**
 * Set up test case context before each one. Run before each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void before_each_CSemInit()
{

}

/**
 * Teardown test case context after each one. Run after each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void after_each_CSemInit()
{

}

/**
 * Teardown test suite context (e.g. free allocated memory). Run only once after all test cases.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void teardown_CSemInit()
{
    free(semaphore);
}


// =============================================================================================
//                                          TEST CASES
// =============================================================================================

pnpcunit_Bool test_CSemInit_CreateValidSemaphore()
{
	return csem_init(semaphore, 3) == CTHREAD_SUCCESS;
}

pnpcunit_Bool test_CSemInit_CreateSemaphoreNullParameters()
{
	return csem_init(NULL, 3) == CTHREAD_FAILURE;
}

pnpcunit_Bool test_CSemInit_CreateSemaphoreLowCount()
{
	return (csem_init(semaphore, 0) == CTHREAD_FAILURE) && (csem_init(semaphore, -1) == CTHREAD_FAILURE);
}


// =============================================================================================
//                                         CONFIGURATION
// =============================================================================================

pnpcunit_TestSuite* configure_suite_CSemInit()
{
	pnpcunit_TestSuite *suite = pnpcunit_create_test_suite("CThread.CSemInit");

	suite->set_up      = set_up_CSemInit;
	suite->before_each = before_each_CSemInit;
	suite->after_each  = after_each_CSemInit;
	suite->teardown    = teardown_CSemInit;

	// -- ADD TEST CASES BELOW: --
	pnpcunit_add_test_case(suite, test_CSemInit_CreateValidSemaphore, "CreateValidSemaphore");
	pnpcunit_add_test_case(suite, test_CSemInit_CreateSemaphoreNullParameters, "CreateValidSemaphore");
	pnpcunit_add_test_case(suite, test_CSemInit_CreateSemaphoreLowCount, "CreateValidSemaphore");

	return suite;
}
