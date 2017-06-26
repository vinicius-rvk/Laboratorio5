#include "../inc/jokenpo.h"

using namespace std;

void jogada_saruman(int i){
	cout << "JOKENPO... "<< endl << "EU ESCOLHO ";
	if(i == 1) cout << "PEDRA!" << endl;
	else if(i == 2) cout << "PAPEL!" << endl;
	else cout << "TESOURA!" << endl;
}

bool jokenpo(){
	int player, saruman;
	cout << "(1)Pedra"<< endl 
		 << "(2)Papel" << endl
		 << "(3)Tesoura" << endl
		 << "Escolha qual opção deseja usar: ";
	cin >> player;
	srand(time(NULL));
	saruman = (rand()%3)+1;
	jogada_saruman(saruman);

	if(player == 1){
		if(saruman == 1){
			cout << "EMPATE" << endl
				 << "AZAR O SEU. NÃO VAI TER OUTRA CHANCE E NÃO VAI GANHAR MONSTRO!" << endl;
				 return false;
		}else if(saruman == 2){
			cout << "PERDEUU!!!" << endl
				 << "EU SOU MUITO FODA!! HAHAHA..." << endl;
				 return false;
		}else{
			cout << "GANHOU!" << endl
				 << "DEU SORTE, MAS A PRÓXIMA EU ACABO COM VOCÊ!" << endl;
				 return true;
		}
	}else if(player == 2){
		if(saruman == 2){
			cout << "EMPATE" << endl
				 << "AZAR O SEU. NÃO VAI TER OUTRA CHANCE E NÃO VAI GANHAR MONSTRO!" << endl;
				 return false;
		}else if(saruman == 3){
			cout << "PERDEUU!!!" << endl
				 << "EU SOU MUITO FODA!! HAHAHA..." << endl;
				 return false;
		}else{
			cout << "GANHOU!" << endl
				 << "DEU SORTE, MAS A PRÓXIMA EU ACABO COM VOCÊ!" << endl;
				 return true;
		}
	}else {
		if(saruman == 3){
			cout << "EMPATE" << endl
				 << "AZAR O SEU. NÃO VAI TER OUTRA CHANCE E NÃO VAI GANHAR MONSTRO!" << endl;
				 return false;
		}else if(saruman == 1){
			cout << "PERDEUU!!!" << endl
				 << "EU SOU MUITO FODA!! HAHAHA..." << endl;
				 return false;
		}else{
			cout << "GANHOU!" << endl
				 << "DEU SORTE, MAS A PRÓXIMA EU ACABO COM VOCÊ!" << endl;
				 return true;
		}
	}

}