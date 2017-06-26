#include "batalha.h"

using namespace std;


Monstro* getMonstroRand(Lista<Monstro>* card, int n){
	Monstro* npc = card->getFirst()->getNext();
	for(int i = 0; i < (n%card->getQuantidade()+1); i++){
		npc = npc->getNext();
	}
	if(npc->getTipo()=="b"){
		Alado* alado = (Alado*)npc;
		cout << *alado << endl;
		return alado;
	}
	else if(npc->getTipo()=="b"){
		Besta* besta = (Besta*)npc;
		cout << *besta << endl;
		return besta;
	}else{
		Magico* magico = (Magico*)npc;
		cout << *magico << endl;
		return magico;
	}
}


void transferir(Monstro* monstro, string de, string para){
	// cria lista do banco X
	Lista<Monstro>* cards = new Lista<Monstro>();
	cards->ler_banco("./banco/"+de+".txt");
	Monstro* novo = cards->buscar(monstro->getNome()); //salva monstro M
	cout << " INFORMAR MONSTRO" << endl;
	cards->remover(monstro->getNome());
	cards->salvar("./banco/"+de+".txt"); // Salva banco com monstro removido
	delete cards;

	// Cria lista do banco Y
	cards = new Lista<Monstro>(); 
	cards->ler_banco("./banco/"+para+".txt");


	if(novo->getTipo()=="b"){
		Alado* alado = (Alado*)novo;
		cout << *alado << endl;
		cards->inserir(alado); // Inseri monstro no banco Y
	}
	else if(novo->getTipo()=="b"){
		Besta* besta = (Besta*)novo;
		cout << *besta << endl;
		cards->inserir(besta); // Inseri monstro no banco Y
	}else{
		Magico* magico = (Magico*)novo;
		cout << *magico << endl;
		cards->inserir(magico); // Inseri monstro no banco Y
	}

	cards->salvar("./banco/"+para+".txt"); //Salva banco com monstro inserido

}

void batalha(Lista<Monstro>* player, Lista<Monstro>* pc){
	string sair = "";

	while(!player->esta_vazia() && !pc->esta_vazia() && sair != "exit"){

		int aleatorio1, aleatorio2; 
		system("clean");
		player->listar();
		pc->listar();
		cout << "NOME DO MONSTRO Q DESEJA USAR: ";
		string nome_monstro;
		cin >> nome_monstro;

		aleatorio1 = rand()%(pc->getQuantidade()); // indice de monstro aleatorio
		cout << aleatorio1 << endl;

		Monstro* monstro_player = player->buscar(nome_monstro);
		Monstro* monstro_pc = getMonstroRand(pc, aleatorio1);

		// player atacando

		atack(monstro_player, monstro_pc, pc);

		system("clear");
		// pc atacks

		aleatorio1 = rand()%(pc->getQuantidade()); // indice de monstro aleatorio
		aleatorio2 = rand()%(player->getQuantidade()); // indice de monstro aleatorio
		monstro_pc = getMonstroRand(pc, aleatorio1);
		monstro_player = getMonstroRand(player, aleatorio2);

		atack(monstro_pc, monstro_player, player);

		cout << "Digite exit para sair? ";
		cin >> sair;
	}
}


void atack(Monstro* atacante, Monstro* vitima, Lista<Monstro>* card_defensor){
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
					transferir(vitima, "pc", "player"); // Trnsferencia de monstro no banco de dados 
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
					transferir(vitima, "pc", "player"); // Trnsferencia de monstro no banco de dados 
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
					transferir(vitima, "pc", "player"); // Trnsferencia de monstro no banco de dados 
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
					transferir(vitima, "pc", "player"); // Trnsferencia de monstro no banco de dados 
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
					transferir(vitima, "pc", "player"); // Trnsferencia de monstro no banco de dados 
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
					transferir(vitima, "pc", "player"); // Trnsferencia de monstro no banco de dados 
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
					transferir(vitima, "pc", "player"); // Trnsferencia de monstro no banco de dados 
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
					transferir(vitima, "pc", "player"); // Trnsferencia de monstro no banco de dados 
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
					transferir(vitima, "pc", "player"); // Trnsferencia de monstro no banco de dados 
					card_defensor->remover(vitima->getNome());  // remover da batalha
				}			
			}
		
		}
}