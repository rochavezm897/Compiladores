#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
const int MAX_ESTADOS = 15;

struct objTransiciones {
	string origen;
	string destino;
	string transicion;
};

class Grafo
{
public:
	ifstream fichero;

	vector<string> Estados;
	vector<char> Vocabulario;
	vector<string> EstadosFinal;
	string EstadoInicial;
	vector<objTransiciones> Transiciones;
	int matrizTransicion[MAX_ESTADOS][MAX_ESTADOS];

	int contEstados = 0;
	int contVocabulario = 0;
	int contEstadosFinales = 0;
	int contTransiciones = 0;

	int estadoActual;
	
	Grafo();
	bool cargarArchivo(string ubicacionFichero);
	bool VerificarCadena(string cadena);
	bool construirMatrizTrans();
	int getIndiceEstados(string nombreEstado);
	int getIndiceVocabulario(char nombreVocabulario);
	bool VerificarFinal();
	int buscarMatriz(char caracter);
};

