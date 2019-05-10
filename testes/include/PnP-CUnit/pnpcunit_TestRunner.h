/**
 * Definition of TestRunner type.
 *
 * @author Renan Kummer
 */
#ifndef PNPCUNIT_INCLUDE_TESTRUNNER_H
#define PNPCUNIT_INCLUDE_TESTRUNNER_H

#include "pnpcunit_TestSuite.h"

typedef struct pnpcunit_TestRunner
{
	pnpcunit_TestSuite* suites_to_run;
	int suites_to_run_size;
	int suites_to_run_capacity;

	int failures;
	pnpcunit_Bool has_passed;
} pnpcunit_TestRunner;

typedef enum pnpcunit_ResultView
{
	pnpcunit_RESULTS_CLI,
	pnpcunit_RESULTS_JUNIT
} pnpcunit_ResultView;

/**
 * Return an initialized instance of TestRunner. It's recommended to use this function to
 * create new instances of TestRunner instead of using manual declarations.
 *
 * @return A reference to a new initialized instance of TestRunner.
 */
pnpcunit_TestRunner* pnpcunit_create_test_runner();

/**
 * Add test suite to a given runner. Test suite won't be added if any of the parameters is NULL.
 *
 * @param runner             A reference to a test runner.
 * @param new_suite_function A reference to a function that returns the test suite to be run.
 */
void pnpcunit_add_test_suite(pnpcunit_TestRunner* runner, pnpcunit_TestSuite* (*new_suite_function)());

/**
 * Run all the configured test suites.
 *
 * @param runner A reference to a test runner.
 */
void pnpcunit_run_all_test_suites(pnpcunit_TestRunner* runner);

/**
 * Display the results of runner and exit the application with either EXIT_SUCCESS or EXIT_FAILURE.
 *
 * @param result_type How to display the results.
 * @param runner      A reference to a test runner to gather the results from.
 */
void pnpcunit_display_results(pnpcunit_ResultView result_type, pnpcunit_TestRunner *runner);


#endif // PNPCUNIT_INCLUDE_TESTRUNNER_H
