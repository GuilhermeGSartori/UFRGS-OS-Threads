/**
 * Test suite to test the functionality provided by ccreate function.
 *
 * @author Guilherme Sartori
 */
#include "../include/ccreate_test.h"


// =============================================================================================
//                                       CONTEXT FUNCTIONS
// =============================================================================================

/**
 * Set up test suite context (e.g. global variables). Run only once before all test cases.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void set_up_CCreate()
{

}

/**
 * Set up test case context before each one. Run before each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void before_each_CCreate()
{

}

/**
 * Teardown test case context after each one. Run after each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void after_each_CCreate()
{

}

/**
 * Teardown test suite context (e.g. free allocated memory). Run only once after all test cases.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void teardown_CCreate()
{
    
}


// =============================================================================================
//                                          TEST CASES
// =============================================================================================

pnpcunit_Bool test_CCreate()
{
	return pnpcunit_TRUE;
}


// =============================================================================================
//                                         CONFIGURATION
// =============================================================================================

pnpcunit_TestSuite* configure_suite_CCreate()
{
	pnpcunit_TestSuite *suite = pnpcunit_create_test_suite("CThread.CCreate");

	suite->set_up      = set_up_CCreate;
	suite->before_each = before_each_CCreate;
	suite->after_each  = after_each_CCreate;
	suite->teardown    = teardown_CCreate;

	// -- ADD TEST CASES BELOW: --
	pnpcunit_add_test_case(suite, test_CCreate, "Test");

	return suite;
}
