/*
 * scheduler.h: arquivo de inclusão com os protótipos das funções auxiliares
 *              necessárias para a implementação e execução de um escalonador.
 *
 * @authors Guilherme, Marlize, Renan
 *
 */

#ifndef __scheduler__
#define __scheduler__


#include "../include/support.h"
#include "../include/cdata.h"




typedef struct s_JOINED { 

	int		tid; 		// identificador da thread
	TCB_t 	*blocked_t;	// TCB da thread bloqueada	
} JoinBlocked; 



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
	Quando executada com erros, retorna um valor negativo.
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
Retorno:
	Quando executada corretamente: retorna um ponteiro de TCB_t
	Caso contrário, retorna NULL.
******************************************************************************/
TCB_t *get_most_prio_t();

/******************************************************************************
xxxx
Retorno:
	Quando executada corretamente: retorna um ponteiro de TCB_t
	Caso contrário, retorna NULL.
******************************************************************************/
TCB_t *which_executing_t();

/******************************************************************************
xxxx
Retorno:
	Quando executada corretamente: retorna um ponteiro de TCB_t
	Caso contrário, retorna NULL.
******************************************************************************/
TCB_t *exec_next();

/******************************************************************************
xxxx
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int join_block_t(JoinBlocked *);

/******************************************************************************
xxxx
Entrada:
	Um inteiro que representa o tid da thread que foi finalizada
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int check_if_join(int tid);

#endif