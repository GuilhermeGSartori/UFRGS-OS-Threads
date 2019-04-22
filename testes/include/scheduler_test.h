/**
 * Test suite to test scheduler and dispatcher.
 *
 * @author Guilherme Sartori
 * @author Marlize Ramos
 * @author Renan Kummer
 */
#ifndef UFRGS_OS_THREADS_TESTES_INCLUDE_SCHEDULER_TEST_H
#define UFRGS_OS_THREADS_TESTES_INCLUDE_SCHEDULER_TEST_H

#include "./PnP-CUnit/PnPCUnit.h"

/**
 * Configure test suite to be run.
 *   - Add Set Up, Before Each, After Each and Teardown functions.
 *   - Add test cases.
 *
 * @return An initialized test suite.
 */
pnpcunit_TestSuite* configure_suite_Scheduler();

#endif // UFRGS_OS_THREADS_TESTES_INCLUDE_SCHEDULER_TEST_H
