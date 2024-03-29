/**
 * Test suite to test the functionality provided by cwait function.
 *
 * @author Marlize Ramos
 * @author Renan Kummer
 */
#include "../include/cwait_test.h"
#include "../../include/constants.h"
#include "../../include/cthread.h"
#include "../../include/support.h"
#include "../../include/cdata.h"
#include <stdlib.h>


// =============================================================================================
//                                       GLOBAL VARIABLES
// =============================================================================================




// =============================================================================================
//                                       CONTEXT FUNCTIONS
// =============================================================================================

/**
 * Set up test suite context (e.g. global variables). Run only once before all test cases.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void set_up_CWait()
{
	test_CWait_Function1();

	//ccreate(test_CWait_Function1, NULL, HIGH);
	//ccreate(test_CWait_Function2, NULL, MEDIUM);
	//ccreate(test_CWait_Function3, NULL, LOW);
}

/**
 * Set up test case context before each one. Run before each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void before_each_CWait()
{/*
	semaphore1 = (csem_t*) malloc(sizeof(csem_t));
	semaphore2 = (csem_t*) malloc(sizeof(csem_t));

	csem_init(semaphore1, 2);

	has_passed = pnpcunit_TRUE;*/
}

/**
 * Teardown test case context after each one. Run after each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void after_each_CWait()
{/*
	free(semaphore1);
	free(semaphore2);*/
}

/**
 * Teardown test suite context (e.g. free allocated memory). Run only once after all test cases.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void teardown_CWait()
{
    
}


// =============================================================================================
//                                          TEST CASES
// =============================================================================================

pnpcunit_Bool test_CWait_AvailableResource()
{
	int count1 = semaphore1->count;

	cwait(semaphore1);
	
	if (!pnpcunit_assert_equal_int(count1 - 1, semaphore1->count))
		return pnpcunit_FALSE;

	if (!pnpcunit_assert_not_equal_int(CTHREAD_SUCCESS, FirstFila2(semaphore1->fila)))
		return pnpcunit_FALSE;

	return pnpcunit_TRUE;	
}

pnpcunit_Bool test_CWait_BusyResource()
{
	cwait(semaphore1);
	cwait(semaphore1);
	cwait(semaphore1);

	if (!pnpcunit_assert_equal_int(-2, semaphore1->count))
		has_passed = pnpcunit_FALSE;

	FirstFila2(semaphore1->fila);
	if (!pnpcunit_assert_equal_int(CTHREAD_SUCCESS, NextFila2(semaphore1->fila)))
		has_passed = pnpcunit_FALSE;

	return has_passed;
}

pnpcunit_Bool test_CWait_NullParameters()
{
	if (cwait(NULL) == CTHREAD_FAILURE)
		return pnpcunit_TRUE;

	return pnpcunit_FALSE;
}


// =============================================================================================
//                                         CONFIGURATION
// =============================================================================================

pnpcunit_TestSuite* configure_suite_CWait()
{
	pnpcunit_TestSuite *suite = pnpcunit_create_test_suite("CThread.CWait");

	suite->set_up      = set_up_CWait;
	suite->before_each = before_each_CWait;
	suite->after_each  = after_each_CWait;
	suite->teardown    = teardown_CWait;

	// -- ADD TEST CASES BELOW: --
	//pnpcunit_add_test_case(suite, test_CWait_AvailableResource, "AvailableResource");
	//pnpcunit_add_test_case(suite, test_CWait_BusyResource, "BusyResource");
	pnpcunit_add_test_case(suite, test_CWait_NullParameters, "NullParameters");

	return suite;
}
