#pragma once
#include "Archivo.h"
const int NUMERO_REGISTROS = 8;
const int PC_REGISTRO = 7;
const int DATOS_MAXIMO = 50;

class Ejecucion
{
	public:
		Archivo archivo;
		int reg[NUMERO_REGISTROS];
		int datos_Memoria[DATOS_MAXIMO];
		bool trace;
		Ejecucion();
		void EjecutarInstruccion();
		void Reset();
		void ImprimirRegistros();
		void EjecutarCompleto();
		void VerMemoria();
};

