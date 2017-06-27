/**
  *@file alado.cpp
  */

#include "../inc/alado.h"
using namespace std;

/**
* @brief Construtor vazio
*/
Alado::Alado():Monstro(){}
/**
* @brief Construtor recebendo um vector contendo as informações necessarias (ver cpp)
*/	
Alado::Alado(vector<string>& palavras){


	this->nome = palavras[0];
	this->tipo = palavras[6];
	this->vida = stoi(palavras[1]);
	this->forca = stoi(palavras[2]);
	this->espirito = stoi(palavras[3]);
	this->vitalidade = stoi(palavras[4]);
	this->agilidade = stoi(palavras[5]);

}
/**
* @brief Construtor para criar um monstro manualmente
*/
Alado::Alado(string nome,
				int vida, 
				int forca, 
				int espirito, 
				int vitalidade,
				int agilidade)
					:
					Monstro(nome, "a", vida, forca, espirito, vitalidade),
					agilidade(agilidade)
					{}


/**
* @brief Retorna especial
*/	
int Alado::getEspecial(){return this->agilidade;}

/**
* @brief Modifica especial
*/
void Alado::setEspecial(int agilidade){this->agilidade = agilidade;}

/**
* @brief sobrecarga do operador <<
*/
ostream& operator<<(ostream& o, Alado& alado){
	o << "Nome: " << alado.getNome() << endl;
	o << "Vida: " << alado.getVida() << endl;
	o << "Força: " << alado.getForca() << endl;
	o << "Espirito: " << alado.getEspirito() << endl;
	o << "Vitalidade: " << alado.getVitalidade() << endl;
	o << "Especial: " << alado.getEspecial() << endl;
return o;
}

