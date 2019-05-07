/**
 * Test suite to test the functionality provided by cidentify function.
 *
 * @author Renan Kummer
 */
#include "../include/cidentify_test.h"
#include "../../include/result_code.h"
#include "../../include/cthread.h"
#include <stdlib.h>
#include <stdio.h>

// =============================================================================================
//                                           CONSTANTS
// =============================================================================================
#define TEST_CIDENTIFY_VALID_SIZE 98
#define TEST_CIDENTIFY_INVALID_SIZE 97


// =============================================================================================
//                                       GLOBAL VARIABLES
// =============================================================================================
char* cidentify_valid_size;
char* cidentify_invalid_size;
char* cidentify_expected_result;


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
	cidentify_expected_result = "Guilherme Girotto Sartori 00274713\nMarlize Ramos Batista 00274703\nRenan Kummer de Jesus 00208946\n";

	cidentify_valid_size   = (char*) malloc(sizeof(char) * TEST_CIDENTIFY_VALID_SIZE);
	cidentify_invalid_size = (char*) malloc(sizeof(char) * TEST_CIDENTIFY_INVALID_SIZE);
}

/**
 * Set up test case context before each one. Run before each test case.
 *
 * OPTIONAL: Implement if it fits your case.
 */
void before_each_CIdentify()
{
	cidentify_valid_size[0]   = '\0';
	cidentify_invalid_size[0] = '\0';
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
    cidentify_expected_result = NULL;

	free(cidentify_valid_size);
	free(cidentify_invalid_size);
}


// =============================================================================================
//                                          TEST CASES
// =============================================================================================

pnpcunit_Bool test_CIdentify_ValidCall()
{
	int result_code = cidentify(cidentify_valid_size, TEST_CIDENTIFY_VALID_SIZE);

	pnpcunit_Bool has_success_code = pnpcunit_assert_equal_int(result_code, CTHREAD_SUCCESS);
	pnpcunit_Bool has_identifications = pnpcunit_assert_equal_string(cidentify_valid_size, cidentify_expected_result);

	return has_success_code && has_identifications;
}

pnpcunit_Bool test_CIdentify_SmallSize()
{
	int result_code = cidentify(cidentify_invalid_size, TEST_CIDENTIFY_INVALID_SIZE);

	pnpcunit_Bool has_failure_code = pnpcunit_assert_equal_int(result_code, CTHREAD_FAILURE);

	return has_failure_code;
}

pnpcunit_Bool test_CIdentify_NullPointer()
{
	int result_code = cidentify(NULL, TEST_CIDENTIFY_VALID_SIZE);

	pnpcunit_Bool has_failure_code = pnpcunit_assert_equal_int(result_code, CTHREAD_FAILURE);

	return has_failure_code;
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
	pnpcunit_add_test_case(suite, test_CIdentify_ValidCall, "ValidCall");
	pnpcunit_add_test_case(suite, test_CIdentify_SmallSize, "SmallSize");
	pnpcunit_add_test_case(suite, test_CIdentify_NullPointer, "NullPointer");

	return suite;
}
