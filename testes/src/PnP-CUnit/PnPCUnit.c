/**
 * Implementation of functions to support the entry point of Plug N' Play CUnit Framework.
 *
 * @author Renan Kummer
 */
#include "../../include/PnP-CUnit/PnPCUnit.h"

#include <stdio.h>

#define PNPCUNIT_VERSION "v1"  // Version of the framework.

void pnpcunit_display_framework_message()
{
	char* intro = "Plug N' Play CUnit Framework ("
				  PNPCUNIT_VERSION
				  ")";

	puts(intro);
	puts("Running test cases...\n");
}
