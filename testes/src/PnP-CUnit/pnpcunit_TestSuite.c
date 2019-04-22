/**
 * Implementation of functions to handle TestSuite type.
 * 
 * @author Renan Kummer
 */
#include "../../include/PnP-CUnit/pnpcunit_TestSuite.h"
#include "../../include/PnP-CUnit/pnpcunit_Bool.h"

#include <stdlib.h>

// ======================================================================================
//                            SUPPORT FUNCTIONS - DECLARATION
// ======================================================================================

/**
 * Check test suite for available capacity.
 *
 * @param suite A reference to a test suite to check.
 * @return pnpcunit_TRUE if there is available capacity, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool has_available_suite_capacity(pnpcunit_TestSuite *suite);

/**
 * Reallocate current test cases in memory and increase available capacity.
 *
 * @param suite A reference to a test suite to increase capacity.
 */
void increase_suite_capacity(pnpcunit_TestSuite *suite);

/**
 * Add a test case to a test suite, increasing its internal size. As a support function,
 * it doesn't ensure capacity availability (programmer must ensure this).
 *
 * @param suite     A reference to a test suite.
 * @param function  A reference to a test case function to be added to suite.
 * @param name      The name of the test case.
 */
void add_test_case_to_suite(pnpcunit_TestSuite *suite, pnpcunit_Bool (*function)(), char* name);


// ======================================================================================
//                                     MAIN FUNCTIONS
// ======================================================================================

pnpcunit_TestSuite* pnpcunit_create_test_suite(char* name)
{
    pnpcunit_TestSuite *new_suite = (pnpcunit_TestSuite*) malloc(sizeof(pnpcunit_TestSuite));
    
	if (name != NULL)
		new_suite->name = name;
	else
		new_suite->name = "Test Suite (unnamed)";

	new_suite->set_up      = NULL;
	new_suite->teardown    = NULL;
	new_suite->before_each = NULL;
	new_suite->after_each  = NULL;
	
	new_suite->test_cases  = NULL;
	new_suite->test_cases_size     = 0;
	new_suite->test_cases_capacity = 0;

	new_suite->has_passed = pnpcunit_TRUE;
	
    return new_suite;
}

void pnpcunit_define_set_up(pnpcunit_TestSuite *suite, void (*set_up)())
{
    if (suite != NULL && set_up != NULL)
        suite->set_up = set_up;
}

void pnpcunit_define_teardown(pnpcunit_TestSuite *suite, void (*teardown)())
{
    if (suite != NULL && teardown != NULL)
        suite->teardown = teardown;
}

void pnpcunit_define_before_each(pnpcunit_TestSuite *suite, void (*before_each)())
{
    if (suite != NULL && before_each != NULL)
        suite->before_each = before_each;
}

void pnpcunit_define_after_each(pnpcunit_TestSuite *suite, void (*after_each)())
{
    if (suite != NULL && after_each != NULL)
		suite->after_each = after_each;
}

void pnpcunit_add_test_case(pnpcunit_TestSuite *suite, pnpcunit_Bool (*test_case_function)(), char* test_case_name)
{
    if (suite != NULL && test_case_function != NULL && test_case_name != NULL)
    {
        if (has_available_suite_capacity(suite))
            add_test_case_to_suite(suite, test_case_function, test_case_name);
        
		else
        {
			increase_suite_capacity(suite);
            add_test_case_to_suite(suite, test_case_function, test_case_name);
        }
    }
}


// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

pnpcunit_Bool has_available_suite_capacity(pnpcunit_TestSuite *suite)
{
    return (suite->test_cases_size < suite->test_cases_capacity);
}

void increase_suite_capacity(pnpcunit_TestSuite *suite)
{
    size_t current_capacity = sizeof(pnpcunit_TestCase) * suite->test_cases_capacity;
    size_t extra_capacity = sizeof(pnpcunit_TestCase) * 5;

    if (suite->test_cases_capacity > 0)
    {
        suite->test_cases = realloc(suite->test_cases, current_capacity + extra_capacity);
    } else
    {
        suite->test_cases = malloc(extra_capacity);
    }

    suite->test_cases_capacity += 5;
}

void add_test_case_to_suite(pnpcunit_TestSuite *suite, pnpcunit_Bool (*function)(), char* name)
{
    pnpcunit_TestCase new_test;
	new_test.name = name;
    new_test.function = function;
	new_test.has_passed = pnpcunit_TRUE;

    int new_test_index = suite->test_cases_size;
    suite->test_cases[new_test_index] = new_test;
    suite->test_cases_size += 1;
}
