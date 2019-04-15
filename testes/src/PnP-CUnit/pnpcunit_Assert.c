/**
 * Implementation of assert functions.
 * 
 * @author Renan Kummer
 */
#include "../../include/PnP-CUnit/pnpcunit_Assert.h"

#include <string.h>
#include <ctype.h>

// ======================================================================================
//                                     MAIN FUNCTIONS
// ======================================================================================

pnpcunit_Bool pnpcunit_assert_equal_int(int value1, int value2)
{
    return value1 == value2;
}

pnpcunit_Bool pnpcunit_assert_not_equal_int(int value1, int value2)
{
    return !pnpcunit_assert_equal_int(value1, value2);
}

pnpcunit_Bool pnpcunit_assert_equal_char(char value1, char value2)
{
    return value1 == value2;
}

pnpcunit_Bool pnpcunit_assert_not_equal_char(char value1, char value2)
{
    return !pnpcunit_assert_equal_char(value1, value2);
}

pnpcunit_Bool pnpcunit_assert_equal_char_ignore_case(char value1, char value2)
{
    return tolower(value1) == tolower(value2);
}

pnpcunit_Bool pnpcunit_assert_not_equal_char_ignore_case(char value1, char value2)
{
    return !pnpcunit_assert_equal_char_ignore_case(value1, value2);
}

pnpcunit_Bool pnpcunit_assert_equal_string(char* value1, char* value2)
{
	if (value1 == NULL || value2 == NULL)
		return pnpcunit_FALSE;
	
	return strcmp(value1, value2) == 0;
}

pnpcunit_Bool pnpcunit_assert_not_equal_string(char* value1, char* value2)
{
    return !pnpcunit_assert_equal_string(value1, value2);
}

pnpcunit_Bool pnpcunit_assert_equal_string_ignore_case(char* value1, char* value2)
{
    if (value1 == NULL || value2 == NULL)
        return pnpcunit_FALSE;

    int index = 0;
    pnpcunit_Bool is_equal = pnpcunit_TRUE;
    
    while (is_equal && (value1[index] != '\0') && (value2[index] != '\0'))
    {
        char lower_v1 = tolower(value1[index]);
        char lower_v2 = tolower(value2[index]);

        if (pnpcunit_assert_not_equal_char(lower_v1, lower_v2))
            is_equal = pnpcunit_FALSE;

        index++;
    }

    if (value1[index] != '\0' || value2[index] != '\0')
        is_equal = pnpcunit_FALSE;

    return is_equal;
}


pnpcunit_Bool pnpcunit_assert_not_equal_string_ignore_case(char* value1, char* value2)
{
    return !pnpcunit_assert_equal_string_ignore_case(value1, value2);
}

pnpcunit_Bool pnpcunit_assert_equal_float(float value1, float value2, float margin_of_error)
{
	float variation = (value1 - value2) >= 0 ? (value1 - value2) : (value1 - value2) * -1;
	margin_of_error = margin_of_error >= 0 ? margin_of_error : margin_of_error * -1;

    pnpcunit_Bool is_within_margin = variation <= margin_of_error;
    
    return is_within_margin;
}

pnpcunit_Bool pnpcunit_assert_not_equal_float(float value1, float value2, float margin_of_error)
{
    return !pnpcunit_assert_equal_float(value1, value2, margin_of_error);
}

pnpcunit_Bool pnpcunit_assert_equal_double(double value1, double value2, double margin_of_error)
{
	double variation = (value1 - value2) >= 0 ? (value1 - value2) : (value1 - value2) * -1;
	margin_of_error = margin_of_error >= 0 ? margin_of_error : margin_of_error * -1;

	pnpcunit_Bool is_within_margin = variation <= margin_of_error;
    
    return is_within_margin;
}

pnpcunit_Bool pnpcunit_assert_not_equal_double(double value1, double value2, double margin_of_error)
{
    return !pnpcunit_assert_equal_double(value1, value2, margin_of_error);
}

pnpcunit_Bool pnpcunit_assert_equal_bool(pnpcunit_Bool value1, pnpcunit_Bool value2)
{
    return value1 == value2;
}

pnpcunit_Bool pnpcunit_assert_not_equal_bool(pnpcunit_Bool value1, pnpcunit_Bool value2)
{
    return !pnpcunit_assert_equal_bool(value1, value2);
}

pnpcunit_Bool pnpcunit_assert_true(pnpcunit_Bool value)
{
    return pnpcunit_assert_equal_bool(pnpcunit_TRUE, value);
}

pnpcunit_Bool pnpcunit_assert_false(pnpcunit_Bool value)
{
    return pnpcunit_assert_equal_bool(pnpcunit_FALSE, value);
}
