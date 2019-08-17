#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Archivo
{
public:
	string instrucciones[100];
	int contadorInstrucciones;
	ifstream infile;
	Archivo();
	bool LeerArchivo(string archivo);
	void ImprimirArchivo();
};

