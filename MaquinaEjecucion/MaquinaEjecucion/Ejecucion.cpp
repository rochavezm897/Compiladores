#include "Ejecucion.h"

Ejecucion::Ejecucion() {
	Reset();
	trace = false;
}

void Ejecucion::EjecutarInstruccion() {
	int a = archivo.matrizCodificada[reg[7]].p2 + reg[archivo.matrizCodificada[reg[7]].p3];
	if (trace) {
		archivo.ImprimirInstruccion(reg[7]);
	}
	switch (archivo.matrizCodificada[reg[7]].codigo) {

	//Instrucciones Tipo Operacion 0-6
	case 0: {//HALT
		system("pause");
		break;
	}
	case 1: {//IN
		cout << "Ingresar valor: ";
		cin >> reg[archivo.matrizCodificada[reg[7]].p1];
		cout << "Guardado"<< endl;
		break;
	}
	case 2: {//OUT
		cout<< reg[archivo.matrizCodificada[reg[7]].p1]<<endl;
		break;
	}
	case 3: {//ADD
		reg[archivo.matrizCodificada[reg[7]].p1] = reg[archivo.matrizCodificada[reg[7]].p2] + reg[archivo.matrizCodificada[reg[7]].p3];
		break;
	}
	case 4: {//SUB
		reg[archivo.matrizCodificada[reg[7]].p1] = reg[archivo.matrizCodificada[reg[7]].p2] - reg[archivo.matrizCodificada[reg[7]].p3];
		break;
	}
	case 5: {//MUL
		reg[archivo.matrizCodificada[reg[7]].p1] = reg[archivo.matrizCodificada[reg[7]].p2] * reg[archivo.matrizCodificada[reg[7]].p3];
		break;
	}
	case 6: {//DIV
		if(reg[archivo.matrizCodificada[reg[7]].p3] == 0){
			cout << "Error: Dividio entre 0" << endl;
			break;
		}
		else{
			reg[archivo.matrizCodificada[reg[7]].p1] = reg[archivo.matrizCodificada[reg[7]].p2] / reg[archivo.matrizCodificada[reg[7]].p3];
			break;
		}
	}
	
	//Instrucciones Tipo Memoria 7-16
	
		/*if (a>6)
		{
			cout << "Error: No esta en los limites" << endl;
		}
		else {*/
			case 7: {//LD 
				if (a < 0 || a>50)
				{
					break;
				}
				else {
					reg[archivo.matrizCodificada[reg[7]].p1] = datos_Memoria[a];
					break;
				}
			}
			case 8: {//LDA 
				int aux = a;
				if (archivo.matrizCodificada[reg[7]].p1 == 7) {
					aux = aux - 1;
				}
				reg[archivo.matrizCodificada[reg[7]].p1] = aux;
				break;
			}
			case 9: {//LDC
				reg[archivo.matrizCodificada[reg[7]].p1] = archivo.matrizCodificada[reg[7]].p2;
				break;
			}
			case 10: {//ST 
				if (a < 0 || a>50)
				{
					break;
				}
				else {
					datos_Memoria[a]= reg[archivo.matrizCodificada[reg[7]].p1];
					break;
				}

			}
			case 11: {//JLT 
				if (reg[archivo.matrizCodificada[reg[7]].p1] < 0) {
					reg[7] = a - 1;
				}
				else {
					break;
				}
				break;
			}
			case 12: {//JLE
				if (reg[archivo.matrizCodificada[reg[7]].p1] <= 0) {
					reg[7] = a - 1;
				}
				else {
					break;
				}
				break;
			}
			case 13: {//JGE
				if (reg[archivo.matrizCodificada[reg[7]].p1] >= 0) {
					reg[7] = a - 1;
				}
				else {
					break;
				}
				break;
			}
			case 14: {//JGT
				if (reg[archivo.matrizCodificada[reg[7]].p1] > 0) {
					reg[7] = a - 1;
				}
				else {
					break;
				}
				break;
			}
			case 15: {//JEQ
				if (reg[archivo.matrizCodificada[reg[7]].p1] == 0) {
					reg[7] = a - 1;
				}
				else {
					break;
				}
				break;
			}
			case 16: {//JNE
				if (reg[archivo.matrizCodificada[reg[7]].p1] != 0) {
					reg[7] = a - 1;
				}
				else {
					break;
				}
				break;
			}
		//}

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
	/*for (int i = 0; i < archivo.contadorInstrucciones; i++) {
		EjecutarInstruccion();
	}*/
	while (reg[7] < archivo.contadorInstrucciones) {
		EjecutarInstruccion();
	}
}

void Ejecucion::VerMemoria() {
	for (int i = 0; i < DATOS_MAXIMO; i= i+5) {
		cout << datos_Memoria[i] << " " << datos_Memoria[i + 1] << " " << datos_Memoria[i + 2] << " " << datos_Memoria[i + 3] << " " << datos_Memoria[i + 4] << endl;
	}
}