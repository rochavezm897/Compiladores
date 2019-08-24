#include <iostream>
#include "Archivo.h"
#include "Ejecucion.h"
using namespace std;

void main()
{
	Ejecucion ejecucion;
	//Leer archivo
	//Archivo debe estar en la misma direccion que MaquinaEjecucion.cpp
	ejecucion.archivo.LeerArchivo("Ejemplo5.me");
	ejecucion.archivo.guardarmatriz();

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
		cout << "8.- Imprimir Matriz" << endl;
		cout << "9.- Salir" << endl;
		cout << "Ingrese opcion: ";
		cin >> opcion;

		switch (opcion) {
			case 1: {
				ejecucion.archivo.ImprimirArchivo();
				//cout << ejecucion.archivo.matriz[0][0]<< ejecucion.archivo.matriz[0][1] << ejecucion.archivo.matriz[0][2] << ejecucion.archivo.matriz[0][3] << ejecucion.archivo.matriz[0][4]<<endl;
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
				ejecucion.archivo.ImprimirInstruccion(ejecucion.reg[7]);
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
			case 8: {
				ejecucion.archivo.ImprimirMatriz();
				break;
			}
		}
	} while (opcion != 9);
}
