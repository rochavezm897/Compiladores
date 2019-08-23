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
	case 2: {

	}
	case 3: {

	}
	case 4: {

	}
	case 5: {

	}
	case 6: {

	}
	case 7: {

	}
	case 8: {

	}
	case 9: {

	}
	case 10: {

	}
	case 11: {

	}
	case 12: {

	}
	case 13: {

	}
	case 14: {

	}
	case 15: {

	}
	case 16: {

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