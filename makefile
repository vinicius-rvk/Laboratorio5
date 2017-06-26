#Makefile for "programa" C++ application
#Criado por Roberto Vinicius Kuo

PROG = ./bin/jogo
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11
OBJS = ./src/main.o ./src/besta.o ./src/magico.o ./src/alado.o ./src/monstro.o

$(PROG) : $(OBJS)
	$(CC)  $(OBJS)  -o $(PROG)

./src/main.o: ./inc/listaEncadeada.h ./inc/arena.h
	$(CC) $(CPPFLAGS) -c ./src/main.cpp

./src/monstro.o: ./inc/monstro.h
	$(CC) $(CPPFLAGS) -c ./src/monstro.cpp

./src/magico.o: ./inc/magico.h 
	$(CC) $(CPPFLAGS) -c ./src/magico.cpp

./src/alado.o: ./inc/alado.h 
	$(CC) $(CPPFLAGS) -c ./src/alado.cpp

./src/besta.o: ./inc/besta.h 
	$(CC) $(CPPFLAGS) -c ./src/besta.cpp

./src/jokenpo.o: ./inc/jokenpo.h
	$(CC) $(CPPFLAGS) -c ./src/jokenpo.cpp
clean:
	rm -f core $(OBJS)
clean_all:
	rm -f core $(PROG) $(OBJS)