/**
 * Implementation of CThread's ccreate function, including supporting functions.
 * 
 * @author Guilherme Sartori
 */
#include "../include/support.h"
#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/scheduler.h"
#include "ucontext.h"

#include <stdio.h>
#include <stdlib.h>



// ======================================================================================
//                            SUPPORT FUNCTIONS - DECLARATION
// ======================================================================================

/**
 * Sample of support function. It uses ccreate_ prefix to avoid naming conflicts.
 */ 
static void *ccreate_hello_world();


// ======================================================================================
//                                        CCREATE
// ======================================================================================

/**
 * Create a new thread.
 * 
 * @param start Pointer to function to run in new thread.
 * @param arg   Parameter to pass to new thread.
 * @param prio  Priority of new thread
 *                0 = HIGH
 *                1 = MEDIUM
 *                2 = LOW
 * @return The thread identifier (tid) when successful, -1 otherwise.
 */
int ccreate(void* (*start)(void*), void *arg, int prio) {

	int tid_r;
	extern int TID;
	extern TCB_t *running_thread2;
	extern ucontext_t *end_context;


	if(prio < 0 || prio > 2)
		return -1;


	if(init_scheduler() != 0)
		return -2;

	TCB_t* new_thread = (TCB_t*)malloc(sizeof(TCB_t));

	getcontext(&(new_thread->context));
	new_thread->tid = ++TID;
	new_thread->state = PROCST_APTO;
	new_thread->prio = prio;
	new_thread->context.uc_link = end_context;
	new_thread->context.uc_stack.ss_sp = (char*)malloc(20000);
	new_thread->context.uc_stack.ss_size = 20000;
	makecontext(&(new_thread->context), (void(*)(void))start, 1, arg);

	/*I also need to create a context for the ending of a thread,
	  so when a thread ends, a function that deals with this is called
	  (using the .link component of the struct), this function needs
	  to kill the TCB and find a new thread to execute in its place*/

	tid_r = TID;


	if(set_as_ready(new_thread) != 0)
		return -3;


	/*this is going to change, it will only put the TCP in the ready queue*/
	if(prio == 0)
	{
		TCB_t* thread_executing = (TCB_t*)malloc(sizeof(TCB_t));	
		thread_executing = which_executing_t();
		running_thread2 = new_thread; 
		swapcontext(&thread_executing->context, &running_thread2->context);
		printf("*snaps*\n");
	}

	return tid_r;
	
}



// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

static void *ccreate_hello_world()
{

	TCB_t *thread_executing = (TCB_t*)malloc(sizeof(TCB_t));
	extern TCB_t *running_thread2;


	thread_executing = which_executing_t();
    
    printf("Hello world!\n");
    swapcontext(&running_thread2->context, &thread_executing->context);
    printf("Bye world!\n");
    exit(0);
}

int ccreate_bye_world()
{
	return 0;
}

int main()
{
	TCB_t *thread_executing = (TCB_t*)malloc(sizeof(TCB_t));
	extern TCB_t *running_thread2;

	ccreate(&ccreate_hello_world, NULL, 0);
	//ccreate((void*(*)(void *))ccreate_bye_world, NULL, 0);
	printf("mr. stark i dont feel so good\n");
	thread_executing = which_executing_t();
	swapcontext(&thread_executing->context, &running_thread2->context);
	
	return 0;
}