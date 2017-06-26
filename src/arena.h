#ifndef _ARENA_H_
#define _ARENA_H_

#include "listaEncadeada.h"
#include "gerador.h"

using namespace std;

template<typename T>
class arena
{
private:
	Lista<Monstro>* player;
	Lista<Monstro>* pc;
public:
	arena( Lista<Monstro>* , Lista<Monstro>* );

	T* getMonstroRand(Lista<T>* , int );



	void transferir(T* , string , string );

	void batalha();

	void atack_passivo(T*);


	void atack(T* atacante, T* , Lista<T>* , string, string);
	
};

template<typename T>
arena<T>::arena(Lista<Monstro>* player, Lista<Monstro>* pc){
	this->player = player;
	this->pc = pc;
	batalha();
}


template<typename T>
T* arena<T>::getMonstroRand(Lista<T>* card, int n){
	T* npc = card->getFirst()->getNext();
	for(int i = 0; i < n && i < card->getQuantidade(); i++){
		npc = npc->getNext();
	}

	return npc;
}

template<typename T>
void arena<T>::transferir(T* monstro, string de, string para){
	// cria lista do banco X
	Lista<T>* perdedor = new Lista<T>();
	Lista<T>* vencedor = new Lista<T>();
	perdedor->ler_banco("./banco/"+de+".txt");
	vencedor->ler_banco("./banco/"+para+".txt");

	
	vencedor->inserir(perdedor->remover(monstro->getNome()));

	//vencedor->inserir((Monstro*)perdedor->remover(monstro->getNome())); // Inseri monstro no banco Y


	perdedor->salvar("./banco/"+de+".txt"); // Salva banco com monstro removido
	vencedor->salvar("./banco/"+para+".txt"); //Salva banco com monstro inserido

	delete perdedor;
	delete vencedor;

}

template <typename T>
void arena<T>::batalha(){
	int aleatorio1, aleatorio2; 
	string stop;

	while(player->getQuantidade() > 0 && pc->getQuantidade() > 0){

		srand(time(NULL));
		system("clean");
		player->listar();		
		cout << "NOME DO MONSTRO Q DESEJA USAR: ";
		cout << player->getQuantidade() << endl;
		cout << pc->getQuantidade() << endl;
		string nome_monstro;
		cin >> nome_monstro;

		aleatorio1 = rand()%(pc->getQuantidade()); // indice de monstro aleatorio
		cout << aleatorio1 << endl;

		T* monstro_player = player->buscar(nome_monstro);
		T* monstro_pc = getMonstroRand(pc, aleatorio1);

		cout <<  " atacante" << endl << *monstro_player << endl;
		cout <<  " vitima" << endl << *monstro_pc << endl;

		int tipo_atack;
		cout << "(1) Ataque Ativo" << endl 
			 << "(2) Ataque Passivo" << endl
		     << "Escolha o tipo de ataque:";
		cin >> tipo_atack;

		// player atacando
		if(tipo_atack == 1){	
			atack(monstro_player, monstro_pc, pc, "pc", "player");
		}
		else if(tipo_atack == 2){
			atack_passivo(monstro_player);
		}
		else{
			cout << "Escolha errada. \nPerdeu a vez!" << endl; 
		}
		// pc atacks
		cout << endl << "Aperte algo para continuar:";
		cin >> stop;

		if(pc->getQuantidade() > 0){
			cout << "Vez do PC" << endl;
			srand(time(NULL));
			aleatorio1 = rand()%(pc->getQuantidade()); // indice de monstro aleatorio
			cout << aleatorio1 << endl;

			srand(time(NULL));
			aleatorio2 = rand()%(player->getQuantidade()); // indice de monstro aleatorio
			cout << aleatorio2 << endl;

			monstro_pc = getMonstroRand(pc, aleatorio1);
			monstro_player = getMonstroRand(player, aleatorio2);
			
			cin >> stop;
			system("clean");

			if((aleatorio1%2) == 0){
			cout << "PC VAI ATACAR" <<enld;
				atack(monstro_pc, monstro_player, player, "player", "pc");
			}
			else {
				cout << "PC ESCOLHEI PASSIVA." <<enld;
				atack_passivo(monstro_pc);
			}
		}else{
			cout << "VOCE GANHOUEEEE!!!!" << endl;
		}
	}// FORA DO LAÇO DO JOGO
	if(player->getQuantidade() < 1){
		cout << "PERDEU, OTAR#*@!!!" << endl;
		cout << "MAS EM UMA CHANCE. VÁ VISITAR O SARUMAN PRA VER SE GANHA ALGUNS MONSTROS, SEU NOOB!" << endl;
		gerador saruman(player);

	}
}

template<typename T>
void arena<T>::atack_passivo(T* atacante){
	int forca, espirito, vitalidade, dano;

	forca = atacante->getForca()+(int)(0.3*atacante->getForca());
	espirito = atacante->getEspirito()+(int)0.2*atacante->getEspirito();
	vitalidade = atacante->getVitalidade()+(int)0.2*atacante->getVitalidade(); 
	dano = forca + espirito + vitalidade;
	
	atacante->setVida(atacante->getVida() + dano);
}


template<typename T>
void arena<T>::atack(T* atacante, T* vitima, Lista<T>* card_defensor, string de, string para){
	int forca, espirito, vitalidade, especial;

		if(atacante->getTipo() == "a"){
			Alado* alado  = (Alado*)atacante;   // convertendo pra classe filho

			if(vitima->getTipo() == "b"){
				forca = alado->getForca()+(int)(0.3*alado->getForca());
				espirito = alado->getEspirito()+(int)0.2*alado->getEspirito();
				vitalidade = alado->getVitalidade()+(int)0.2*alado->getVitalidade(); 
				especial = alado->getEspecial()+(int)(0.5*alado->getEspecial());
				int dano = forca + espirito + vitalidade + especial;
				cout << *vitima << endl;
				cout << "Alado bateu em Besta " << dano << endl;
				
				vitima->setVida(vitima->getVida() - dano);
				cout << *vitima << endl;
				if(vitima->getVida() <= 0){
					transferir(vitima, de, para); // Trnsferencia de monstro no banco de dados 
					card_defensor->remover(vitima->getNome());  // remover da batalha
				}
			}else if(vitima->getTipo() == "m"){
				forca = alado->getForca()-(int)(0.3*alado->getForca());
				espirito = alado->getEspirito()-(int)0.2*alado->getEspirito();
				vitalidade = alado->getVitalidade()-(int)0.2*alado->getVitalidade(); 
				especial = alado->getEspecial()-(int)0.5*alado->getEspecial();
				int dano = forca + espirito + vitalidade + especial;

				cout << "Alado bateu em Magico " << dano << endl;
				cout << *vitima << endl;
				vitima->setVida(vitima->getVida() - dano);
				cout << *vitima << endl;

				if(vitima->getVida() <= 0){
					transferir(vitima, de, para); // Trnsferencia de monstro no banco de dados 
					card_defensor->remover(vitima->getNome());  // remover da batalha
				}			
			}else{
				forca = alado->getForca();
				espirito = alado->getEspirito();
				vitalidade = alado->getVitalidade();
				especial = alado->getEspecial();
				int dano = forca + espirito + vitalidade + especial;

				cout << "Alado bateu em Alado " << dano << endl;
				cout << *vitima << endl;
				vitima->setVida(vitima->getVida() - dano);
				cout << *vitima << endl;


				if(vitima->getVida() <= 0){
					transferir(vitima, de, para); // Trnsferencia de monstro no banco de dados 
					card_defensor->remover(vitima->getNome());  // remover da batalha
				}			
			}

		}else if(atacante->getTipo() == "b"){
			Besta* besta = (Besta*)atacante;

			if(vitima->getTipo() == "m"){
				forca = besta->getForca()+(int)(0.3*besta->getForca());
				espirito = besta->getEspirito()+(int)0.2*besta->getEspirito();
				vitalidade = besta->getVitalidade()+(int)0.2*besta->getVitalidade(); 
				especial = besta->getEspecial()+(int)0.5*besta->getEspecial();
				int dano = forca + espirito + vitalidade + especial;

				cout << "Besta bateu em Magico " << dano << endl;
				cout << *vitima << endl;
				vitima->setVida(vitima->getVida() - dano);
				cout << *vitima << endl;

				if(vitima->getVida() <= 0){
					transferir(vitima, de, para); // Trnsferencia de monstro no banco de dados 
					card_defensor->remover(vitima->getNome());  // remover da batalha
				}			
			}else if(vitima->getTipo() == "a"){
				forca = besta->getForca()-(int)(0.3*besta->getForca());
				espirito = besta->getEspirito()-(int)0.2*besta->getEspirito();
				vitalidade = besta->getVitalidade()-(int)0.2*besta->getVitalidade(); 
				especial = besta->getEspecial()-(int)0.5*besta->getEspecial();
				int dano = forca + espirito + vitalidade + especial;


				cout << "Besta bateu em Alado " << dano << endl;
				cout << *vitima << endl;
				vitima->setVida(vitima->getVida() - dano);
				cout << *vitima << endl;


				if(vitima->getVida() <= 0){
					transferir(vitima, de, para); // Trnsferencia de monstro no banco de dados 
					card_defensor->remover(vitima->getNome());  // remover da batalha
				}			
			}else{
				forca = besta->getForca();
				espirito = besta->getEspirito();
				vitalidade = besta->getVitalidade();
				especial = besta->getEspecial();
				int dano = forca + espirito + vitalidade + especial;


				cout << "Besta bateu em Besta " << dano << endl;
				cout << *vitima << endl;
				vitima->setVida(vitima->getVida() - dano);
				cout << *vitima << endl;

				if(vitima->getVida() <= 0){
					transferir(vitima, de, para); // Trnsferencia de monstro no banco de dados 
					card_defensor->remover(vitima->getNome());  // remover da batalha
				}			
			}		
		}else {
			Magico* magico = (Magico*)atacante;
			if(vitima->getTipo() == "a"){
				forca = magico->getForca()+(int)(0.3*magico->getForca());
				espirito = magico->getEspirito()+(int)0.2*magico->getEspirito();
				vitalidade = magico->getVitalidade()+(int)0.2*magico->getVitalidade(); 
				especial = magico->getEspecial()+(int)0.5*magico->getEspecial();
				int dano = forca + espirito + vitalidade + especial;

				cout << "Magico bateu em Alado " << dano << endl;
				cout << *vitima << endl;
				vitima->setVida(vitima->getVida() - dano);
				cout << *vitima << endl;


				if(vitima->getVida() <= 0){
					transferir(vitima, de, para); // Trnsferencia de monstro no banco de dados 
					card_defensor->remover(vitima->getNome());  // remover da batalha
				}			
			}else if(vitima->getTipo() == "b"){
				forca = magico->getForca()-(int)(0.3*magico->getForca());
				espirito = magico->getEspirito()-(int)0.2*magico->getEspirito();
				vitalidade = magico->getVitalidade()-(int)0.2*magico->getVitalidade(); 
				especial = magico->getEspecial()-(int)0.5*magico->getEspecial();
				int dano = forca + espirito + vitalidade + especial;

				cout << "Magico bateu em Besta " << dano << endl;
				cout << *vitima << endl;
				vitima->setVida(vitima->getVida() - dano);
				cout << *vitima << endl;



				if(vitima->getVida() <= 0){
					transferir(vitima, de, para); // Trnsferencia de monstro no banco de dados 
					card_defensor->remover(vitima->getNome());  // remover da batalha
				}			
			}else{
				forca = magico->getForca();
				espirito = magico->getEspirito();
				vitalidade = magico->getVitalidade();
				especial = magico->getEspecial();
				int dano = forca + espirito + vitalidade + especial;

				cout << "Magico bateu em Magico " << dano << endl;
				cout << *vitima << endl;
				vitima->setVida(vitima->getVida() - dano);
				cout << *vitima << endl;


				if(vitima->getVida() <= 0){
					transferir(vitima, de, para); // Trnsferencia de monstro no banco de dados 
					card_defensor->remover(vitima->getNome());  // remover da batalha
				}			
			}
		
		}
}


#endif