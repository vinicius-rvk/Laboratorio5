#Makefile for "programa" C++ application
#Criado por Roberto Vinicius Kuo

PROG = jogo
EXE = bin
OBJ =build
INC = inc
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11
OBJS = build/main.o build/besta.o build/magico.o build/alado.o build/monstro.o build/jokenpo.o

$(EXE)/$(PROG) : $(OBJS)
	$(CC)  $(OBJS)  -o $@

$(OBJ)/main.o: $(INC)/listaEncadeada.h $(INC)/arena.h
	$(CC) $(CPPFLAGS) -c src/main.cpp  -o $@ -I$(INC)

$(OBJ)/monstro.o: $(INC)/monstro.h
	$(CC) $(CPPFLAGS) -c src/monstro.cpp -o $@ -I$(INC)

$(OBJ)/magico.o: $(INC)/magico.h 
	$(CC) $(CPPFLAGS) -c src/magico.cpp -o $@ -I$(INC)

$(OBJ)/alado.o: $(INC)/alado.h 
	$(CC) $(CPPFLAGS) -c src/alado.cpp -o $@ -I$(INC)

$(OBJ)/besta.o: $(INC)/besta.h 
	$(CC) $(CPPFLAGS) -c src/besta.cpp -o $@ -I$(INC)

$(OBJ)/jokenpo.o: $(INC)/jokenpo.h
	$(CC) $(CPPFLAGS) -c src/jokenpo.cpp -o $@ -I$(INC)

clean:
	rm -f core $(OBJS)
clean_all:
	rm -f core $(PROG) $(OBJS)