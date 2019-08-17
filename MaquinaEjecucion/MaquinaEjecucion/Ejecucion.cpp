#include "Ejecucion.h"

Ejecucion::Ejecucion() {
	Reset();
	trace = false;
}
void Ejecucion::EjecutarInstruccion() {
	if (trace) {
		archivo.ImprimirInstruccion(lineaEjecutando);
	}
	lineaEjecutando++;
}

void Ejecucion::Reset() {
	lineaEjecutando = 0;
	for (int i = 0; i < 8; i++) {
		registros[i] = 0;
	}
}

void  Ejecucion::ImprimirRegistros() {
	for (int i = 0; i < 8; i++) {
		cout << "Registro" << i <<": " << registros[i] << endl;
	}
}

void Ejecucion::EjecutarCompleto() {
	for (int i = 0; i < archivo.contadorInstrucciones; i++) {
		EjecutarInstruccion();
	}
}