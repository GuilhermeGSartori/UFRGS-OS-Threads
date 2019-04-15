/**
 * Test suite to test scheduler and dispatcher.
 *
 * @author Guilherme Sartori
 * @author Marlize Ramos
 * @author Renan Kummer
 */
#include "../include/scheduler_test.h"


// =============================================================================================
//                                       CONTEXT FUNCTIONS
// =============================================================================================

/**
 * Set up test suite context (e.g. global variables). Run only once before all test cases.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void set_up_Scheduler()
{

}

/**
 * Set up test case context before each one. Run before each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void before_each_Scheduler()
{

}

/**
 * Teardown test case context after each one. Run after each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void after_each_Scheduler()
{

}

/**
 * Teardown test suite context (e.g. free allocated memory). Run only once after all test cases.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void teardown_Scheduler()
{
    
}


// =============================================================================================
//                                          TEST CASES
// =============================================================================================

pnpcunit_Bool test_Scheduler_Sample1()
{
	return pnpcunit_assert_true(pnpcunit_TRUE);
}


// =============================================================================================
//                                         CONFIGURATION
// =============================================================================================

pnpcunit_TestSuite* configure_suite_Scheduler()
{
	pnpcunit_TestSuite *suite = pnpcunit_create_test_suite("CThread.Scheduler");

	suite->set_up      = set_up_Scheduler;
	suite->before_each = before_each_Scheduler;
	suite->after_each  = after_each_Scheduler;
	suite->teardown    = teardown_Scheduler;

	// -- ADD TEST CASES BELOW: --
	pnpcunit_add_test_case(suite, test_Scheduler_Sample1, "Sample");

	return suite;
}
