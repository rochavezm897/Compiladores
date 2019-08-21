#include <iostream>
#include "Archivo.h"
#include "Ejecucion.h"
using namespace std;

int main()
{
	Ejecucion ejecucion;
	//Leer archivo
	//Archivo debe estar en la misma direccion que MaquinaEjecucion.cpp
	ejecucion.archivo.LeerArchivo("prueba.txt");

	// variable menu
	int opcion;
	do {
		cout << "1.- Ver codigo" << endl;
		cout << "2.- Ver registros" << endl;
		cout << "3.- Ejecutar siguiente linea" << endl;
		cout << "4.- Ejecutar completo" << endl;
		cout << "5.- Imprimir Instruccion" << endl;
		cout << "6.- Trace" << endl;
		cout << "7.- Reiniciar" << endl;
		cout << "8.- Salir" << endl;
		cout << "Ingrese opcion: ";
		cin >> opcion;
		switch (opcion) {
			case 1: {
				ejecucion.archivo.ImprimirArchivo();
				//cout << "Instruccion 1: " << ejecucion.archivo.instrucciones[0]<<endl;
				//cout << "Instruccion 2: " << ejecucion.archivo.instrucciones[1] << endl;
				break;
			}
			case 2: {
				ejecucion.ImprimirRegistros();
				break;
			}
			case 3: {
				ejecucion.EjecutarInstruccion();
				break;
			}
			case 4: {
				ejecucion.EjecutarCompleto();
				break;
			}
			case 5: {
				ejecucion.archivo.ImprimirInstruccion(ejecucion.lineaEjecutando);
				break;
			}
			case 6: {
				if (ejecucion.trace) {
					ejecucion.trace = false;
				}
				else {
					ejecucion.trace = true;
				}
				break;
			}
			case 7: {
				ejecucion.Reset();
				break;
			}
		}
	} while (opcion != 8);
}
