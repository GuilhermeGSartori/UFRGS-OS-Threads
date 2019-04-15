/**
 * Test suite to test the functionality provided by cwait function.
 *
 * @author Marlize Ramos
 */
#include "../include/cwait_test.h"


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

}

/**
 * Set up test case context before each one. Run before each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void before_each_CWait()
{

}

/**
 * Teardown test case context after each one. Run after each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void after_each_CWait()
{

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

pnpcunit_Bool test_CWait_Sample1()
{
	return pnpcunit_assert_true(pnpcunit_TRUE);
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
	pnpcunit_add_test_case(suite, test_CWait_Sample1, "Sample");

	return suite;
}
