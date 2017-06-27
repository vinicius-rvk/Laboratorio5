/**
 * @file alado.h
 */

#ifndef _ALADO_HPP_
#define _ALADO_HPP_

#include "monstro.h"

using namespace std;

/**
 * @brief      Classe para Alado.
 */
class Alado: public Monstro{
private:
	int agilidade;
public:

	/**
 	* @brief Construtor vazio
 	*/
	Alado();

	/**
 	* @brief Construtor recebendo um vector contendo as informações necessarias (ver cpp)
 	*/	
	Alado(vector<string>& );

	/**
 	* @brief Construtor para criar um monstro manualmente
 	*/
	Alado(string, int, int, int, int, int);

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
	friend ostream& operator<<(ostream&, Alado&);

};

#endif //_ALADO_HPP_