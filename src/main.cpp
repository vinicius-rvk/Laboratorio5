#include <iostream>
#include "listaEncadeada.h"
#include "arena.h"

using namespace std;

int main(){


  Lista<Monstro>* cards_player = new Lista<Monstro>();
  Lista<Monstro>* cards_pc = new Lista<Monstro>();

  cards_player->ler_banco("./banco/player.txt");
  cards_pc->ler_banco("./banco/pc.txt");


  arena<Monstro> *bat = new arena<Monstro>(cards_player, cards_pc);



  //cout << teste->getEspecial() << endl;
  //cards_player->listar();
  //cards_pc->listar();
  //batalha(cards_player, cards_pc);

  //cards_player->salvar("./banco/player.txt");
  //cards_pc->salvar("./banco/pc.txt");
  

  cout << "acabou"<< endl;
  delete cards_player;
  delete cards_pc;
  delete bat;


	return 0;

}