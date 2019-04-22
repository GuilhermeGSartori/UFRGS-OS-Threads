/**
 * Implementation of functions to handle TestRunner type.
 *
 * @author Renan Kummer
 */
#include "../../include/PnP-CUnit/pnpcunit_TestRunner.h"

#include <stdlib.h>
#include <stdio.h>

// ======================================================================================
//                            SUPPORT FUNCTIONS - DECLARATION
// ======================================================================================

/**
 * Check test runner for available capacity.
 *
 * @param runner A reference to a test runner to check.
 * @return pnpcunit_TRUE if there is available capacity, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool has_available_runner_capacity(pnpcunit_TestRunner *runner);

/**
 * Run a single test suite.
 *
 * @param suite A reference to a test suite to be run.
 * @return pnpcunit_TRUE if all test cases have passed, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool run_single_test_suite(pnpcunit_TestSuite *suite);

/**
 * Reallocate current test suites in memory and increase available capacity.
 *
 * @param runner A reference to a test runner to increase capacity.
 */
void increase_runner_capacity(pnpcunit_TestRunner *runner);

/**
 * Add test suite to a test runner, increasing its internal size. As a support function, 
 * it doesn't ensure capacity availability (programmer must ensure this).
 *
 * @param runner A reference to a test runner.
 * @param suite  A reference to a test suite to be added to runner.
 */
void add_test_suite_to_runner(pnpcunit_TestRunner *runner, pnpcunit_TestSuite *suite);

/**
 * Display results in Command Line.
 *
 * @param runner A reference to a test runner to gather the results from.
 */
void display_results_in_command_line(pnpcunit_TestRunner *runner);


// ======================================================================================
//                                     MAIN FUNCTIONS
// ======================================================================================

pnpcunit_TestRunner* pnpcunit_create_test_runner()
{
	pnpcunit_TestRunner* runner = (pnpcunit_TestRunner*) malloc(sizeof(pnpcunit_TestRunner));

	runner->suites_to_run = NULL;
	runner->suites_to_run_size     = 0;
	runner->suites_to_run_capacity = 0;

	runner->has_passed = pnpcunit_TRUE;

	return runner;
}

void pnpcunit_add_test_suite(pnpcunit_TestRunner* runner, pnpcunit_TestSuite* (*new_suite_function)())
{
	if (runner != NULL && new_suite_function != NULL)
	{
		pnpcunit_TestSuite* suite_to_add = new_suite_function();

		if (suite_to_add != NULL && has_available_runner_capacity(runner))
		{
			add_test_suite_to_runner(runner, suite_to_add);
		}
		else if (suite_to_add != NULL)
		{
			increase_runner_capacity(runner);
			add_test_suite_to_runner(runner, suite_to_add);
		}
	}
}

void pnpcunit_run_all_test_suites(pnpcunit_TestRunner* runner)
{
	if (runner != NULL && runner->suites_to_run_size > 0)
	{
		for (int i = 0; i < runner->suites_to_run_size; i++)
		{	
			pnpcunit_Bool result = run_single_test_suite(&(runner->suites_to_run[i]));

			if (result == pnpcunit_FALSE)
				runner->has_passed = pnpcunit_FALSE;
		}
	}
}

void pnpcunit_display_results(pnpcunit_ResultView result_type, pnpcunit_TestRunner *runner)
{
	if (runner == NULL)
		return;

	if (result_type == pnpcunit_RESULTS_CLI)
		display_results_in_command_line(runner);
}


// ==================================================================================================
//                                 SUPPORT FUNCTIONS - IMPLEMENTATION
// ==================================================================================================

pnpcunit_Bool has_available_runner_capacity(pnpcunit_TestRunner *runner)
{
	return (runner->suites_to_run_size < runner->suites_to_run_capacity);
}

void increase_runner_capacity(pnpcunit_TestRunner *runner)
{
	size_t current_capacity = sizeof(pnpcunit_TestSuite) * runner->suites_to_run_capacity;
	size_t extra_capacity = sizeof(pnpcunit_TestSuite) * 5;

	if (runner->suites_to_run_capacity > 0)
	{
		runner->suites_to_run = realloc(runner->suites_to_run, current_capacity + extra_capacity);
	}
	else
	{
		runner->suites_to_run = malloc(extra_capacity);
	}

	runner->suites_to_run_capacity += 5;
}

pnpcunit_Bool run_single_test_suite(pnpcunit_TestSuite *suite)
{
	if (suite->set_up != NULL)
		suite->set_up();

	for (int j = 0; j < suite->test_cases_size; j++)
	{
		if (suite->before_each != NULL)
			suite->before_each();

		pnpcunit_Bool result = suite->test_cases[j].function();

		if (result == pnpcunit_FALSE)
		{
			suite->test_cases[j].has_passed = pnpcunit_FALSE;
			suite->has_passed = pnpcunit_FALSE;
		}

		if (suite->after_each != NULL)
			suite->after_each();
	}

	if (suite->teardown != NULL)
		suite->teardown();

	return suite->has_passed;
}

void add_test_suite_to_runner(pnpcunit_TestRunner *runner, pnpcunit_TestSuite *suite)
{
	runner->suites_to_run[runner->suites_to_run_size] = *suite;
	runner->suites_to_run_size += 1;
}

void display_results_in_command_line(pnpcunit_TestRunner *runner)
{
	for (int i = 0; i < runner->suites_to_run_size; i++)
	{
		pnpcunit_TestSuite suite = runner->suites_to_run[i];

		if (suite.has_passed)
			printf("[ OK ] %s\n", suite.name);
		else
			printf("[FAIL] %s\n", suite.name);

		for (int j = 0; j < suite.test_cases_size; j++)
		{
			pnpcunit_TestCase test_case = suite.test_cases[j];

			if (test_case.has_passed)
				printf(" - [ OK ] %s\n", test_case.name);
			else
				printf(" - [FAIL] %s\n", test_case.name);

		}

		printf("\n");
	}

	if (runner->has_passed == pnpcunit_TRUE)
	{
		puts("\nAll tests have passed!\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		puts("\nSome tests have failed!\n");
		exit(EXIT_FAILURE);
	}
}
