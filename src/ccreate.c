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
static void *ccreate_bye_world();


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
	extern ucontext_t *end_context;


	if(prio < 0 || prio > 2)
		return -1;


	if(init_scheduler() != 0)
		return -2;

	TCB_t* new_thread = (TCB_t*)malloc(sizeof(TCB_t));

	getcontext(&(new_thread->context));
	new_thread->tid = ++TID;
	//new_thread->state = PROCST_APTO;
	new_thread->prio = prio;
	new_thread->context.uc_link = end_context;
	//preciso rever esse 2000... tá estranha essa stack!
	new_thread->context.uc_stack.ss_sp = (char*)malloc(20000);
	new_thread->context.uc_stack.ss_size = 20000;
	//q q é esse 1 no makecontexto? numero de argumentos?
	makecontext(&(new_thread->context), (void(*)(void))start, 1, arg);

	/*I also need to create a context for the ending of a thread,
	  so when a thread ends, a function that deals with this is called
	  (using the .link component of the struct), this function needs
	  to kill the TCB and find a new thread to execute in its place*/

	tid_r = TID;


	if(set_as_ready(new_thread) != 0)
		return -3;


	return tid_r;
	
}



// ======================================================================================
//                           SUPPORT FUNCTIONS - IMPLEMENTATION
// ======================================================================================

static void *ccreate_hello_world()
{
	//mudando prio pra 2 muda output...
	ccreate(&ccreate_bye_world, NULL, 2);	
    printf("Hello World!\n");
    return 0;
}

static void *ccreate_bye_world()
{

    printf("Bye World!\n");
    return 0;
}

static void *ccreate_join_waited()
{

	printf("wow, thanks for waiting me!\n");

	return 0;
}

/*static void *ccreate_join_waiter(void *tid)
{

	printf("I'm going to wait my good friend! with tid %d\n", *tid);
	cjoin(*tid);
	printf("my friend did what he needed, bye!\n");

	return 0;
}*/

static void *ccreate_join_middle2()
{
	printf("I have the same priority but you were blocked, muahaha\n");
	return 0;
}

static void *ccreate_join_middle()
{
	printf("I have more priority, muahaha\n");
	ccreate(&ccreate_join_middle2, NULL, 2);
	return 0;
}



int ccreate_main()
{

	//cenários, coloca ccreate do bye world antes do ccreate hello world, muda output
	//depois, ainda assim, muda prioridade, bye mais que hello...
	ccreate(&ccreate_hello_world, NULL, 0);
	printf("Is there anybody out there?\n");
	cyield();
	printf("Hello world, my sweet friend...\n");
	cyield();
	printf("Now my time has come..\n");

	int wait;

	wait = ccreate(&ccreate_join_waited, NULL, 1);
	//ccreate(&ccreate_join_waiter, &wait, 0);
	ccreate(&ccreate_join_middle, NULL, 0);
	printf("I'm going to wait my good friend! with tid %d\n", wait);
	cjoin(wait);
	printf("my friend did what he needed, bye!\n");

	/*TODO
		*Fazer os arquivos de teste
		*Explicar o que cada função auxiliar faz
		*Stack não ser 2000... e sim algo real, de verdade, que faça sentido (olhar os outros trabs)
		*revisar trabs dos outros e ver se deixei passar detalhe
		*Passar argumentos pra ccreate e ver se eles funcionar assim
		*comentar o que precisar comentar
		*make fazer .a e rm
		*modular melhor, fazer outras funções extra
	*/


	return 0;
}