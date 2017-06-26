#ifndef _MONSTROS_H_
#define _MONSTROS_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
	Monstro();
	Monstro(vector<string>& );
	Monstro(string, string, int, int, int, int);

	//int GETTERS
	string getNome();
	string getTipo();
	int getVida();
	int getForca();
	int getEspirito();
	int getVitalidade();
	Monstro* getNext();
	Monstro* getPrevious();

	//void SETTERS
	void setNome(string );
	void setVida(int);
	void setForca(int);
	void setEspirito(int);
	void setVitalidade(int);
	void setNext(Monstro*);
	void setPrevious(Monstro*);
	//SOBRECARGA DE OPERADORES
	friend ostream& operator<<(ostream&, Monstro&);

	//friend istream& operator>>(istream&, Monstro&);

};

#endif //_MONSTROS_HPP_