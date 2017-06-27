/**
* @file listaEncadeada.h
* @author Roberto Vinicius Kuo <viniciusrvk@gmail.com>
*
*/
#ifndef _LISTA_H_ // Uso do pré-processador
#define _LISTA_H_ // Definição do identificador do cabeçalho

#include <iostream>
#include "alado.h"
#include "besta.h"
#include "magico.h"
#include "monstro.h"
#include <vector>
#include <fstream>


/**
* @class Lista
* @brief objeto generico com a finalidade de criar e manipular lista de qualquer objeto.
*/
template<typename T>
class Lista {
private:
	T* value; //variavel de objeto de qualuqer tipo
	T* first; // variavel que indica qual o inicio da lista
	T* end; // variavel que indica qual é o ultimo da lista
	int quantidade; // variavel que indica quantidade
public:
	/**
	* @brief Costructor de uma lista de objeto generico
	*/
	Lista();
	/**
	* @brief Destrutor
	*/
    ~Lista();
	//GETTERS
	/**
    * @brief Retorna um ponteiro do objeto limitador inicial
    */
	T* getFirst();
	/**
    * @brief Retorna um ponteiro do objeto limitador final
    */
	T* getEnd();
	/**
    * @brief Retorna a variavel quantidade do objeto
    */
	int getQuantidade();
	//SETTERS
	void setQuantidade(int);
	

	//funçoes
	/**
	* @brief Fução de separar palavras de uma frase em varias strings
	* @ppp in string contendo a frase a ser tratada
	* @ppp &palavras Vrctor de string para guardar as palavras separadas
	*/
	void tratar_texto(string , vector<string>& );

	/**
    * @brief Lista todos os objetos da lista
    */
	void listar();
	/**
    * @brief Iseri objeto generico no final da lista
    * @param T* Generico
    */
	void inserir(T*);
	/**
    * @brief Busca um objeto na lista
    * @param string Recebe uma string para a busca
    * @return curr Retorna objeto encontrado
    */
	T* buscar(string); // buscar por string
	/**
    * @brief Remove objeto da lista buscando por string
    * @param string String com o nome TAG do objeto
    */
	T* remover(string); // busca por string
	/**
    * @brief Recebe o nome do arquivo como string e faz leiura e estanciamento dos objetos
    * @param string
    */
	void ler_banco(string );
	
	/**
    * @brief Recebe o nome do arquivo como string e grava a partida.
    * @param string
    */
	void salvar(string);
	/**
	* @brief Retorna verdadeiro se a lista estiver vazia 
	*/
	bool esta_vazia();
};
/**
* @brief Cria uma lista de objeto generico
*/
template <typename T>
Lista<T>::Lista(){
	this->first = new T();
    this->end = new T();

	first->setNext(end);
	first->setPrevious(NULL);

	end->setNext(NULL);
	end->setPrevious(first);

	quantidade = 0;

}
/**
* @brief Destrutor
*/
template<typename T>
Lista<T>::~Lista(){

}
//GETTERS
/**
    * @brief retorna um ponteiro do objeto limitador inicial
    */
template<typename T>
T* Lista<T>::getFirst(){ return first;}
/**
    * @brief retorna um ponteiro do objeto limitador final
    */
template<typename T>
T* Lista<T>::getEnd(){ return end;}
/**
    * @brief retorna a variavel quantidade
    */
template <typename T>
int Lista<T>::getQuantidade(){ return this->quantidade;}

template<typename T>
void Lista<T>::setQuantidade(int nova){this->quantidade = nova;} 

//FUNÇOES

/**
* @brief Fução de separar palavras de uma frase em varias strings
* @ppp in string contendo a frase a ser tratada
* @ppp &palavras Vrctor de string para guardar as palavras separadas
*/
template<typename T>
void Lista<T>::tratar_texto(string in, vector<string>& palavras){

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
* @brief Lista todos os objetos da lista
*/
template<typename T>
void Lista<T>::listar(){
	T* curr = first->getNext(); //CRIA UM OBJETO PARA PERCORRER
	cout << "INICIO DA LISTA DE MONSTROS";
	int i = 0;
	while(curr != end &&  this->quantidade > i++){ // PERCORRE IMPRIMINDO ENQUANTO NAO CHEGAR AO FINAL DA LISTA
		cout << "-----------" << endl;
		if(curr->getTipo() == "a"){
			cout << *((Alado*)curr) << endl << endl;
		}else if(curr->getTipo() == "b"){
			cout << *((Besta*)curr) << endl << endl;
		}else if(curr->getTipo() == "m"){
			cout << *((Magico*)curr) << endl << endl;
		}
		curr = curr->getNext();
	}
	cout << "FIM DA LISTA ----------------" << endl << endl;

}
/**
* @brief Inseri objeto generico no final da lista
* @param *novo Ponteiro para um objeto generico
*/
template <typename T>
void Lista<T>::inserir(T* novo){ 
	novo->setNext(this->end); 	
	novo->setPrevious(this->end->getPrevious()); 	
	
	novo->getNext()->setPrevious(novo); 	
	novo->getPrevious()->setNext(novo); 	
	
	this->quantidade++;
}

/**
    * @brief Busca e retorna objeto generico
    * @param String para comparar os nomes dos objetos genericos
    * @return curr Retora o objeto encontrado
    */
template<typename T>
T* Lista<T>::buscar(string s){
	T* curr = first->getNext();
	int i = 0;
	while(curr->getNome() != s && curr != end && this->quantidade > i){
		//cout << *curr << endl;
		curr = curr->getNext();
		i++;
	}
	if (curr == end)
	{
		cout << "Não existe esse monstro." << endl;
		return NULL;
	}else{
		return curr;
	}
}

 /**
    * @brief Remove objeto da lista
    * @param s String com o nome do objeto generico a ser removido
    */
template <typename T>
T* Lista<T>::remover(string s){
	
	T* curr = first->getNext();

	while(curr->getNome() != s && curr != end){
		curr = curr->getNext();
	}

	curr->getNext()->setPrevious(curr->getPrevious());
	curr->getPrevious()->setNext(curr->getNext());

	quantidade--;
	return curr;
	

} 
/**
* @brief Recebe o nome do arquivo e faz a leitura criando objetos genericos
* @param arq Nome do arquivo a ser lido
*/
template<typename T>
void Lista<T>::ler_banco(string arq){
	
	fstream arquivo(arq);
	string linha;

	if(arquivo.is_open()){
		while(getline(arquivo, linha)){
			vector<string> palavras; //cria um vector temporario para armazenar a linha tratada

			tratar_texto(linha, palavras);  // trata a linha do banco de dados
			
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
			inserir(novo);
			//cout << *novo << endl;
			palavras.erase(palavras.begin(), palavras.end()); // limpa o vector
			}
		arquivo.close();
	}
	else{
		cout << "ARQUIVO "<< arq <<" NAO ABRIU!" << endl;
	}
}

/**
* @brief Recebe o nome do arquivo e salva em formato especifico no arquivo
* @param arq Nome do arquivo a ser lido
*/
template<typename T>
void Lista<T>:: salvar(string arq){
	ofstream arquivo(arq);

	T* curr = this->first->getNext();
	
	while(curr != this->end ){
		arquivo << curr->getNome() <<";";
		//arquivo << "salvou corretamente" << ";";
		arquivo << curr->getVida() <<";";
		arquivo << curr->getForca() <<";";
		arquivo << curr->getEspirito() <<";";
		arquivo << curr->getVitalidade() <<";";
		
		if(curr->getTipo() == "a"){
			arquivo << ((Alado*)curr)->getEspecial();
		}
		else if(curr->getTipo() == "m"){
			arquivo << ((Magico*)curr)->getEspecial();
		}
		else if(curr->getTipo() == "b"){
			arquivo << ((Besta*)curr)->getEspecial();
		}
		arquivo << ";";
		arquivo << curr->getTipo();
		arquivo << endl;
		curr = curr->getNext();
	}cout << endl;

}
/**
* @brief Verifica se a Lista esta vazia
* @return true/false se ela esta vazia, true; se nao, false
*/

template<typename T>
bool Lista<T>::esta_vazia(){
	T* teste = first->getNext();
	if(teste == end)
		return true;
	else
		return false;
}
#endif // fim da definição _LISTAENCADEADA_H_