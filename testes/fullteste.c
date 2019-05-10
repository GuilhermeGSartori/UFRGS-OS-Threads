#include <stdio.h>
#include "../include/cthread.h"
#include "../include/support.h"
#include <stdlib.h>

static void *ccreate_hello_world();
static void *ccreate_bye_world();
static void *ccreate_join_waited();
static void *ccreate_join_waiter(void *tid);
static void *ccreate_join_middle2();
static void *ccreate_join_middle();

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

static void *ccreate_join_waiter(void *tid)
{

	printf("I'm going to wait my good friend! with tid %d\n", *(int *)tid);
	cjoin(*(int *)tid);
	printf("my friend did what he needed, bye!\n");

	return 0;
}

static void *ccreate_join_middle2()
{
	printf("I have the same priority but you were blocked, muahaha\n");
	return 0;
}

static void *ccreate_join_middle()
{
	printf("I were here first, muahaha\n");
	ccreate(&ccreate_join_middle2, NULL, 0);
	return 0;
}



int fullteste_main()
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

	ccreate(&ccreate_join_waiter, (void*)&wait, 0);
	ccreate(&ccreate_join_middle, NULL, 0);
	wait = ccreate(&ccreate_join_waited, NULL, 0);

	cyield();	

	printf("main is back to action!\n");

	int i, j;
	
	printf("im going to create 2 past threads\n");
	i = ccreate(&ccreate_join_middle, NULL, 0);
	j = ccreate(&ccreate_join_middle2, NULL, 0);
	printf("im going to block for the first one\n");
	cjoin(i);
	printf("im going to block for the second one\n");
	cjoin(j);
	printf("opsie, it already executed, because of the prio, so im going to end, bye\n");

	/*TODO
		
		*revisar trabs dos outros e ver se deixei passar detalhe
		*comentar o que precisar comentar
		*modular melhor, fazer outras funções extra
	*/


	return 0;
}