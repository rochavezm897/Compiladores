#include "Ejecucion.h"

Ejecucion::Ejecucion() {
	Reset();
	trace = false;
}
void Ejecucion::EjecutarInstruccion() {
	if (trace) {
		archivo.ImprimirInstruccion(reg[7]);
	}
	switch (archivo.matrizCodificada[reg[7]].codigo) {
	case 0: {
		system("pause");
		break;
	}
	case 1: {
		cout << "Ingresar valor: ";
		cin >> reg[archivo.matrizCodificada[reg[7]].p1];
		cout << "Guardado"<< endl;
	}
	}
	reg[7]++;
}

void Ejecucion::Reset() {
	for (int i = 0; i < NUMERO_REGISTROS; i++) {
		reg[i] = 0;
	}
}

void  Ejecucion::ImprimirRegistros() {
	for (int i = 0; i < NUMERO_REGISTROS; i++) {
		cout << "Registro" << i <<": " << reg[i] << endl;
	}
}

void Ejecucion::EjecutarCompleto() {
	for (int i = 0; i < archivo.contadorInstrucciones; i++) {
		EjecutarInstruccion();
	}
}