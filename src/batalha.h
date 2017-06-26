#ifndef _BATALHA_H_
#define _BATALHA_H_

#include "listaEncadeada.h"
#include <cstdlib>


Monstro* getMonstroRand(Lista<Monstro>* , int );

void transferir(Monstro* monstro, string de, string para);

void batalha(Lista<Monstro>* player, Lista<Monstro>* pc);

void atack(Monstro* atacante, Monstro* vitima, Lista<Monstro>* card_defensor);



#endif //_BATALHA_HPP_