#ifndef _BESTAS_HPP_
#define _BESTAS_HPP_

#include "../inc/monstro.h"

using namespace std;

class Besta: public Monstro{
private:
	int furia;
public:
	Besta();
	Besta(vector<string>& );
	Besta(string, int, int, int, int, int);

	int getEspecial();

	void setEspecial(int);

	friend ostream& operator<<(ostream&, Besta&);

	//friend istream& operator>>(istream&, Besta&);

};

#endif //_BESTAS_HPP_