#include "Archivo.h"

Archivo::Archivo() {
	for (int i = 0; i < 300; i++) {
		instrucciones[i] = "";
	}
	contadorInstrucciones = 0;
	siguienteInstruccion = 0;
}

void Archivo::ImprimirArchivo() {
	for (int i = 0; i < contadorInstrucciones; i++) {
		cout << instrucciones[i] << endl;
	}
}

void Archivo::LeerArchivo(string archivo) {
	infile.open(archivo);
	while (infile) 
	{
		getline(infile, instrucciones[contadorInstrucciones]);
		contadorInstrucciones++;
	}
	infile.close();
}

void Archivo::ImprimirInstruccion(int indice) {
	cout << instrucciones[indice] << endl;
}