/**
 * Test suite to test the functionality provided by csignal function.
 *
 * @author Marlize Ramos
 */
#include "../include/csignal_test.h"
#include "../../include/constants.h"
#include "../../include/cthread.h"
#include "../../include/support.h"
#include "../../include/cdata.h"
#include <stdlib.h>


// =============================================================================================
//                                       GLOBAL VARIABLES
// =============================================================================================

pnpcunit_Bool has_passed;
csem_t* semaphore1;
csem_t* semaphore2;


// =============================================================================================
//                                       SUPPORT FUNCTIONS
// =============================================================================================

/**
 * Function for thread 1.
 */
void* test_CWait_Function1()
{
	return NULL;
}

/**
 * Function for thread 2.
 */
void* test_CWait_Function2()
{
	cwait(semaphore2);
	csignal(semaphore2);

	if (!pnpcunit_assert_equal_int(0, semaphore2->count))
		has_passed = pnpcunit_FALSE;

	if (!pnpcunit_assert_not_equal_int(CTHREAD_SUCCESS, FirstFila2(semaphore2->fila)))
		has_passed = pnpcunit_FALSE;

	return NULL;
}

/**
 * Function for thread 3.
 */
void* test_CWait_Function3()
{
	cyield();

	if (!pnpcunit_assert_equal_int(-2, semaphore2->count))
		has_passed = pnpcunit_FALSE;

	FirstFila2(semaphore2->fila);
	if (!pnpcunit_assert_equal_int(CTHREAD_SUCCESS, NextFila2(semaphore2->fila)))
		has_passed = pnpcunit_FALSE;

	csignal(semaphore2);

	if (!pnpcunit_assert_equal_int(-1, semaphore2->count))
		has_passed = pnpcunit_FALSE;

	if (!pnpcunit_assert_equal_int(CTHREAD_SUCCESS, FirstFila2(semaphore2->fila)))
		has_passed = pnpcunit_FALSE;

	return NULL;
}

// =============================================================================================
//                                       CONTEXT FUNCTIONS
// =============================================================================================

/**
 * Set up test suite context (e.g. global variables). Run only once before all test cases.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void set_up_CSignal()
{

}

/**
 * Set up test case context before each one. Run before each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void before_each_CSignal()
{
	semaphore1 = (csem_t*) malloc(sizeof(csem_t));
	csem_init(semaphore1, 1);
	csem_init(semaphore2, 1);

	has_passed = pnpcunit_TRUE;
}

/**
 * Teardown test case context after each one. Run after each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void after_each_CSignal()
{
	free(semaphore1);
	free(semaphore2);
}

/**
 * Teardown test suite context (e.g. free allocated memory). Run only once after all test cases.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void teardown_CSignal()
{
    
}


// =============================================================================================
//                                          TEST CASES
// =============================================================================================

pnpcunit_Bool test_CSignal_SingleCall()
{
	ccreate(&test_CWait_Function1, NULL, HIGH);

	cwait(semaphore1);
	cwait(semaphore1);

	if (!pnpcunit_assert_equal_int(-1, semaphore1->count))
		return pnpcunit_FALSE;

	if (!pnpcunit_assert_equal_int(CTHREAD_SUCCESS, FirstFila2(semaphore1->fila)))
		return pnpcunit_FALSE;

	csignal(semaphore1);

	if (!pnpcunit_assert_equal_int(0, semaphore1->count))
		return pnpcunit_FALSE;

	if (!pnpcunit_assert_not_equal_int(CTHREAD_SUCCESS, FirstFila2(semaphore1->fila)))
		return pnpcunit_FALSE;

	csignal(semaphore1);

	if (!pnpcunit_assert_equal_int(1, semaphore1->count))
		return pnpcunit_FALSE;

	if (!pnpcunit_assert_not_equal_int(CTHREAD_SUCCESS, FirstFila2(semaphore1->fila)))
		return pnpcunit_FALSE;

	return pnpcunit_assert_true(pnpcunit_TRUE);
}

pnpcunit_Bool test_CSignal_Priorities()
{
	ccreate(&test_CWait_Function2, NULL, HIGH);
	ccreate(&test_CWait_Function3, NULL, MEDIUM);
	ccreate(&test_CWait_Function1, NULL, LOW);

	cwait(semaphore2);
	cwait(semaphore2);

	csignal(semaphore2);

	if (!pnpcunit_assert_equal_int(1, semaphore2->count))
		return pnpcunit_FALSE;

	if (!pnpcunit_assert_not_equal_int(CTHREAD_SUCCESS, FirstFila2(semaphore2->fila)))
		return pnpcunit_FALSE;

	return has_passed;
}

pnpcunit_Bool test_CSignal_NullParameters()
{
	if (csignal(NULL) == CTHREAD_FAILURE)
		return pnpcunit_TRUE;

	return pnpcunit_FALSE;
}


// =============================================================================================
//                                         CONFIGURATION
// =============================================================================================

pnpcunit_TestSuite* configure_suite_CSignal()
{
	pnpcunit_TestSuite *suite = pnpcunit_create_test_suite("CThread.CSignal");

	suite->set_up      = set_up_CSignal;
	suite->before_each = before_each_CSignal;
	suite->after_each  = after_each_CSignal;
	suite->teardown    = teardown_CSignal;

	// -- ADD TEST CASES BELOW: --
	pnpcunit_add_test_case(suite, test_CSignal_SingleCall, "SingleCall");
	pnpcunit_add_test_case(suite, test_CSignal_Priorities, "Priorities");
	pnpcunit_add_test_case(suite, test_CSignal_NullParameters, "NullParameters");

	return suite;
}
