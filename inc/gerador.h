/**
 * @file gerador.h
 */

#ifndef _GERADOR_H_
#define _GERADOR_H_

#include "listaEncadeada.h"
#include "jokenpo.h"
#include <ctime>
#include <cstdlib>

using namespace std;

/**
 * @brief      Classe para gerador.
 */
extern "C" class gerador
{
private:
	vector<Monstro*> saruman;
	Lista<Monstro>* player;
public:
	/**
 	* @brief Construtor vazio
 	*/
	gerador(Lista<Monstro>* player);
	/**
 	* @brief Carrega banco de dados do saruman
 	*/
	void carregar();
	/**
 	* @brief Tratamento das linhas do banco de dados
 	*/
	void separar_texto(string, vector<string>&);
	/**
 	* @brief Inicio para o jogo jokenpo contra o saruman
 	*/
	void jogo();
	
};

#endif  // final _GERADOR_H_