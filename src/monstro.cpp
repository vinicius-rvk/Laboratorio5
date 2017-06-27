/**
  *@file monstro.cpp
  */

#include "../inc/monstro.h"

using namespace std;

/**
* @brief Construtor vazio
*/
Monstro::Monstro(){}

/**
* @brief Construtor recebendo um vector contendo as informações necessarias (ver cpp)
*/	
Monstro::Monstro(vector<string>& atributos){
	this->nome = atributos[0];
	this->tipo = atributos[6];
	this->vida = stoi(atributos[1]);
	this->forca = stoi(atributos[2]);
	this->espirito = stoi(atributos[3]);
	this->vitalidade = stoi(atributos[4]);
}
/**
* @brief Construtor para criar um monstro manualmente
*/
Monstro::Monstro(string nome, string tipo, int vida, int forca, int espirito, int vitalidade):
			nome(nome),
			tipo(tipo),
			vida(vida),
			forca(forca),
			espirito(espirito),
			vitalidade(vitalidade)
			{}

//GETTERS
/**
* @brief Retorna nome
*/	
string Monstro::getNome(){return this->nome;}
/**
* @brief Retorna tipo
*/	
string Monstro::getTipo(){return this->tipo;}
/**
* @brief Retorna vida
*/	
int Monstro::getVida(){return this->vida;}
/**
* @brief Retorna força
*/	
int Monstro::getForca(){return this->forca;}
/**
* @brief Retorna espirito
*/	
int Monstro::getEspirito(){return this->espirito;}
/**
* @brief Retorna vitalidade
*/	
int Monstro::getVitalidade(){return this->vitalidade;}
/**
* @brief Retorna NODE proximo
*/	
Monstro* Monstro::getNext(){ return next;}
/**
* @brief Retorna NODE anterior
*/	
Monstro* Monstro::getPrevious(){ return previous;}

// SETTERS
/**
* @brief Modifica nome
*/

void Monstro::setNome(string nome){this->nome = nome;}
/**
* @brief Modifica vida
*/

void Monstro::setVida(int vida){this->vida = vida;}
/**
* @brief Modifica força
*/

void Monstro::setForca(int forca){this->forca = forca;}
/**
* @brief Modifica espirito
*/

void Monstro::setEspirito(int espirito){this->espirito = espirito;}
/**
* @brief Modifica vitalidade
*/

void Monstro::setVitalidade(int vitalidade){this->vitalidade = vitalidade;}
/**
* @brief Modifica NODE proximo
*/

void Monstro::setNext(Monstro* next){this->next = next;}
/**
* @brief Modifica NODE ANTERIOR
*/
void Monstro::setPrevious(Monstro* previous){this->previous = previous;}
//SOBRECARGA DE OPERADORES

/**
* @brief sobrecarga do operador <<
*/
ostream& operator<<(ostream& o, Monstro& monstro){
	o << "Nome: " << monstro.getNome() << endl;
	o << "Vida: " << monstro.getVida() << endl;
return o;
}

//friend istream& operator>>(istream&, Monstro&);
