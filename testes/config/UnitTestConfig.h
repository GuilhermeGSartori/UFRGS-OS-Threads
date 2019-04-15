/**
 * Declaration of configuration function for Plug N' Play CUnit Framework.
 *
 * @author Renan Kummer
 */
#ifndef UFRGS_OS_THREADS_TEST_CONFIG_UNITTESTCONFIG_H
#define UFRGS_OS_THREADS_TEST_CONFIG_UNITTESTCONFIG_H

#include "../include/PnP-CUnit/PnPCUnit.h"

/**
 * Add test suites to runner.
 *
 * @param runner A reference to a test runner to be configured.
 */
void configure_pnpcunit(pnpcunit_TestRunner *runner);

#endif // UFRGS_OS_THREADS_TEST_CONFIG_UNITTESTCONFIG_H
