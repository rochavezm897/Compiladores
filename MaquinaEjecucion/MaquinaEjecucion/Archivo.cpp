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
	string temporal="";
	while (infile) 
	{
		getline(infile, temporal);
		if (!temporal.empty())
		{
			instrucciones[contadorInstrucciones] = temporal;
			contadorInstrucciones++;
		}
		temporal= "";
	}
	rop = instrucciones[0].at(0);
	infile.close();
}

void Archivo::ImprimirInstruccion(int indice) {
	cout << instrucciones[indice] << endl;
}



void Archivo::guardarmatriz()
{
	int contador;
	int contador1;
	string tmp;
	string tmp1;
	char x;
	bool band;
	for (int i = 0; i < 300; i++)
	{
		contador = 0;
		contador1 = 0;
		tmp = "";
		tmp1 = "";
		band = 0;
		if (instrucciones[i].empty())
		{
			break;
		}
		while (true)
		{

			x = instrucciones[i].at(contador);
			if (47<int(x)<59 && !band)
			{
				matriz[i][0] = instrucciones[i].at(contador);
				band = 1;
			}
			else 
			{
				if (64<int(x) && int(x)<91)
				{
					tmp += x;
				}
				if (47 < int(x) && int(x)<59 && band)
				{
					tmp1 += x;
					contador1 += 1;
					if (contador1 == 3)
					{
						break;
					}
				}
			}


			contador++;
		}
		matriz[i][1] = tmp;
		matriz[i][2] = tmp1.at(0);
		matriz[i][3] = tmp1.at(1);
		matriz[i][4] = tmp1.at(2);
	}


}