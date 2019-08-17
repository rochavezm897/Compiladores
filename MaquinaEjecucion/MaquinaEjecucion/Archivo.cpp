#include "Archivo.h"

Archivo::Archivo() {
	for (int i = 0; i < 100; i++) {
		instrucciones[i] = "";
	}
	contadorInstrucciones = 0;
}

bool Archivo::LeerArchivo(string archivo) {
	try {
		infile.open(archivo);
		do {
			infile >> instrucciones[contadorInstrucciones];
			contadorInstrucciones++;
		} while (infile);
		infile.close();
	}
	catch (exception e) {
		cout << "Error al leer el archivo" << endl;
		return false;
	}
	return true;
}

void Archivo::ImprimirArchivo() {
	for (int i = 0; i < contadorInstrucciones; i++) {
		cout << instrucciones[i] << endl;
	}
}