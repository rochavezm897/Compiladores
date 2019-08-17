#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Archivo
{
public:
	string instrucciones[300];
	int contadorInstrucciones;
	int siguienteInstruccion;
	ifstream infile;
	Archivo();
	void LeerArchivo(string archivo);
	void ImprimirArchivo();
	void ImprimirInstruccion(int indice);
};

