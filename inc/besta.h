/**
 * @file besta.h
 */

#ifndef _BESTAS_HPP_
#define _BESTAS_HPP_

#include "monstro.h"

using namespace std;

/**
 * @brief      Classe para Besta.
 */
class Besta: public Monstro{
private:
	int furia;
public:
	/**
 	* @brief Construtor vazio
 	*/
	Besta();
	/**
 	* @brief Construtor recebendo um vector contendo as informações necessarias (ver cpp)
 	*/	
	Besta(vector<string>& );
	/**
 	* @brief Construtor para criar um monstro manualmente
 	*/
	Besta(string, int, int, int, int, int);

	/**
 	* @brief Retorna especial
 	*/
	int getEspecial();

	/**
 	* @brief Modifica especial
 	*/
	void setEspecial(int);

	/**
 	* @brief sobrecarga do operador <<
 	*/
	friend ostream& operator<<(ostream&, Besta&);

};

#endif //_BESTAS_HPP_