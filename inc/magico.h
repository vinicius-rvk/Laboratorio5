#ifndef _MAGICO_HPP_
#define _MAGICO_HPP_

#include "monstro.h"

using namespace std;

/**
 * @brief      Classe para Magico.
 */
class Magico: public Monstro
{
private:
	int magic_point;
public:
	/**
 	* @brief Construtor vazio
 	*/
	Magico();
	/**
 	* @brief Construtor recebendo um vector contendo as informações necessarias (ver cpp)
 	*/	
	Magico(vector<string>& );
	/**
 	* @brief Construtor para criar um monstro manualmente
 	*/
	Magico(string, int, int, int, int, int);
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
	friend ostream& operator<<(ostream&, Magico&);

	
};

#endif // _MAGICO_HPP_