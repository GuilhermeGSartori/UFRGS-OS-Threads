/**
 * Definition of entry point for Plug N' Play CUnit Framework. This header file includes every component the user might need,
 * which means that in an application to be tested, the programmers will only need to include this header file.
 *
 * @author Renan Kummer
 */
#ifndef PNPCUNIT_INCLUDE_PNPCUNIT_H
#define PNPCUNIT_INCLUDE_PNPCUNIT_H

#include "pnpcunit_TestRunner.h"
#include "pnpcunit_TestSuite.h"
#include "pnpcunit_Commands.h"
#include "pnpcunit_Assert.h"
#include "pnpcunit_Bool.h"

/**
 * Display Plug N' Play CUnit Framework message in Command Line.
 */
void pnpcunit_display_framework_message();

/**
 * Entry point for Plug N' Play CUnit Framework. This macro must be added as the first "statement" of your main function.
 * 
 * DISCLAIMER: The signature of your main function must follow the standard of C language - int main(int argc, char** argv).
 * 
 * @param set_up_test_runner_function Configuration function to the test runner.
 */
#define TOGGLE_PNPCUNIT(set_up_test_runner_function) \
	pnpcunit_Commands command = pnpcunit_read_command(argc, argv);\
	\
	if (command == pnpcunit_COMMAND_HELP)\
		pnpcunit_get_help();\
	\
	else if (command == pnpcunit_COMMAND_RUN_ALL)\
	{\
		pnpcunit_display_framework_message();\
		\
		pnpcunit_TestRunner *runner = pnpcunit_create_test_runner();\
		set_up_test_runner_function(runner);\
		pnpcunit_run_all_test_suites(runner);\
		\
		pnpcunit_ResultView view = pnpcunit_read_result_view(argc, argv);\
		\
		if (view == pnpcunit_RESULTS_JUNIT)\
			pnpcunit_display_results(pnpcunit_RESULTS_JUNIT, runner);\
		else\
			pnpcunit_display_results(pnpcunit_RESULTS_CLI, runner);\
	}	


#endif // PNPCUNIT_INCLUDE_PNPCUNIT_H
