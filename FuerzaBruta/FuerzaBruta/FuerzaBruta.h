#pragma once
#include <stack>
#include <string>
using namespace std;

class FuerzaBruta
{
public:
	struct reglas
	{
		string NT;
		unsigned int MAX;
		unsigned int FIRST;
	};

	struct Hist {
		unsigned int P;
		string SYMB;
	};
	stack<Hist> HIST;
	string* RHS;
	reglas* LHS;
	FuerzaBruta();
	FuerzaBruta(string Reglas[], reglas Derivaciones[], unsigned int cantReglas, unsigned int cantDerivaciones);
	bool probarCadena(string CadenaAProbar);
	unsigned int F(string i);

private:
	struct cuadrupla
	{
		char S;
		unsigned int i;
		string A;
		string B;
	};
};