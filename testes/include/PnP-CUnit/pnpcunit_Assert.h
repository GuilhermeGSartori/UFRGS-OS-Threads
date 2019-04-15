/**
 * Declaration of assert functions.
 * 
 * @author Renan Kummer
 */
#ifndef PNPCUNIT_INCLUDE_ASSERT_H
#define PNPCUNIT_INCLUDE_ASSERT_H

#include "pnpcunit_Bool.h"

// ============================================================================================
//                                           INTEGER
// ============================================================================================

/**
 * Check if two integer values are equal.
 * 
 * @param value1 Integer value to compare.
 * @param value2 Integer value to compare.
 * @return pnpcunit_TRUE if equal, pnpcunit_FALSE otherwise.
 */ 
pnpcunit_Bool pnpcunit_assert_equal_int(int value1, int value2);

/**
 * Check if two integer values are different.
 * 
 * @param value1 Integer value to compare.
 * @param value2 Integer value to compare.
 * @return pnpcunit_TRUE if different, pnpcunit_FALSE otherwise.
 */ 
pnpcunit_Bool pnpcunit_assert_not_equal_int(int, int);


// ============================================================================================
//                                          CHARACTER
// ============================================================================================

/**
 * Check if two character values are equal. This function is case-sensitive.
 * 
 * @param value1 Character value to compare.
 * @param value2 Character value to compare.
 * @return pnpcunit_TRUE if equal, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool pnpcunit_assert_equal_char(char value1, char value2);

/**
 * Check if two character values are different. This function is case-sensitive.
 * 
 * @param value1 Character value to compare.
 * @param value2 Character value to compare.
 * @return pnpcunit_TRUE if different, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool pnpcunit_assert_not_equal_char(char value1, char value2);

/**
 * Check if two character values are equal. This function ignores case, i.e. it considers 
 * uppercase and lowercase as the same letter.
 * 
 * @param value1 Character value to compare.
 * @param value2 Character value to compare.
 * @return pnpcunit_TRUE if equal, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool pnpcunit_assert_equal_char_ignore_case(char value1, char value2);

/**
 * Check if two character values are different. This function ignores case, i.e. it considers
 * uppercase and lowercase as the same letter.
 * 
 * @param value1 Character value to compare.
 * @param value2 Character value to compare.
 * @return pnpcunit_TRUE if different, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool pnpcunit_assert_not_equal_char_ignore_case(char value1, char value2);

// ============================================================================================
//                                            STRING
// ============================================================================================

/**
 * Check if two string values are equal. This function is case-sensitive.
 * 
 * @param value1 String value to compare.
 * @param value2 String value to compare.
 * @return pnpcunit_TRUE if equal, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool pnpcunit_assert_equal_string(char* value1, char* value2);

/**
 * Check if two string values are different. This function is case-sensitive.
 * 
 * @param value1 String value to compare.
 * @param value2 String value to compare.
 * @return pnpcunit_TRUE if different, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool pnpcunit_assert_not_equal_string(char* value1, char* value2);

/**
 * Check if two string values are equal. This function ignores case, i.e. it considers 
 * uppercase and lowercase as the same letter.
 * 
 * @param value1 String value to compare.
 * @param value2 String value to compare.
 * @return pnpcunit_TRUE if equal, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool pnpcunit_assert_equal_string_ignore_case(char* value1, char* value2);

/**
 * Check if two string values are different. This function ignores case, i.e. it considers 
 * uppercase and lowercase as the same letter.
 * 
 * @param value1 String value to compare.
 * @param value2 String value to compare.
 * @return pnpcunit_TRUE if different, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool pnpcunit_assert_not_equal_string_ignore_case(char*, char*);


// ============================================================================================
//                                            FLOAT
// ============================================================================================

/**
 * Check if two single-precision floating point values are equal. Since floating point numbers
 * aren't completely accurate, this function considers as equals two values within a given
 * margin of error (e.g. given a margin of 0.001, the values 3.998 and 3.999 are equal).
 * 
 * @param value1 Float value to compare.
 * @param value2 Float value to compare.
 * @param margin_of_error Variation where values are still considered equal.
 * @return pnpcunit_TRUE if equal, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool pnpcunit_assert_equal_float(float value1, float value2, float margin_of_error);

/**
 * Check if two single-precision floating point values are different. Since floating point 
 * numbers aren't completely accurate, this function considers as equals two values within a 
 * given margin of error (e.g. given a margin of 0.001, the values 3.998 and 3.999 are equal).
 * 
 * @param value1 Float value to compare.
 * @param value2 Float value to compare.
 * @param margin_of_error Variation where values are still considered equal.
 * @return pnpcunit_TRUE if different, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool pnpcunit_assert_not_equal_float(float value1, float value2, float margin_of_error);


// ============================================================================================
//                                            DOUBLE
// ============================================================================================

/**
 * Check if two double-precision floating point values are equal. Since floating point numbers
 * aren't completely accurate, this function considers as equals two values within a given
 * margin of error (e.g. given a margin of 0.001, the values 3.998 and 3.999 are equal).
 * 
 * @param value1 Double value to compare.
 * @param value2 Double value to compare.
 * @param margin_of_error Variation where values are still considered equal.
 * @return pnpcunit_TRUE if equal, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool pnpcunit_assert_equal_double(double value1, double value2, double margin_of_error);

/**
 * Check if two double-precision floating point values are different. Since floating point 
 * numbers aren't completely accurate, this function considers as equals two values within a 
 * given margin of error (e.g. given a margin of 0.001, the values 3.998 and 3.999 are equal).
 * 
 * @param value1 Double value to compare.
 * @param value2 Double value to compare.
 * @param margin_of_error Variation where values are still considered equal.
 * @return pnpcunit_TRUE if different, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool pnpcunit_assert_not_equal_double(double value1, double value2, double margin_of_error);


// ============================================================================================
//                                           BOOLEAN
// ============================================================================================

/**
 * Check if two boolean values are equal.
 * 
 * @param value1 Boolean value to compare.
 * @param value2 Boolean value to compare.
 * @return pnpcunit_TRUE if equal, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool pnpcunit_assert_equal_bool(pnpcunit_Bool value1, pnpcunit_Bool value2);

/**
 * Check if two boolean values are different.
 * 
 * @param value1 Boolean value to compare.
 * @param value2 Boolean value to compare.
 * @return pnpcunit_TRUE if different, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool pnpcunit_assert_not_equal_bool(pnpcunit_Bool value1, pnpcunit_Bool value2);

/**
 * Check if boolean value is true.
 * 
 * @param value Boolean value to check.
 * @return pnpcunit_TRUE if value is true, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool pnpcunit_assert_true(pnpcunit_Bool value);

/**
 * Check if boolean value is false.
 * 
 * @param value Boolean value to check.
 * @return pnpcunit_TRUE if value is false, pnpcunit_FALSE otherwise.
 */
pnpcunit_Bool pnpcunit_assert_false(pnpcunit_Bool value);

#endif // PNPCUNIT_INCLUDE_ASSERT_H
