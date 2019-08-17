#include <iostream>
#include "Archivo.h"
using namespace std;

int main()
{
	//Leer archivo
	//Archivo debe estar en la misma direccion que MaquinaEjecucion.cpp
	Archivo archivo;
	archivo.LeerArchivo("prueba.txt");

	// variable menu
	int opcion;
	do {
		cout << "1.- Ver codigo" << endl;
		cout << "2.- Ver registros" << endl;
		cout << "3.- Ejecutar siguiente linea" << endl;
		cout << "4.- Ejecutar completo" << endl;
		cout << "5.- Salir" << endl;
		cout << "Ingrese opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
			archivo.ImprimirArchivo();
			break;
		}
		case 2: {
			cout << "caso 2" << endl;
			break;
		}
		case 3: {
			cout << "caso 3" << endl;
			break;
		}
		case 4: {
			cout << "caso 4" << endl;
			break;
		}
		}
	} while (opcion != 5);
}
