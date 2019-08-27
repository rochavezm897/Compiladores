#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX_ESTADOS = 20;
class Grafo
{
public:
	string estados[MAX_ESTADOS];
	int contadorEstados;
	string estadoInicio;
	string estadosFin[MAX_ESTADOS];
	int contadorEstadosFin;
	int estadoActual;
	char matriz[MAX_ESTADOS][MAX_ESTADOS];
	Grafo();
	bool VerificarCadena(string cadena);
	bool cargarArchivo(std::ifstream fs);
	int IndiceEstado(string estado);
	string NombreIndice(int indice);
	bool VerificarFinal();
	int buscarMatriz(char caracter);
	void valoresPrueba();
};

