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
	string temporal;
	while (infile) 
	{
		getline(infile, temporal);
		if (convertToASCII(temporal)<0)
		{
			getline(infile, instrucciones[contadorInstrucciones]);
		}
		contadorInstrucciones++;
	}
	infile.close();
}

void Archivo::ImprimirInstruccion(int indice) {
	cout << instrucciones[indice] << endl;
}

int Archivo::convertToASCII(string letter)
{
	int tmp=0;
	for (int i = 0; i < letter.length(); i++)
	{
		char x = letter.at(i);
		tmp += int(x);
	}
	return tmp;
}