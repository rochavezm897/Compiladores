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
	int tamanostring;
	string tmp;
	string tmp1;
	string tmp2;
	char x;
	bool band;
	for (int i = 0; i < 300; i++)
	{
		contador = 0;
		contador1 = 0;
		tmp = "";
		tmp1 = "";
		tmp2 = "";
		band = 0;
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
				if (64<int(x) && int(x)<91)
				{
					tmp += x;
					band = 1;
				}
				if ((47 < int(x) && int(x)<58 && band) || (int(x) == 44 || int(x) == 40) || int(x) == 45)
				{
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


}