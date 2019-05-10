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
#include <stdlib.h>
#include <stdio.h>




// =============================================================================================
//                                       SUPPORT FUNCTIONS
// =============================================================================================

/**
 * Function for thread 1.
 */
void* test_CWait_Function1()
{
	printf("Hello ");
    if (semaphore1 == NULL)
        printf("EIta!");
    
    //printf("%d\n", semaphore1->count);

	//if (!pnpcunit_assert_equal_int(CTHREAD_SUCCESS, FirstFila2(semaphore1->fila)))
	//	has_passed = pnpcunit_FALSE;

	//cwait(semaphore1);

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

void test_CWait_Explicit()
{
    semaphore1 = (csem_t*) malloc(sizeof(csem_t));
    semaphore2 = (csem_t*) malloc(sizeof(csem_t));
    csem_init(semaphore1, 2);
    csem_init(semaphore2, 2);

    test_CWait_Function1();
	//ccreate(&test_CWait_Function1, NULL, HIGH);
	//ccreate(&test_CWait_Function2, NULL, MEDIUM);
	//ccreate(&test_CWait_Function3, NULL, LOW);

    //cwait(semaphore1);
	//cwait(semaphore1);
	//cwait(semaphore1);

	//if (!pnpcunit_assert_equal_int(-2, semaphore1->count))
	//	has_passed = pnpcunit_FALSE;

	//FirstFila2(semaphore1->fila);
	//if (!pnpcunit_assert_equal_int(CTHREAD_SUCCESS, NextFila2(semaphore1->fila)))
	//	has_passed = pnpcunit_FALSE;

	//if (has_passed)
      //  printf("PASS!\n");
    //else
      //  printf("FAIL!\n\n");
}

int main(int argc, char** argv)
{
    printf("\nTesting CWait:\n\n");
    test_CWait_Explicit();

    TOGGLE_PNPCUNIT(configure_pnpcunit)


}