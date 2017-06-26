#Makefile for "programa" C++ application
#Criado por Roberto Vinicius Kuo

PROG = ./bin/jogo
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11
OBJS = ./build/main.o ./build/besta.o ./build/magico.o ./build/alado.o ./build/monstro.o

$(PROG) : $(OBJS)
	$(CC)  $(OBJS)  -o $(PROG)

/build/main.o: ./inc/listaEncadeada.h ./inc/arena.h
	$(CC) $(CPPFLAGS) -c ./src/main.cpp

/build/monstro.o: ./inc/monstro.h
	$(CC) $(CPPFLAGS) -c ./build/monstro.cpp

/build/magico.o: ./inc/magico.h 
	$(CC) $(CPPFLAGS) -c ./src/magico.cpp

/build/alado.o: ./inc/alado.h 
	$(CC) $(CPPFLAGS) -c ./src/alado.cpp

/build/besta.o: ./inc/besta.h 
	$(CC) $(CPPFLAGS) -c ./src/besta.cpp

/build/jokenpo.o: ./inc/jokenpo.h
	$(CC) $(CPPFLAGS) -c ./src/jokenpo.cpp
clean:
	rm -f core $(OBJS)
clean_all:
	rm -f core $(PROG) $(OBJS)