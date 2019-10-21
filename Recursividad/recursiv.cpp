
#include "Header.h"

int main()
{

	/*LUIS
		FRAN
			RODRIGO
				SERGIO
					BELÉN*/

	char cadena[50];
	cout << "La gramatica es: E->E+T, E->T, T->T * F, T->F, F->(E), F->a \n" << endl;
	cout << "Introduce la cadena por reconocer (terminando con #):" << endl;
	cin >> cadena;

	//Validar que termine con #
	int leng = strlen(cadena);
	if (cadena[leng - 1] != '#') {
		cout << "La cadena debe terminar con # \n" << endl;

		cout << "Introduce la cadena por reconocer (terminando con #):" << endl;
		cin >> cadena;
	}

	recursivo(cadena);
}
