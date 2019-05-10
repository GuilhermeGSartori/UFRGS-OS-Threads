/**
 * Entry point for test application.
 * 
 * @author Renan Kummer
 */

#include "../include/PnP-CUnit/PnPCUnit.h"
#include "../config/UnitTestConfig.h"
#include "../../include/constants.h"
#include "../../include/cthread.h"
#include "../../include/support.h"
#include "../../include/cdata.h"
#include "../include/cwait_test.h"




// =============================================================================================
//                                       SUPPORT FUNCTIONS
// =============================================================================================

/**
 * Function for thread 1.
 */
void* test_CWait_Function1()
{
	if (!pnpcunit_assert_equal_int(-1, semaphore1->count))
		has_passed = pnpcunit_FALSE;

	if (!pnpcunit_assert_equal_int(CTHREAD_SUCCESS, FirstFila2(semaphore1->fila)))
		has_passed = pnpcunit_FALSE;

	cwait(semaphore1);

	return NULL;
}

/**
 * Function for thread 2.
 */
void* test_CWait_Function2()
{
	if (!pnpcunit_assert_equal_int(-2, semaphore1->count))
		has_passed = pnpcunit_FALSE;

	FirstFila2(semaphore1->fila);
	if (!pnpcunit_assert_equal_int(CTHREAD_SUCCESS, NextFila2(semaphore1->fila)))
		has_passed = pnpcunit_FALSE;

	return NULL;
}

/**
 * Function for thread 3.
 */
void* test_CWait_Function3()
{
	return NULL;
}

int main(int argc, char** argv)
{
    TOGGLE_PNPCUNIT(configure_pnpcunit)
}