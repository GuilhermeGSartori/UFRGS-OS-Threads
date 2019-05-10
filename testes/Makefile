# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# Makefile for testing application.                                           #
#                                                                             #
#  The tests are performed using Plug N' Play CUnit Framework, developed as a #
# side-project for Operating Systems I class at UFRGS, by RenanKummer.        #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                  CONSTANTS                                  #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
COMPILER   =gcc
LIBRARY_DIR=../lib

MAIN_INCLUDE_DIR=../include
MAIN_SOURCE_DIR =../src
MAIN_BINARY_DIR =../bin

TEST_INCLUDE_DIR=./include
TEST_SOURCE_DIR =./src
TEST_CONFIG_DIR =./config

PNPCUNIT_INCLUDE_DIR=./include/PnP-CUnit
PNPCUNIT_SOURCE_DIR =./src/PnP-CUnit

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                    TASKS                                    #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Default target executed when no arguments are given to make.
default_target: all

all: Test_CThread

Test_CThread:
	@echo "Building tests..."
	@$(COMPILER) -o $(MAIN_BINARY_DIR)/Test_CThread.exe $(PNPCUNIT_INCLUDE_DIR)/*.h $(TEST_INCLUDE_DIR)/*.h $(TEST_CONFIG_DIR)/*.h $(PNPCUNIT_SOURCE_DIR)/*.c $(TEST_SOURCE_DIR)/*.c $(TEST_CONFIG_DIR)/*.c -L$(LIBRARY_DIR) -lcthread -Wall

clean:
	@echo "Cleaning tests..."
	@rm -rf $(MAIN_BINARY_DIR)/Test_CThread.exe
