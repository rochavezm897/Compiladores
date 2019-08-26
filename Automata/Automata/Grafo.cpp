#include "Grafo.h"

Grafo::Grafo() {
	estadoInicio = "";
	contadorEstados = 0;
	contadorEstadosFin = 0;
	for (int i = 0; i < MAX_ESTADOS; i++) {
		estados[i] = -1;
		estadosFin[i] = -1;
		for (int j = 0; j < MAX_ESTADOS; j++) {
			matriz[i][j] = -1;
		}
	}
}

bool Grafo::VerificarCadena(string cadena) {
	estadoActual = IndiceEstado(estadoInicio);
	for (int i = 0; i < cadena.length(); i++) {
		estadoActual = buscarMatriz(cadena[i]);
		if (estadoActual == -1) {
			return false;
		}
	}
	if (VerificarFinal()) {
		return true;
	}
	return false;
}
int Grafo::IndiceEstado(string estado) {
	for (int i = 0; i < contadorEstados; i++) {
		if (estados[i].compare(estado) == 0) {
			return i;
		}
	}
	return -1;
}
string Grafo::NombreIndice(int indice) {
	return estados[indice];
}

bool Grafo::VerificarFinal() {
	string temp = NombreIndice(estadoActual);
	for (int i = 0; i < contadorEstadosFin; i++) {
		if (estadosFin[i].compare(temp) == 0) {
			return true;
		}
	}
	return false;
}

int Grafo::buscarMatriz(char caracter) {
	for (int i = 0; i < contadorEstados; i++) {
		if (matriz[estadoActual][i] == caracter) {
			return i;
		}
	}
	return -1;
}

void Grafo::valoresPrueba() {
	contadorEstados = 5;
	contadorEstadosFin = 3;
	estadoInicio = "A";
	estados[0] = "A";
	estados[1] = "B";
	estados[2] = "C";
	estados[3] = "D";
	estados[4] = "E";
	estadosFin[0] = "B";
	estadosFin[1] = "C";
	estadosFin[2] = "E";
	matriz[0][1] = '0';
	matriz[1][2] = '1';
	matriz[1][3] = '2';
	matriz[2][2] = '1';
	matriz[2][3] = '2';
	matriz[3][4] = '3';
	matriz[4][2] = '1';
	matriz[4][3] = '2';

}