#ifndef _MONSTROS_H_
#define _MONSTROS_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief      Classe para Monstro.
 */
class Monstro{
protected: 
	string nome;
	string tipo;
	int vida,
		forca,
		espirito,
		vitalidade;
	Monstro* next;
	Monstro* previous;
public:
	 /**
 	* @brief Construtor vazio
 	*/
	Monstro();
	/**
 	* @brief Construtor recebendo um vector contendo as informações necessarias (ver cpp)
 	*/
	Monstro(vector<string>& );
	/**
 	* @brief Construtor para criar um monstro manualmente
 	*/
	Monstro(string, string, int, int, int, int);

	//int GETTERS
	/**
 	* @brief Retorna nome
 	*/
	string getNome();
	/**
 	* @brief Retorna Tipo
 	*/
	string getTipo();
	/**
 	* @brief Retorna Vida
 	*/
	int getVida();
	/**
 	* @brief Retorna força
 	*/
	int getForca();
	/**
 	* @brief Retorna espirito
 	*/
	int getEspirito();
	/**
 	* @brief Retorna vitalidade
 	*/
	int getVitalidade();
	/**
 	* @brief Retorna proximo NODE<Monstro>
 	*/
	Monstro* getNext();
	/**
 	* @brief Retorna NODE<Monstro> anterior
 	*/
	Monstro* getPrevious();

	//void SETTERS
	/**
 	* @brief Modifica nome
 	*/
	void setNome(string );
	/**
 	* @brief Modifica vida
 	*/
	void setVida(int);
	/**
 	* @brief Modifica força
 	*/
	void setForca(int);
	/**
 	* @brief Modifica espirito
 	*/
	void setEspirito(int);
	/**
 	* @brief Modifica vitalidade
 	*/
	void setVitalidade(int);
	/**
 	* @brief Modifica NODE<Monstro> proximo
 	*/
 	void setNext(Monstro*);
	/**
 	* @brief Modifica NODE<Monstro> anterior
 	*/
 	void setPrevious(Monstro*);

	//SOBRECARGA DE OPERADORES
	/**
 	* @brief sobrecarga do operador <<
 	*/
	friend ostream& operator<<(ostream&, Monstro&);


};

#endif //_MONSTROS_HPP_