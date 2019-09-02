#include "Grafo.h"
#include <iostream>

int main()
{
	Grafo grafo;
	grafo.valoresPrueba();
	if (grafo.VerificarCadena("0232312")) {
		cout << "Aceptado" << endl;
	}
	else {
		cout << "Rechazado" << endl;
	}
	system("pause");
}
