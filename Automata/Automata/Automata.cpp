#include "Grafo.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	Grafo grafo;
	grafo.cargarArchivo("ingesta.txt");

	if (grafo.VerificarCadena("abaac")) {
		cout << "Aceptado" << endl;
	}
	else {
		cout << "Rechazado" << endl;
	}
	system("pause");

	return 0;
}
