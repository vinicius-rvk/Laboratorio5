#include "../inc/alado.h"
using namespace std;

Alado::Alado():Monstro(){}
Alado::Alado(vector<string>& palavras){


	this->nome = palavras[0];
	this->tipo = palavras[6];
	this->vida = stoi(palavras[1]);
	this->forca = stoi(palavras[2]);
	this->espirito = stoi(palavras[3]);
	this->vitalidade = stoi(palavras[4]);
	this->agilidade = stoi(palavras[5]);

}
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

int Alado::getEspecial(){return this->agilidade;}


void Alado::setEspecial(int agilidade){this->agilidade = agilidade;}

ostream& operator<<(ostream& o, Alado& alado){
	o << "Nome: " << alado.getNome() << endl;
	o << "Vida: " << alado.getVida() << endl;
	o << "Força: " << alado.getForca() << endl;
	o << "Espirito: " << alado.getEspirito() << endl;
	o << "Vitalidade: " << alado.getVitalidade() << endl;
	o << "Especial: " << alado.getEspecial() << endl;
return o;
}

//friend istream& operator>>(istream&, Alado&);
