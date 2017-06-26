#ifndef _JOKENPO_H_
#define _JOKENPO_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
* @brief Monstra o que o Saruman escolheu
* @param i  Recebe a opção do Saruman
*/
void jogada_saruman(int i);

/*
* @brief Jogo simples de jokenpo retornando true para vitoria e false para derota
* @return venceu?
*/
bool jokenpo();


#endif