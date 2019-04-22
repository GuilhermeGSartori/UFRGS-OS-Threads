/**
 * Definition of TestCase type.
 *
 * @author Renan Kummer
 */
#ifndef PNPCUNIT_INCLUDE_TESTCASE_H
#define PNPCUNIT_INCLUDE_TESTCASE_H

#include "pnpcunit_Bool.h"

typedef struct pnpcunit_TestCase
{
	char* name;
	pnpcunit_Bool (*function)();
	pnpcunit_Bool has_passed;
} pnpcunit_TestCase;

#endif // PNPCUNIT_INCLUDE_TEST_CASE_H
