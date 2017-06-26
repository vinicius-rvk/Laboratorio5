#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "./inc/monstro.h"
#include "./inc/alado.h"
#include "./inc/besta.h"
#include "./inc/magico.h"




using namespace std;



void separar_texto(string in, vector<string>& palavras){

	int i =0, j = 0;
	string guarda;

	do{ 
		if(in[i] == ';'){
			//guarda += '\0';
			palavras.push_back(guarda);
			guarda = "";
			j++;
		}else{
			guarda += in[i];
			
		}
		j++;
		i++;

		
	}while(in[i] != '\0');

	palavras.push_back(guarda);
}


void carregar(vector<Monstro*>& saruman){
	fstream arquivo("./banco/saruman.txt");
	string linha;

	if(arquivo.is_open()){
		while(getline(arquivo, linha)){
			vector<string> palavras; //cria um vector temporario para armazenar a linha tratada

			separar_texto(linha, palavras);  // trata a linha do banco de dados
			
			Monstro* novo;
			if(palavras[6] == "a"){
				novo = new Alado(palavras);
			}
			else if(palavras[6] == "m"){
				novo = new Magico(palavras);
			}
			else if(palavras[6] == "b"){
				novo = new Besta(palavras);
			}else{
				cout << "nenhum tipo" << endl;
				cout << "ERRO!" << endl;
				return;
			}
			saruman.push_back(novo);
			cout << "saruman carregou monstro" << endl;
			palavras.erase(palavras.begin(), palavras.end()); // limpa o vector
			}
		arquivo.close();
	}
	else{
		cout << "ARQUIVO SARUAN.TXT NAO ABRIU!" << endl;
	}

}

int main(){
	vector<Monstro*> saruman;

	carregar(saruman);



	cout << "deu certo!" << endl;
	return 0;
}