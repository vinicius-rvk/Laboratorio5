#include <iostream>
#include "../inc/listaEncadeada.h"
#include "../inc/arena.h"

using namespace std;

int main(){


  Lista<Monstro>* cards_player = new Lista<Monstro>();
  Lista<Monstro>* cards_pc = new Lista<Monstro>();

  cards_player->ler_banco("./banco/player.txt");
  cards_pc->ler_banco("./banco/pc.txt");

  arena<Monstro> *bat = new arena<Monstro>(cards_player, cards_pc);
  

  cout << "acabou"<< endl;
  delete cards_player;
  delete cards_pc;
  delete bat;


	return 0;

}