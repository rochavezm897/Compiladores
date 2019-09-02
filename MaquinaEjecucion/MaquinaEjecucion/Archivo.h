#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int INSTRUCCIONES_MAXIMO = 100;

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
	string instrucciones[INSTRUCCIONES_MAXIMO];
	string matriz[INSTRUCCIONES_MAXIMO][5];
	int contadorInstrucciones;
	int siguienteInstruccion;
	ifstream infile;
	MatrizCodigo matrizCodificada[INSTRUCCIONES_MAXIMO];
	Archivo();
	void LeerArchivo(string archivo);
	void ImprimirArchivo();
	void ImprimirInstruccion(int indice);
	void guardarmatriz();
	void ImprimirMatriz();
	void CodificarMatriz();
	int ObtenerCodigo(int indice);
};


