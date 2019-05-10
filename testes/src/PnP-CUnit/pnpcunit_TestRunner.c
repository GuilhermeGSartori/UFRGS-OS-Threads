/**
 * Implementation of functions to handle TestRunner type.
 *
 * @author Renan Kummer
 */
#include "../../include/PnP-CUnit/pnpcunit_TestRunner.h"
#include "../../include/cwait_test.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TESTSUITES_TAG_BASE_SIZE 34
#define TESTSUITE_TAG_BASE_SIZE  62
#define TESTCASE_TAG_BASE_SIZE   27

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

/**
 * Generate a XML file in JUnit format.
 * 
 * @param runner A reference to a test runner to gather the results from.
 */
void display_results_as_junix_xml(pnpcunit_TestRunner *runner);

/**
 * Obtain the number of tests associated to a given runner.
 * 
 * @param runner A reference to a test runner to gather the results from.
 */ 
int get_number_of_tests(pnpcunit_TestRunner *runner);

/**
 * Parse an integer number to a string.
 * 
 * @param value Integer to parse.
 */ 
char* pnpcunit_parse_int_to_string(int value);


// ======================================================================================
//                                     MAIN FUNCTIONS
// ======================================================================================

pnpcunit_TestRunner* pnpcunit_create_test_runner()
{
	pnpcunit_TestRunner* runner = (pnpcunit_TestRunner*) malloc(sizeof(pnpcunit_TestRunner));

	runner->suites_to_run = NULL;
	runner->suites_to_run_size     = 0;
	runner->suites_to_run_capacity = 0;

	runner->failures   = 0;
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
		int i;
		for (i = 0; i < runner->suites_to_run_size; i++)
		{	
			pnpcunit_Bool result = run_single_test_suite(&(runner->suites_to_run[i]));

			if (result == pnpcunit_FALSE)
			{
				runner->has_passed = pnpcunit_FALSE; 
				runner->failures += runner->suites_to_run[i].failures;
			}
		}
	}
}

void pnpcunit_display_results(pnpcunit_ResultView result_type, pnpcunit_TestRunner *runner)
{
	if (runner == NULL)
		return;

	if (result_type == pnpcunit_RESULTS_CLI)
		display_results_in_command_line(runner);

	else if (result_type == pnpcunit_RESULTS_JUNIT)
		display_results_as_junix_xml(runner);
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
	if (suite->name == "CThread.CWait")
	{
		ccreate(test_CWait_Function1, NULL, HIGH);
		ccreate(test_CWait_Function2, NULL, MEDIUM);
		ccreate(test_CWait_Function3, NULL, LOW);
	}

	if (suite->set_up != NULL)
		suite->set_up();

	int j;
	for (j = 0; j < suite->test_cases_size; j++)
	{
		if (suite->before_each != NULL)
			suite->before_each();

		pnpcunit_Bool result = suite->test_cases[j].function();

		if (result == pnpcunit_FALSE)
		{
			suite->test_cases[j].has_passed = pnpcunit_FALSE;
			suite->has_passed = pnpcunit_FALSE;
			
			suite->failures += 1;
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
	int i, j;
	for (i = 0; i < runner->suites_to_run_size; i++)
	{
		pnpcunit_TestSuite suite = runner->suites_to_run[i];
		
		printf("%s\n", suite.name);
		for (j = 0; j < suite.test_cases_size; j++)
		{
			pnpcunit_TestCase test_case = suite.test_cases[j];

			if (test_case.has_passed)
				printf("    PASS : %s\n", test_case.name);
			else
				printf("->  FAIL : %s\n", test_case.name);

		}

		printf("\n");
	}

	if (runner->has_passed == pnpcunit_TRUE)
	{
		puts("All tests have passed!");
		exit(EXIT_SUCCESS);
	}
	else
	{
		puts("Some tests have failed!");
		exit(EXIT_FAILURE);
	}
}

void display_results_as_junix_xml(pnpcunit_TestRunner *runner)
{
	FILE *test_results = fopen("pnpcunit_result.xml", "w");
	fprintf(test_results, "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n");
	
	char* number_of_tests    = pnpcunit_parse_int_to_string(get_number_of_tests(runner)); 
	char* number_of_failures = pnpcunit_parse_int_to_string(runner->failures);

	int testsuites_tag_size = TESTSUITES_TAG_BASE_SIZE + strlen(number_of_tests) + strlen(number_of_failures);
	char* testsuites_tag = (char*) malloc(sizeof(char) * testsuites_tag_size);

	testsuites_tag[0] = '\0';
	strcat(testsuites_tag, "<testsuites tests=\"");
	strcat(testsuites_tag, number_of_tests);
	strcat(testsuites_tag, "\" failures=\"");
	strcat(testsuites_tag, number_of_failures);
	strcat(testsuites_tag, "\">\n");

	fprintf(test_results, "%s", testsuites_tag);

	int i, j;
	for (i = 0; i < runner->suites_to_run_size; i++)
	{
		pnpcunit_TestSuite suite = runner->suites_to_run[i];

		number_of_tests    = pnpcunit_parse_int_to_string(suite.test_cases_size);
		number_of_failures = pnpcunit_parse_int_to_string(suite.failures);

		int testsuite_tag_size = TESTSUITE_TAG_BASE_SIZE + strlen(number_of_tests) + strlen(number_of_failures);
		char* testsuite_tag = (char*) malloc(sizeof(char) * testsuite_tag_size);

		testsuite_tag[0] = '\0';
		strcat(testsuite_tag, "    <testsuite name=\"");
		strcat(testsuite_tag, suite.name);
		strcat(testsuite_tag, "\" tests=\"");
		strcat(testsuite_tag, number_of_tests);
		strcat(testsuite_tag, "\" failures=\"");
		strcat(testsuite_tag, number_of_failures);
		strcat(testsuite_tag, "\">\n");

		fprintf(test_results, "%s", testsuite_tag);

		for (j = 0; j < suite.test_cases_size; j++)
		{
			pnpcunit_TestCase test_case = suite.test_cases[j];

			int testcase_tag_size = TESTCASE_TAG_BASE_SIZE + strlen(test_case.name);
			char* testcase_tag = (char*) malloc(sizeof(char) * testcase_tag_size);

			testcase_tag[0] = '\0';
			strcat(testcase_tag, "        <testcase name=\"");
			strcat(testcase_tag, test_case.name);
			strcat(testcase_tag, "\">");

			fprintf(test_results, "%s", testcase_tag);

			if (!test_case.has_passed)
			{
				fprintf(test_results, "\n            <failure>Test has failed!</failure>\n");
				fprintf(test_results, "        </testcase>\n");
			}

			else
			{
				fprintf(test_results, "</testcase>\n");
			}
			

		}

		fprintf(test_results, "    </testsuite>\n");
	}

	fprintf(test_results, "</testsuites>\n");
	fclose(test_results);
}

int get_number_of_tests(pnpcunit_TestRunner *runner)
{
	int number_of_tests = 0;
	int i;
	for (i = 0; i < runner->suites_to_run_size; ++i)
	{
		pnpcunit_TestSuite suite = runner->suites_to_run[i];
		number_of_tests += suite.test_cases_size;
	}

	return number_of_tests;
}

char* pnpcunit_parse_int_to_string(int value)
{
	if (value == 0)
		return "0";

	if (value < 0)
		value *= -1;

	int string_size = 0;
	int i;
	for (i = value; i > 0; i /= 10)
		string_size++;

	char* string = (char*) malloc(sizeof(char) * string_size + 2);
	for (i = 0; i < string_size; ++i)
	{
		string[i] = (value % 10) + '0';
		value /= 10;
	}

	return string;
}

