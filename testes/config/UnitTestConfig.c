/**
 * Implementation of configuration function for Plug N' Play CUnit Framework.
 *
 * @author Renan Kummer
 */
#include "UnitTestConfig.h"

// =============================================================================================
//                                          TEST SUITES
// =============================================================================================
#include "../include/cidentify_test.h"
#include "../include/csem_init_test.h"
#include "../include/scheduler_test.h"
#include "../include/csetprio_test.h"
#include "../include/ccreate_test.h"
#include "../include/csignal_test.h"
#include "../include/cyield_test.h"
#include "../include/cjoin_test.h"
#include "../include/cwait_test.h"

/**
 * Add all test suites that should be run.
 *
 * @param runner The test runner to be configured.
 */
void configure_pnpcunit(pnpcunit_TestRunner *runner)
{
	// -- ADD TEST SUITE BELOW: --
	pnpcunit_add_test_suite(runner, configure_suite_CCreate);
	pnpcunit_add_test_suite(runner, configure_suite_CIdentify);
	pnpcunit_add_test_suite(runner, configure_suite_CJoin);
	pnpcunit_add_test_suite(runner, configure_suite_CSemInit);
	pnpcunit_add_test_suite(runner, configure_suite_CSetprio);
	//pnpcunit_add_test_suite(runner, configure_suite_CSignal);
	pnpcunit_add_test_suite(runner, configure_suite_CWait);
	pnpcunit_add_test_suite(runner, configure_suite_CYield);
	pnpcunit_add_test_suite(runner, configure_suite_Scheduler);	
}
