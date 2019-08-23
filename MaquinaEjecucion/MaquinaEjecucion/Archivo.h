#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct MatrizCodigo
{
	int linea;
	string instruccion;
	int codigo;
	int p1;
	int p2;
	int p3;
};
class Archivo
{
public:
	string instrucciones[300];
	char rop = 0;
	string matriz[300][5];
	int contadorInstrucciones;
	int siguienteInstruccion;
	ifstream infile;
	MatrizCodigo matrizCodificada[300];
	Archivo();
	void LeerArchivo(string archivo);
	void ImprimirArchivo();
	void ImprimirInstruccion(int indice);
	void guardarmatriz();
	void ImprimirMatriz();
	void CodificarMatriz();
	int ObtenerCodigo(int indice);
};


