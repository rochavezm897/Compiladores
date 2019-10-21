#include "FuerzaBruta.h"

void main() {
	FuerzaBruta FB;
	FB = new FuerzaBruta();
	while (true)
	{

		printf("Probar cadena: ");
		string temp;
		scanf("%s", temp);
		FB.probarCadena(temp);
	}
}