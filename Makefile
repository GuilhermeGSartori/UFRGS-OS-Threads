#
# Makefile de EXEMPLO
#
# OBRIGATÓRIO ter uma regra "all" para geração da biblioteca e de uma
# regra "clean" para remover todos os objetos gerados.
#
# É NECESSARIO ADAPTAR ESSE ARQUIVO de makefile para suas necessidades.
#  1. Cuidado com a regra "clean" para não apagar o "support.o"
#
# OBSERVAR que as variáveis de ambiente consideram que o Makefile está no diretótio "cthread"
# 

CC=gcc
LIB_DIR=./lib
INC_DIR=./include
BIN_DIR=./bin
SRC_DIR=./src

all: cthread test

cthread: #dependências para compilação da ccthread
	$(CC) -Wall -c $(SRC_DIR)/scheduler.c -o $(BIN_DIR)/scheduler.o
	$(CC) -Wall -c $(SRC_DIR)/ccreate.c -o $(BIN_DIR)/ccreate.o
	$(CC) -Wall -c $(SRC_DIR)/cyield.c -o $(BIN_DIR)/cyield.o
	$(CC) -Wall -c $(SRC_DIR)/csetprio.c -o $(BIN_DIR)/csetprio.o
	$(CC) -Wall -c $(SRC_DIR)/cidentify.c -o $(BIN_DIR)/cidentify.o

test: #dependências para a criação de um executavel linkando os objetos
	$(CC) -Wall -o output  $(BIN_DIR)/support.o $(BIN_DIR)/scheduler.o $(BIN_DIR)/ccreate.o $(BIN_DIR)/cyield.o $(BIN_DIR)/csetprio.o $(BIN_DIR)/cidentify.o

clean:
	rm -rf $(LIB_DIR)/*.a $(BIN_DIR)/*.o $(SRC_DIR)/*~ $(INC_DIR)/*~ *~


