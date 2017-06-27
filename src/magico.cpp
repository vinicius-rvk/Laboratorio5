/**
  *@file magico.cpp
  */


#include "../inc/magico.h"

using namespace std;

/**
* @brief Construtor vazio
*/
Magico::Magico():Monstro(){}
/**
* @brief Construtor recebendo um vector contendo as informações necessarias (ver cpp)
*/
Magico::Magico(vector<string>& palavras){


	this->nome = palavras[0];
	this->tipo = palavras[6];
	this->vida = stoi(palavras[1]);
	this->forca = stoi(palavras[2]);
	this->espirito = stoi(palavras[3]);
	this->vitalidade = stoi(palavras[4]);
	this->magic_point = stoi(palavras[5]);

}
/**
* @brief Construtor para criar um monstro manualmente
*/
Magico::Magico( string nome,
				int vida,
				int forca, 
				int espirito, 
				int vitalidade,
				int magic_point):
					Monstro(nome, "m", vida, forca, espirito, vitalidade),
					magic_point(magic_point)
					{}

/**
* @brief Retorna especial
*/
int Magico::getEspecial(){return this->magic_point;}

/**
* @brief Modifica especial
*/
void Magico::setEspecial(int magic_point){this->magic_point = magic_point;}

/**
* @brief sobrecarga do operador <<
*/
ostream& operator<<(ostream& o, Magico& magico){
	o << "Nome: " << magico.getNome() << endl;
	o << "Vida: " << magico.getVida() << endl;
	o << "Força: " << magico.getForca() << endl;
	o << "Espirito: " << magico.getEspirito() << endl;
	o << "Vitalidade: " << magico.getVitalidade() << endl;
	o << "Magic_point: " << magico.getEspecial() << endl;
return o;
}
