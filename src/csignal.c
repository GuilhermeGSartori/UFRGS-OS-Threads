/**
 * Implementation of CThread's csignal function, including supporting functions.
 * 
 * @author Renan Kummer
 */
#include "../include/constants.h"
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/scheduler.h"
#include <stdio.h>

// ======================================================================================
//                                    GLOBAL VARIABLES
// ======================================================================================

extern FILA2 ready_low;
extern FILA2 ready_mid;
extern FILA2 ready_high;


// ======================================================================================
//                            SUPPORT FUNCTIONS - DECLARATION
// ======================================================================================

/**
 * Get the highest priority thread waiting for this resource.
 * 
 * @param semaphore_queue The queue to get the thread from.
 * @return Highest priority thread waiting for this resource.
 */
TCB_t* csignal_get_highest_priority_thread(PFILA2 semaphore_queue);

/**
 * Insert thread into the appropriate APTO queue according to its priority.
 * 
 * @param thread The thread to insert.
 * @return CTHREAD_SUCCESS if successful, CTHREAD_FAILURE otherwise.
 */
ResultCode csignal_insert_in_ready_queue(TCB_t* thread);


// ======================================================================================
//                                        CSIGNAL
// ======================================================================================

/**
 * Release a resource managed by a semaphore variable.
 * 
 * @param sem   Pointer to semaphore variable that manages the released resource.
 * @return 0 if successful, -1 otherwise.
 */
int csignal(csem_t *sem) 
{
	if (sem == NULL || sem->count > 0)
		return CTHREAD_FAILURE;

	if(init_scheduler() != 0)
        return CTHREAD_FAILURE;

	sem->count++;
	if (sem->count <= 0)
	{
		TCB_t* next_thread = csignal_get_highest_priority_thread(sem->fila);
		return csignal_insert_in_ready_queue(next_thread);
	}
	
	return CTHREAD_SUCCESS;
}


// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

TCB_t* csignal_get_highest_priority_thread(PFILA2 semaphore_queue)
{
	if (semaphore_queue == NULL || (FirstFila2(semaphore_queue) != CTHREAD_SUCCESS))
		return NULL;

	TCB_t* current_thread = ((TCB_t*) GetAtIteratorFila2(semaphore_queue));

	TCB_t* low_priority    = (current_thread->prio == LOW)    ? current_thread : NULL;
	TCB_t* medium_priority = (current_thread->prio == MEDIUM) ? current_thread : NULL;
	TCB_t* high_priority   = (current_thread->prio == HIGH)   ? current_thread : NULL;

	while (GetAtNextIteratorFila2(semaphore_queue) == CTHREAD_SUCCESS)
	{
		if (NextFila2(semaphore_queue) != CTHREAD_SUCCESS)
			return NULL;

		current_thread = (TCB_t*) GetAtIteratorFila2(semaphore_queue);

		if (current_thread->prio == LOW && low_priority == NULL)
			low_priority    = current_thread;
		else if (current_thread->prio == MEDIUM && medium_priority == NULL)
			medium_priority = current_thread;	 
		else if (current_thread->prio == HIGH && high_priority == NULL)
			high_priority = current_thread;
	}

	if (high_priority != NULL)
		return high_priority;
	if (medium_priority != NULL)
		return medium_priority;
	
	return low_priority;
}

ResultCode csignal_insert_in_ready_queue(TCB_t* thread)
{
	if (thread == NULL)
		return CTHREAD_FAILURE;

	if (thread->prio == LOW)
	{
		if (AppendFila2(&ready_low, thread) == CTHREAD_SUCCESS)
			return CTHREAD_SUCCESS;
		else
			return CTHREAD_FAILURE;
	}

	if (thread->prio == MEDIUM)
	{
		if (AppendFila2(&ready_mid, thread) == CTHREAD_SUCCESS)
			return CTHREAD_SUCCESS;
		else
			return CTHREAD_FAILURE;
	}

	if (thread->prio == HIGH)
	{
		if (AppendFila2(&ready_high, thread) == CTHREAD_SUCCESS)
			return CTHREAD_SUCCESS;
		else
			return CTHREAD_FAILURE;
	}

	return CTHREAD_FAILURE;
}