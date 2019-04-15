/**
 * Definition of structures and functions related to CLI commands.
 *
 * @author Renan Kummer
 */
#ifndef PNPCUNIT_INCLUDE_COMMANDS_H
#define PNPCUNIT_INCLUDE_COMMANDS_H

#define PNPCUNIT_GET_HELP  "--pnpcunit-help"
#define PNPCUNIT_RUN_TESTS "--pnpcunit-test"

typedef enum pnpcunit_Commands
{
	pnpcunit_COMMAND_NONE,          // No command or not applicable to Plug N' Play CUnit Framework.
	pnpcunit_COMMAND_HELP,          // Display available commands for Plug N' Play CUnit Framework.
	pnpcunit_COMMAND_RUN_ALL        // Run all test suites. 
} pnpcunit_Commands;

typedef enum pnpcunit_Verbosity
{
	pnpcunit_LOW_VERBOSITY,     // Display results of failed test cases only.
	pnpcunit_NORMAL_VERBOSITY,  // Display results of test suites and failed test cases.
	pnpcunit_HIGH_VERBOSITY     // Display results of all the test cases per test suite.
} pnpcunit_Verbosity;

/**
 * Entry point for Plug N' Play CUnit Framework. Read the commands passed by Command Line
 * and check if tests should be run.
 *
 * @param argc Number of arguments passed by Command Line.
 * @param argv Array of arguments passed by Command Line.
 * @return Command to be run.
 */
pnpcunit_Commands pnpcunit_read_command(int argc, char** argv);

/**
 * Display in Command Line all the available commands for Plug N' Play CUnit Framework.
 */
void pnpcunit_get_help();

#endif // PNPCUNIT_INCLUDE_COMMANDS_H
