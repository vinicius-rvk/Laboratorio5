/**
  *@file gerador.cpp
  */


#include "../inc/gerador.h"

using namespace std;
/**
* @brief Construtor vazio
*/
gerador::gerador(Lista<Monstro>* player){
	this->player = player;
	carregar();

	jogo();
}

/**
* @brief Carrega banco de dados do saruman
*/
void gerador::carregar(){
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
			}
			saruman.push_back(novo);
			//cout << "saruman carregou monstro" << endl;
			palavras.erase(palavras.begin(), palavras.end()); // limpa o vector
			}
		arquivo.close();
	}
	else{
		cout << "ARQUIVO SARUAN.TXT NAO ABRIU!" << endl;
	}

}
/**
* @brief Tratamento das linhas do banco de dados
*/
void gerador::separar_texto(string in, vector<string>& palavras){

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

/**
* @brief Inicio para o jogo jokenpo contra o saruman
*/
void gerador::jogo(){
	int aleatorio;
	for(int i = 0; i < 5; i++){
		if(jokenpo() == true){
			srand(time(NULL));
			aleatorio = rand()%saruman.size();
			cout << "Ganhou um Monstro!" << endl;
			cout << aleatorio << endl;
			
			cout << *(saruman[aleatorio]) << endl;
			player->inserir(saruman[aleatorio]);
		}else{
			cout << "PERDEU, TROXA!" << endl;
		}
	}cout << "ACABOU!! SAIA DAQUI ANTES QUE EU TE MATE!" << endl;
	player->salvar("./banco/player.txt");
}
