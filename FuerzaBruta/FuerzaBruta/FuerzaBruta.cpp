#include "FuerzaBruta.h"
#include <stdlib.h>
#include <string>
#include <stdio.h>

using namespace std;

FuerzaBruta::FuerzaBruta(string Reglas[], reglas Derivaciones[], unsigned int cantReglas, unsigned int cantDerivaciones) {
	this->RHS = (string*)malloc(sizeof(string) * cantReglas);
	this->LHS = (reglas*)malloc(sizeof(reglas) * cantDerivaciones);

	this->RHS = Reglas;
	this->LHS = Derivaciones;
}

FuerzaBruta::FuerzaBruta() {
	this->LHS = (reglas*)malloc(sizeof(reglas) * 5);

	string tempR[10] = {
		string("T#"),
		string("TK#"),
		string("+T"),
		string("+TK"),
		string("F"),
		string("FR"),
		string("*F"),
		string("*FR"),
		string("(E)"),
		string("a")
	};

	reglas tempL[5] = {
		string("E"), 2, 1,
		string("K"), 2, 3,
		string("T"), 2, 5,
		string("R"), 2, 7,
		string("F"), 2, 9,
	};
	this->RHS = tempR;
	this->LHS = tempL;
}

unsigned int FuerzaBruta::F(string i) {
	
}

bool FuerzaBruta::probarCadena(string T) {
	unsigned int n = T.length();
	T.append("#");
	unsigned int i = 0;
	string SENT = this->LHS[0].NT + "#";
	unsigned int T_HIST = 1;
	string state = "q";
	this->HIST.emplace( 0, "");
	
	while (true) {
		string s = this->HIST.top().SYMB;
		string t = SENT.substr(1, 1);
		unsigned int p = 0;

		if (state == "q" && i == n + 1 && t == "#") {
			//Case 3
			state = "t";
			SENT = "";
			printf("SUCCESSFULL PARSE");
			break;
		}
		else if(state == "q") {
			if (F(t) > 0) {
				//Case 1
				T_HIST++;
				this->HIST.emplace(this->LHS[1], t);
				SENT = RHS[LHS[F(t)].FIRST] + SENT.substr(2);

				if (t == T.substr(i, 1)) {
					//Case 2
					T_HIST++;
					this->HIST.emplace(this->LHS[0], t);
					i++;
					SENT = RHS[LHS[F(t)].FIRST] + SENT.substr(2);
				}
				else {
					//Case 4
					state = "b";	
				}
			}
			else if  (F(s) == 0) {
				//Case 5
				T_HIST--;
				i--;
				SENT = s + SENT;
				if (p < LHS[F(s)].MAX) {
					//Case 6
					state = "q";
					HIST.top().P++;
					SENT = RHS[LHS[F(s)].FIRST + p] + SENT.substr(RHS[LHS[F(s)].FIRST + p - 1].length + 1);
				}
				else if (i == 1 && s == LHS[1].NT) {
					//Case 7
					SENT = RHS[LHS[F(t)].FIRST] + SENT.substr(RHS[LHS[F(s) + p - 1].FIRST].length() + 1);  
					T_HIST--;
					printf("UN SUCCESFULL PARSE");
					break;
				}
			}
		}
	}

}