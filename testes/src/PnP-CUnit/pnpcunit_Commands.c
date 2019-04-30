/**
 * Implementation of functions related to CLI commands.
 *
 * @author Renan Kummer
 */
#include "../../include/PnP-CUnit/pnpcunit_Commands.h"
#include "../../include/PnP-CUnit/pnpcunit_Bool.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// ======================================================================================
//                            SUPPORT FUNCTIONS - DECLARATION
// ======================================================================================

/**
  * List available commands for Plug N' Play CUnit Framework.
  *
  * @return List of available commands for Plug N' Play CUnit Framework.
  */
char* list_commands();


// ======================================================================================
//                                     MAIN FUNCTIONS
// ======================================================================================

pnpcunit_Commands pnpcunit_read_command(int argc, char** argv)
{
	pnpcunit_Commands command = pnpcunit_COMMAND_NONE;

	if (argc >= 2 && argv != NULL)
	{
		if (strcmp(argv[1], PNPCUNIT_GET_HELP) == 0)
			command = pnpcunit_COMMAND_HELP;

		else if (strcmp(argv[1], PNPCUNIT_RUN_TESTS) == 0)
			command = pnpcunit_COMMAND_RUN_ALL;
	}

	return command;
}

void pnpcunit_get_help()
{
	puts(list_commands());
	exit(EXIT_SUCCESS);
}

pnpcunit_ResultView pnpcunit_read_result_view(int argc, char** argv)
{
	pnpcunit_ResultView view = pnpcunit_RESULTS_CLI;

	if (argc >= 3 && argv != NULL)
	{
		if (strcmp(argv[2], PNPCUNIT_VIEW_JUNIT) == 0)
			view = pnpcunit_RESULTS_JUNIT;
	}

	return view;
}


// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

char* list_commands()
{
	char* help = "Plug N' Play CUnit Framework\n"
		         " --pnpcunit-test  : Run all test suites\n"
	             " --pnpcunit-help  : Display this list\n";

	return help;
}
