/**
 * Test suite to test the functionality provided by csetprio function.
 *
 * @author Renan Kummer
 */
#include "../include/csetprio_test.h"


// =============================================================================================
//                                       CONTEXT FUNCTIONS
// =============================================================================================

/**
 * Set up test suite context (e.g. global variables). Run only once before all test cases.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void set_up_CSetprio()
{

}

/**
 * Set up test case context before each one. Run before each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void before_each_CSetprio()
{

}

/**
 * Teardown test case context after each one. Run after each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void after_each_CSetprio()
{

}

/**
 * Teardown test suite context (e.g. free allocated memory). Run only once after all test cases.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void teardown_CSetprio()
{
    
}


// =============================================================================================
//                                          TEST CASES
// =============================================================================================

pnpcunit_Bool test_CSetprio_Sample1()
{
	return pnpcunit_assert_true(pnpcunit_TRUE);
}


// =============================================================================================
//                                         CONFIGURATION
// =============================================================================================

pnpcunit_TestSuite* configure_suite_CSetprio()
{
	pnpcunit_TestSuite *suite = pnpcunit_create_test_suite("CThread.CSetprio");

	suite->set_up      = set_up_CSetprio;
	suite->before_each = before_each_CSetprio;
	suite->after_each  = after_each_CSetprio;
	suite->teardown    = teardown_CSetprio;

	// -- ADD TEST CASES BELOW: --
	pnpcunit_add_test_case(suite, test_CSetprio_Sample1, "Sample");

	return suite;
}
