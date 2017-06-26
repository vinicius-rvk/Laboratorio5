#include "../inc/listaEncadeada.h"
#include "../inc/jokenpo.h"
#include <list>
#include <ctime>
#include <cstdlib>

using namespace std;

template<typename T>
class gerador
{
private:
	list<Monstro>* saruman;
	Lista<Monstro>* player;
public:
	gerador(Lista<Monstro>* player);
	
	void carregar();
	void separar_texto(string, vector<string>&);
	void jogo();
	
};


template<typename T>
gerador<T>::gerador(Lista<Monstro>* player){
	this->player = player;
	carregar();

	jogo();
}

template<typename T>
void gerador<T>::carregar(){
	fstream arquivo("../banco/saruman.txt");
	string linha;

	if(arquivo.is_open()){
		while(getline(arquivo, linha)){
			vector<string> palavras; //cria um vector temporario para armazenar a linha tratada

			separar_texto(linha, palavras);  // trata a linha do banco de dados
			
			T* novo;
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
			saruman->push_back(novo);
			cout << "saruman carregou monstro" << endl;
			palavras.erase(palavras.begin(), palavras.end()); // limpa o vector
			}
		arquivo.close();
	}
	else{
		cout << "ARQUIVO SARUAN.TXT NAO ABRIU!" << endl;
	}

}


template<typename T>
void gerador<T>::separar_texto(string in, vector<string>& palavras){

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

template<typename T>
void gerador<T>::jogo(){
	bool ganhou;
	int aleatorio = rand()%saruman->size();
	for(int i = 0; i < 5; i++){
		if(jokenpo()){
			srand(time(NULL));
			system("clean");
			cout << "Ganhou um Monstro!" << endl;
			cout << aleaTorio << endl;
			Monstro* novo = saruman[aleatorio];
			cout << *novo << endl;
			player->inserir(novo);
		}else{
			cout << "PERDEU, TROXA!" << endl;
		}
	}cout << "ACABOU!! SAI DAQUI ANTES QUE EU TE MATE!" << endl;
}
