/**
 * Definition of TestSuite type.
 * 
 * @author Renan Kummer
 */
#ifndef PNPCUNIT_INCLUDE_TESTSUITE_H
#define PNPCUNIT_INCLUDE_TESTSUITE_H

#include "pnpcunit_TestCase.h"

typedef struct pnpcunit_TestSuite
{
	char* name;

    void (*set_up)();
    void (*teardown)();
    void (*before_each)();
    void (*after_each)();
    
	pnpcunit_TestCase *test_cases;
    int test_cases_size;
    int test_cases_capacity;

	pnpcunit_Bool has_passed;
} pnpcunit_TestSuite;


/**
 * Return an initialized instance of TestSuite. It's recommended to use this function to
 * create new instances of TestSuite instead of using manual declarations.
 * 
 * @param name The name of this test suite.
 * @return A reference to a new initialized instance of TestSuite.
 */
pnpcunit_TestSuite* pnpcunit_create_test_suite(char* name);

/**
 * Define Set Up function of a given test suite. A Set Up function runs once, prior to 
 * all the test cases of its test suite. Set Up function won't be defined if any of the
 * parameters is NULL.
 * 
 * @param suite   A reference to a test suite.
 * @param set_up  A reference to a Set Up function.
 */
void pnpcunit_define_set_up(pnpcunit_TestSuite *suite, void (*set_up)());

/**
 * Define Teardown function of a given test suite. A Teardown function runs once, after 
 * all the test cases of its test suite. Teardown function won't be defined if any of the 
 * parameters is NULL.
 * 
 * @param suite    A reference to a test suite.
 * @param teardown A reference to a Teardown function.
 */
void pnpcunit_define_teardown(pnpcunit_TestSuite *suite, void (*teardown)());

/**
 * Define Before Each function of a given test suite. As the name implies, this function 
 * runs before each test case in the test suite. Before Each function won't be defined if 
 * any of the parameters is NULL.
 * 
 * @param suite       A reference to a test suite.
 * @param before_each A reference to a Before Each function.
 */
void pnpcunit_define_before_each(pnpcunit_TestSuite *suite, void (*before_each)());

/**
 * Define After Each function of a given test suite. As the name implies, this function 
 * runs after each test case in the test suite. After Each function won't be defined if 
 * any of the parameters is NULL.
 * 
 * @param suite      A reference to a test suite.
 * @param after_each A reference to a After Each function.
 */
void pnpcunit_define_after_each(pnpcunit_TestSuite *suite, void (*after_each)());

/**
 * Add a test case to the test suite. It's recommended to use this function instead 
 * of adding a test case manually due to it also handling memory management.
 * 
 * @param suite               A reference to a test suite.
 * @param test_case_function  A reference to a test case (function) to add to suite.
 * @param test_case_name      The name of the test case.
 */
void pnpcunit_add_test_case(pnpcunit_TestSuite *suite, pnpcunit_Bool (*test_case_function)(), char* test_case_name);

#endif // PNPCUNIT_INCLUDE_TESTSUITE_H
