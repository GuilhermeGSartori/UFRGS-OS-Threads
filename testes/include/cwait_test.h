/**
 * Test suite to test the functionality provided by cwait function.
 *
 * @author Marlize Ramos
 */
#ifndef UFRGS_OS_THREADS_TESTES_INCLUDE_CWAIT_TEST_H
#define UFRGS_OS_THREADS_TESTES_INCLUDE_CWAIT_TEST_H

#include "./PnP-CUnit/PnPCUnit.h"

pnpcunit_Bool has_passed;
csem_t* semaphore1;
csem_t* semaphore2;

/**
 * Function for thread 1.
 */
void* test_CWait_Function1();

/**
 * Function for thread 2.
 */
void* test_CWait_Function2();

/**
 * Function for thread 3.
 */
void* test_CWait_Function3();

/**
 * Configure test suite to be run.
 *   - Add Set Up, Before Each, After Each and Teardown functions.
 *   - Add test cases.
 *
 * @return An initialized test suite.
 */
pnpcunit_TestSuite* configure_suite_CWait();

#endif // UFRGS_OS_THREADS_TESTES_INCLUDE_CWAIT_TEST_H
