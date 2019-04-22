/**
 * Test suite to test the functionality provided by cjoin function.
 *
 * @author Guilherme Sartori
 */
#include "../include/cjoin_test.h"


// =============================================================================================
//                                       CONTEXT FUNCTIONS
// =============================================================================================

/**
 * Set up test suite context (e.g. global variables). Run only once before all test cases.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void set_up_CJoin()
{

}

/**
 * Set up test case context before each one. Run before each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void before_each_CJoin()
{

}

/**
 * Teardown test case context after each one. Run after each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void after_each_CJoin()
{

}

/**
 * Teardown test suite context (e.g. free allocated memory). Run only once after all test cases.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void teardown_CJoin()
{
    
}


// =============================================================================================
//                                          TEST CASES
// =============================================================================================

pnpcunit_Bool test_CJoin_Sample1()
{
	return pnpcunit_assert_true(pnpcunit_TRUE);
}


// =============================================================================================
//                                         CONFIGURATION
// =============================================================================================

pnpcunit_TestSuite* configure_suite_CJoin()
{
	pnpcunit_TestSuite *suite = pnpcunit_create_test_suite("CThread.CJoin");

	suite->set_up      = set_up_CJoin;
	suite->before_each = before_each_CJoin;
	suite->after_each  = after_each_CJoin;
	suite->teardown    = teardown_CJoin;

	// -- ADD TEST CASES BELOW: --
	pnpcunit_add_test_case(suite, test_CJoin_Sample1, "Sample");

	return suite;
}
