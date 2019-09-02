#include "Grafo.h"

Grafo::Grafo() {
	int i, j;
	for (i = 0; i < MAX_ESTADOS; i++)
	{
		for (j = 0; j < MAX_ESTADOS; j++)
		{
			matrizTransicion[i][j] = -1;
		}
	}
}

bool Grafo::cargarArchivo(string ubicacionFichero) {
	//ABRIMOS EL ARCHIVO
	fichero.open(ubicacionFichero);
	//VARIABLES TEMPORALES Y CONTROL
	int indiceClaves[5];
	string arrClaves[5] = { "K", "VT", "S", "Z", "M" };
	string temp[300];
	objTransiciones tempMatriz;

	bool nada;

	//Variables contadoras
	bool llenarArreglo = false;
	int contadorClaves = 0;
	int contadorIndice = 0;
	int i = 0;
	int lenFichero = 0;

	//LLENAMOS TEMP CON TODO LO QUE ESTE SEPARADO POR ESPACIOS
	try
	{
		do {
			fichero >> temp[lenFichero];
			if (temp[lenFichero] == "")
				break;
			lenFichero++;
		}while (fichero);

		//CERRAMOS EL ARCHIVO
		fichero.close();

		//CONTAMOS PARA ENCONTRAR LA UBICACI[ON DE LAS CLAVES EN EL ARCHIVO
		while (i < lenFichero) {
			if (temp[i] == arrClaves[contadorIndice])
			{
				indiceClaves[contadorIndice] = i;
				contadorIndice++;
			}
			i++;
		}

		i = 0;
		contadorIndice = 0;

		//LLENAMOS CADA CLAVE CON SUS ELEMENTOS
		do {

			if (indiceClaves[0] < i && i < indiceClaves[1]) {
				//LLENAMOS ESTADOS
				Estados.push_back(temp[i]);
			}
			else if (indiceClaves[1] < i && i < indiceClaves[2]) {
				//LLENAMOS VOCABULARIO
				Vocabulario.push_back(temp[i][0]);
			}
			else if (indiceClaves[2] < i && i < indiceClaves[3]) {
				//LLENAMOS ESTADO INICIAL
				//SIEMPRE ASUMIMNOS QUE SOLO HAY UN ESTADO INICIAL
				EstadoInicial = temp[i];
			}
			else if (indiceClaves[3] < i && i < indiceClaves[4]) {
				//LLENAMOS ESTADO FINAL
				EstadosFinal.push_back(temp[i]);
			}
			else if (indiceClaves[4] < i) {
				//LLENAMOS TRANSICIONES
				tempMatriz.origen = temp[i];
				tempMatriz.destino = temp[i + 1];
				tempMatriz.transicion = temp[i + 2];
				Transiciones.push_back(tempMatriz);
				i += 2;
			}
			i++;
		} while (i < lenFichero);

		contEstados = Estados.size();
		contVocabulario = Vocabulario.size();
		contEstadosFinales = EstadosFinal.size();
		contTransiciones = Transiciones.size();

		construirMatrizTrans();

		return true;
	}
	catch (const std::exception&)
	{
		cout << "Error al cargar el archivo" << endl;
		return false;
	}
	
}

bool Grafo::construirMatrizTrans() {
	int i = 0;
	int j = 0;

	//Llenamos matriz de transicion
	for (i = 0; i < contTransiciones; i++) {
		matrizTransicion[getIndiceEstados(Transiciones[i].origen)][getIndiceEstados(Transiciones[i].destino)]
			= getIndiceVocabulario(Transiciones[i].transicion[0]);
	}

	return true;
}

int Grafo::getIndiceEstados(string nombreEstado) {
	for (int i = 0; i < contEstados; i++)
	{
		if (Estados[i] == nombreEstado)
			return i;
	}
}


int Grafo::getIndiceVocabulario(char nombreVocabulario) {
	for (int i = 0; i < contVocabulario; i++)
	{
		if (Vocabulario[i] == nombreVocabulario)
			return i;
	}
}

bool Grafo::VerificarCadena(string cadena) {
	estadoActual = getIndiceEstados(EstadoInicial);
	for (int i = 0; i < cadena.length(); i++) {
		estadoActual = buscarMatriz(getIndiceVocabulario(cadena[i]));
		if (estadoActual == -1) {
			return false;
		}
	}

	if (VerificarFinal()) {
		return true;
	}
	return false;
}

bool Grafo::VerificarFinal() {
	for (int i = 0; i < contEstadosFinales; i++) {
		if (EstadosFinal[i] == Estados[estadoActual])
			return true;
	}
	return false;
}

int Grafo::buscarMatriz(char caracter) {
	for (int i = 0; i < contEstados; i++) {
		if (matrizTransicion[estadoActual][i] == caracter) {
			return i;
		}
	}
	return -1;
}
