#include "../include/support.h"
#include "../include/cdata.h"
/*
 * scheduler.h: arquivo de inclusão com os protótipos das funções auxiliares
 *              necessárias para a implementação e execução de um escalonador.
 *
 * @authors Guilherme, Marlize, Renan
 *
 */

#ifndef __scheduler__
#define __scheduler__


/******************************************************************************
xxxx
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int init_scheduler();

/******************************************************************************
xxxx
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int init_queues();

/******************************************************************************
xxxx
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int init_main();

/******************************************************************************
xxxx
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int finish_thread();

/******************************************************************************
xxxx
Entrada:
	Um ponteiro de estrutura TCB_t da thread a ser inserida
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int set_as_ready(TCB_t *thread);

/******************************************************************************
xxxx
Entrada:
	Um ponteiro de estrutura TCB_t da thread a ser inserida
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
TCB_t *get_most_prio_t();

/******************************************************************************
xxxx
Entrada:
	Um ponteiro de estrutura TCB_t da thread a ser inserida
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
TCB_t *which_executing_t();

#endif