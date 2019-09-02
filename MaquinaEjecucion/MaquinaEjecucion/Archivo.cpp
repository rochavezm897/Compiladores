#include "Archivo.h"

Archivo::Archivo() {
	for (int i = 0; i < INSTRUCCIONES_MAXIMO; i++) {
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
	string temporal="";
	char x=0;
	while (infile) 
	{
		getline(infile, temporal);
		if (!temporal.empty())
		{
			for (int i = 0; i < temporal.length(); i++)
			{
				x = temporal.at(i);
				if (int(x)==42)
				{
					break;
				}
				else
				{
					if (int(x) == 32)
					{

					}
					else
					{
						instrucciones[contadorInstrucciones] = temporal;
						contadorInstrucciones++;
						break;
					}
				}
			}
		}
		temporal= "";
	}
	infile.close();
}


void Archivo::ImprimirInstruccion(int indice) {
	cout << instrucciones[indice] << endl;
}


void Archivo::guardarmatriz()
{
	int contador;
	int contador1;
	int tamanostring;
	string tmp;
	string tmp1;
	string tmp2;
	char x;
	bool band;
	bool band1;
	for (int i = 0; i < INSTRUCCIONES_MAXIMO; i++)
	{
		contador = 0;
		contador1 = 0;
		tmp = "";
		tmp1 = "";
		tmp2 = "";
		band = 0;
		band1 = 0;
		tamanostring = instrucciones[i].length();
		if (instrucciones[i].empty())
		{
			break;
		}
		while (tamanostring!=0)
		{
			tamanostring--;
			x = instrucciones[i].at(contador);
			if (47<int(x) && int(x)<58 && !band)
			{
				//matriz[i][0] = instrucciones[i].at(contador);
				tmp2 += x;
			}
			else 
			{
				if (64<int(x) && int(x)<91 && !band1)
				{
					tmp += x;
					band = 1;
				}
				if ((47 < int(x) && int(x)<58 && band) || (int(x) == 44 || int(x) == 40) || int(x) == 45)
				{
					band1 = 1;
					if (int(x) == 44 || int(x) == 40)
					{
						contador1 += 1;
					}
					else
					{
						switch (contador1)
						{
						case 0:
							matriz[i][2] += x;
							break;
						case 1:
							matriz[i][3] += x;
							break;
						case 2:
							matriz[i][4] += x;
							break;
						default:
							break;
						}
					}

				}
			}
			contador++;
		}
		matriz[i][0] = tmp2;
		matriz[i][1] = tmp;
	}

	CodificarMatriz();
}


void Archivo::ImprimirMatriz() {
	for (int i = 0; i < contadorInstrucciones; i++) {
		cout << matrizCodificada[i].linea << " " <<
			matrizCodificada[i].instruccion << " " <<
			matrizCodificada[i].codigo << " " <<
			matrizCodificada[i].p1 << " " <<
			matrizCodificada[i].p2 << " " <<
			matrizCodificada[i].p3 << " " <<
			endl;
	}
}


void Archivo::CodificarMatriz() {
	
	for (int i = 0; i < contadorInstrucciones; i++) {
		matrizCodificada[i].linea = stoi(matriz[i][0]);
		matrizCodificada[i].instruccion = matriz[i][1];
		matrizCodificada[i].codigo = ObtenerCodigo(i);
		matrizCodificada[i].p1 = stoi(matriz[i][2]);
		matrizCodificada[i].p2 = stoi(matriz[i][3]);
		matrizCodificada[i].p3 = stoi(matriz[i][4]);
	}
}


int Archivo::ObtenerCodigo(int indice) {
	if (!matriz[indice][1].compare("HALT")) {
		return 0;
	}
	else if(!matriz[indice][1].compare("IN")){
		return 1;
	} 
	else if (!matriz[indice][1].compare("OUT")) {
		return 2;
	}
	else if (!matriz[indice][1].compare("ADD")) {
		return 3;
	}
	else if (!matriz[indice][1].compare("SUB")) {
		return 4;
	}
	else if (!matriz[indice][1].compare("MUL")) {
		return 5;
	}
	else if (!matriz[indice][1].compare("DIV")) {
		return 6;
	}
	else if (!matriz[indice][1].compare("LD")) {
		return 7;
	}
	else if (!matriz[indice][1].compare("LDA")) {
		return 8;
	}
	else if (!matriz[indice][1].compare("LDC")) {
		return 9;
	}
	else if (!matriz[indice][1].compare("ST")) {
		return 10;
	}
	else if (!matriz[indice][1].compare("JLT")) {
		return 11;
	}
	else if (!matriz[indice][1].compare("JLE")) {
		return 12;
	}
	else if (!matriz[indice][1].compare("JGE")) {
		return 13;
	}
	else if (!matriz[indice][1].compare("JGT")) {
		return 14;
	}
	else if (!matriz[indice][1].compare("JEQ")) {
		return 15;
	}
	else if (!matriz[indice][1].compare("JNE")) {
		return 16;
	}
}