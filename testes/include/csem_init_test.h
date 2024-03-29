/**
 * Test suite to test the functionality provided by csem_init function.
 *
 * @author Marlize Ramos
 */
#ifndef UFRGS_OS_THREADS_TESTES_INCLUDE_CSEM_INIT_TEST_H
#define UFRGS_OS_THREADS_TESTES_INCLUDE_CSEM_INIT_TEST_H

#include "./PnP-CUnit/PnPCUnit.h"

/**
 * Configure test suite to be run.
 *   - Add Set Up, Before Each, After Each and Teardown functions.
 *   - Add test cases.
 *
 * @return An initialized test suite.
 */
pnpcunit_TestSuite* configure_suite_CSemInit();

#endif // UFRGS_OS_THREADS_TESTES_INCLUDE_CSEM_INIT_TEST_H
