#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Archivo
{
public:
	string instrucciones[300];
	char rop = 0;
	string matriz[300][5];
	int contadorInstrucciones;
	int siguienteInstruccion;
	ifstream infile;
	Archivo();
	void LeerArchivo(string archivo);
	void ImprimirArchivo();
	void ImprimirInstruccion(int indice);
	void guardarmatriz();
	void ImprimirMatriz();
};

