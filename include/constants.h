/**
 * Define constants for the result codes of CThread's functions.
 *
 * @author Renan Kummer
 */
#ifndef UFRGS_OS_THREADS_INCLUDE_RESULT_CODE_H
#define UFRGS_OS_THREADS_INCLUDE_RESULT_CODE_H

typedef enum ResultCode
{
    CTHREAD_SUCCESS         =  0,
    CTHREAD_FAILURE         = -1,
    CTHREAD_NOT_IMPLEMENTED = -9
} ResultCode;


typedef enum Priority
{
    LOW    = 0,
    MEDIUM = 1,
    HIGH   = 2
} Priority;


#endif // UFRGS_OS_THREADS_INCLUDE_RESULT_CODE_H
