#include <iostream>
#include "../inc/arena.h"
#include "../inc/gerador.h"
#include "../inc/jokenpo.h"


using namespace std;

int main(){


  Lista<Monstro>* cards_player = new Lista<Monstro>();
  Lista<Monstro>* cards_pc = new Lista<Monstro>();

  cards_player->ler_banco("./banco/player.txt");
  cards_pc->ler_banco("./banco/pc.txt");

  arena<Monstro> *bat;

  while(cards_player->getQuantidade() > 0 && cards_pc->getQuantidade() > 0){

    bat = new arena<Monstro>(cards_player, cards_pc);
    
    gerador saruman(cards_player);

    cards_player = new Lista<Monstro>();

    cards_player->ler_banco("./banco/player.txt");

  }


  cout << "acabou"<< endl;
  delete cards_player;
  delete cards_pc;
  delete bat;


	return 0;

}