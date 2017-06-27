/**
  *@file besta.cpp
  */


#include "../inc/besta.h"
using namespace std;
/**
* @brief Construtor vazio
*/
Besta::Besta():Monstro(){}
/**
* @brief Construtor recebendo um vector contendo as informações necessarias (ver cpp)
*/
Besta::Besta(vector<string>& palavras){


	this->nome = palavras[0];
	this->tipo = palavras[6];
	this->vida = stoi(palavras[1]);
	this->forca = stoi(palavras[2]);
	this->espirito = stoi(palavras[3]);
	this->vitalidade = stoi(palavras[4]);
	this->furia = stoi(palavras[5]);

}

/**
* @brief Construtor para criar um monstro manualmente
*/
Besta::Besta(string nome,
				int vida, 
				int forca, 
				int espirito, 
				int vitalidade,
				int furia):
					Monstro(nome, "b", vida, forca, espirito, vitalidade),
					furia(furia)
					{}

/**
* @brief Retorna especial
*/
int Besta::getEspecial(){return this->furia;}

/**
* @brief Modifica especial
*/
void Besta::setEspecial(int furia){this->furia = furia;}

/**
* @brief sobrecarga do operador <<
*/
ostream& operator<<(ostream& o, Besta& besta ){
	o << "Nome: " << besta.getNome() << endl;
	o << "Vida: " << besta.getVida() << endl;
	o << "Força: " << besta.getForca() << endl;
	o << "Espirito: " << besta.getEspirito() << endl;
	o << "Vitalidade: " << besta.getVitalidade() << endl;
	o << "Especial: " << besta.getEspecial() << endl;
return o;
}


