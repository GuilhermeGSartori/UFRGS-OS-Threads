/**
 * Test suite to test the functionality provided by cidentify function.
 *
 * @author Renan Kummer
 */
#include "../include/cidentify_test.h"


// =============================================================================================
//                                       CONTEXT FUNCTIONS
// =============================================================================================

/**
 * Set up test suite context (e.g. global variables). Run only once before all test cases.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void set_up_CIdentify()
{

}

/**
 * Set up test case context before each one. Run before each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void before_each_CIdentify()
{

}

/**
 * Teardown test case context after each one. Run after each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void after_each_CIdentify()
{

}

/**
 * Teardown test suite context (e.g. free allocated memory). Run only once after all test cases.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void teardown_CIdentify()
{
    
}


// =============================================================================================
//                                          TEST CASES
// =============================================================================================

pnpcunit_Bool test_CIdentify_Sample1()
{
	return pnpcunit_assert_true(pnpcunit_FALSE);
}


// =============================================================================================
//                                         CONFIGURATION
// =============================================================================================

pnpcunit_TestSuite* configure_suite_CIdentify()
{
	pnpcunit_TestSuite *suite = pnpcunit_create_test_suite("CThread.CIdentify");

	suite->set_up      = set_up_CIdentify;
	suite->before_each = before_each_CIdentify;
	suite->after_each  = after_each_CIdentify;
	suite->teardown    = teardown_CIdentify;

	// -- ADD TEST CASES BELOW: --
	pnpcunit_add_test_case(suite, test_CIdentify_Sample1, "Sample");

	return suite;
}
