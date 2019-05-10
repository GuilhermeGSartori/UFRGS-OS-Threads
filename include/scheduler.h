/*
 * scheduler.h: arquivo de inclusão com os protótipos das funções auxiliares
 *              necessárias para a implementação e execução de um escalonador.
 *
 * @authors Guilherme, Marlize, Renan
 *
 */

#ifndef __scheduler__
#define __scheduler__

#define STACK_SIZE 20000
#define HOW_MANY_ARGS 1

#include "../include/support.h"
#include "../include/cdata.h"



typedef struct s_JOINED { 

	int		tid; 		// identificador da thread esperada
	TCB_t 	*blocked_t;	// TCB da thread bloqueada	
} JoinBlocked; 



/******************************************************************************
Inicia o escalonador, permitindo assim o uso da biblioteca cthread
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int init_scheduler();

/******************************************************************************
Inicializa as filas que serão utilizadas pelo escalonador
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int init_queues();

/******************************************************************************
Inicializa a thread main
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int init_main();

/******************************************************************************
Função acionada quando uma thread acaba(pelo link), assim permitindo a finalização 
completa dela e o escalonamento de outra thread.
Retorno:
	Quando executada com erros, retorna um valor negativo.
******************************************************************************/
int finish_thread();

/******************************************************************************
Coloca a thread passada como parâmetro no estado apto. A fila que ela vai
ser inserida é definida pela prioridade
Entrada:
	Um ponteiro de estrutura TCB_t da thread a ser inserida
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int set_as_ready(TCB_t *thread);

/******************************************************************************
Busca a thread de maior priodidade e remove essa thread da fila de aptos
Retorno:
	Quando executada corretamente: retorna um ponteiro de TCB_t
	Caso contrário, retorna NULL.
******************************************************************************/
TCB_t *get_most_prio_t();

/******************************************************************************
Verifica qual thread está em execução, sem remover ela do estado.
Retorno:
	Quando executada corretamente: retorna um ponteiro de TCB_t
	Caso contrário, retorna NULL.
******************************************************************************/
TCB_t *which_executing_t();

/******************************************************************************
Busca e insere a próxima thread a ser executada no estado de execução.
Retorno:
	Quando executada corretamente: retorna um ponteiro de TCB_t
	Caso contrário, retorna NULL.
******************************************************************************/
TCB_t *exec_next();

/******************************************************************************
Insere a estrutura utilizada para bloquar as threads que usaram cjoin em uma fila
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int join_block_t(JoinBlocked *);

/******************************************************************************
Verifica se a thread finalizada teve seu tid requisitado por alguém pela cjoin
Entrada:
	Um inteiro que representa o tid da thread que foi finalizada
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int check_if_join(int tid);

/******************************************************************************
Deleta o tid informado da lista de tids
Entrada:
	Um inteiro que representa o tid da thread que foi finalizada
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int delete_tid_list(int tid);

/******************************************************************************
Verifica se a thread de tid específico(parâmetro ainda existe).
Entrada:
	Um inteiro que representa o tid da thread procurada
Retorno:
	Quando encontra a tid corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int search_tid(int tid);

#endif