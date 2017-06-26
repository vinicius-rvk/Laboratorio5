#ifndef _ALADO_HPP_
#define _ALADO_HPP_

#include "monstro.h"

using namespace std;

class Alado: public Monstro{
private:
	int agilidade;
public:
	Alado();
	Alado(vector<string>& );
	Alado(string, int, int, int, int, int);
	
	int getEspecial();

	void setEspecial(int);
	
	friend ostream& operator<<(ostream&, Alado&);

	//friend istream& operator>>(istream&, Alado&);

};

#endif //_ALADO_HPP_