#include "../inc/monstro.h"

using namespace std;

Monstro::Monstro(){}
Monstro::Monstro(vector<string>& atributos){
	this->nome = atributos[0];
	this->tipo = atributos[6];
	this->vida = stoi(atributos[1]);
	this->forca = stoi(atributos[2]);
	this->espirito = stoi(atributos[3]);
	this->vitalidade = stoi(atributos[4]);
}
Monstro::Monstro(string nome, string tipo, int vida, int forca, int espirito, int vitalidade):
			nome(nome),
			tipo(tipo),
			vida(vida),
			forca(forca),
			espirito(espirito),
			vitalidade(vitalidade)
			{}

//GETTERS
string Monstro::getNome(){return this->nome;}
string Monstro::getTipo(){return this->tipo;}
int Monstro::getVida(){return this->vida;}
int Monstro::getForca(){return this->forca;}
int Monstro::getEspirito(){return this->espirito;}
int Monstro::getVitalidade(){return this->vitalidade;}
Monstro* Monstro::getNext(){ return next;}
Monstro* Monstro::getPrevious(){ return previous;}
	
// SETTERS
void Monstro::setNome(string nome){this->nome = nome;}
void Monstro::setVida(int vida){this->vida = vida;}
void Monstro::setForca(int forca){this->forca = forca;}
void Monstro::setEspirito(int espirito){this->espirito = espirito;}
void Monstro::setVitalidade(int vitalidade){this->vitalidade = vitalidade;}
void Monstro::setNext(Monstro* next){this->next = next;}
void Monstro::setPrevious(Monstro* previous){this->previous = previous;}
//SOBRECARGA DE OPERADORES

ostream& operator<<(ostream& o, Monstro& monstro){
	o << "Nome: " << monstro.getNome() << endl;
	o << "Vida: " << monstro.getVida() << endl;
return o;
}

//friend istream& operator>>(istream&, Monstro&);
