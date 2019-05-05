#include "../include/support.h"
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
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int init_scheduler();
/******************************************************************************
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int init_queues();
/******************************************************************************
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contrário, retorna um valor negativo.
******************************************************************************/
int init_main();


#endif