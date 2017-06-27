#Makefile for "programa" C++ application
#Criado por Roberto Vinicius Kuo

PROG = jogo

EXE = bin/
OBJ = build/
INC = inc/
LIB = lib/
SRC = src/

CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11 -I$(INC)
OBJS = $(OBJ)main.o $(OBJ)besta.o $(OBJ)magico.o $(OBJ)alado.o $(OBJ)monstro.o

linux: gerador.so jokenpo.so $(EXE)jogo

gerador.so: $(SRC)gerador.cpp $(INC)gerador.h 
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)gerador.cpp -o $(OBJ)gerador.o -I$(INC)
	$(CC) -shared -fPIC -o $(LIB)$@ $(OBJ)gerador.o
	@echo "+++ [Biblioteca dinamica criada em $(LIB)S@] +++"
	

jokenpo.so: $(SRC)jokenpo.cpp $(INC)jokenpo.h 
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)jokenpo.cpp -o $(OBJ)jokenpo.o -I$(INC)
	$(CC) -shared -fPIC -o $(LIB)$@ $(OBJ)jokenpo.o
	@echo "+++ [Biblioteca dinamica criada em $(LIB)S@] +++"

$(EXE)$(PROG) : $(OBJS)
	$(CC)  $(OBJS)  -o $@ $(LIB)gerador.so $(LIB)jokenpo.so

$(OBJ)main.o: $(INC)listaEncadeada.h $(INC)arena.h 
	$(CC) $(CPPFLAGS) -c $(SRC)main.cpp  -o $@ 

$(OBJ)monstro.o: $(INC)monstro.h
	$(CC) $(CPPFLAGS) -c $(SRC)monstro.cpp -o $@ -I$(INC)

$(OBJ)magico.o: $(INC)magico.h 
	$(CC) $(CPPFLAGS) -c $(SRC)magico.cpp -o $@ -I$(INC)

$(OBJ)alado.o: $(INC)alado.h 
	$(CC) $(CPPFLAGS) -c $(SRC)alado.cpp -o $@ -I$(INC)

$(OBJ)besta.o: $(INC)besta.h 
	$(CC) $(CPPFLAGS) -c $(SRC)besta.cpp -o $@ -I$(INC)


clean:
	rm -f core $(OBJS) $(OBJ)jokenpo.o $(OBJ)gerador.o $(LIB)gerador.so $(LIB)jokenpo.so
clean_all:
	rm -f core $(PROG) $(OBJS)