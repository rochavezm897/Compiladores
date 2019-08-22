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
	//string temporal="";
	while (infile) 
	{
		//getline(infile, temporal);
		//if (convertToASCII(temporal)!=1)
		//{
			//infile >> instrucciones[contadorInstrucciones];
			getline(infile, instrucciones[contadorInstrucciones]);
			
			contadorInstrucciones++;
		//}
	}
	rop = instrucciones[0].at(0);
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
		if (tmp==32)
		{
			break;
			tmp = 1;
		}
	}
	return tmp;
}