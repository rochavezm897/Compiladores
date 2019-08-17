#pragma once
#include "Archivo.h"
class Ejecucion
{
	public:
		Archivo archivo;
		int registros[8];
		int lineaEjecutando;
		bool trace;
		Ejecucion();
		void EjecutarInstruccion();
		void Reset();
		void ImprimirRegistros();
		void EjecutarCompleto();
};

