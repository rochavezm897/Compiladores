#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h> 
#include<conio.h>
using namespace std;

int i = 0;
int contadorparentesis = 0;

void recursivo(char cadena[]) {
	int leng = strlen(cadena);

	for (i; i < leng; i++)
	{
		// E->E+T, E->T, T->T * F, T->F, F->(E), F->a 
		if (cadena[0] == 'a' || cadena[0] == '(') {  //Solo puede empezar con a o (
			if (cadena[i] == 'a' || cadena[i] == '(' || cadena[i] == ')' || cadena[i] == '+' || cadena[i] == '*' || cadena[i] == '#') {
				if (cadena[i] == '(' || cadena[i] == ')' || cadena[i] == '+' || cadena[i] == '*') {
					if (((cadena[i] == '+' || cadena[i] == '*') && cadena[i + 1] == 'a') || ((cadena[i] == '+' || cadena[i] == '*') && cadena[i + 1] == '(')) {  //Despues de + o * siempre debe haber "a" o (
						i++;
						recursivo(cadena);
					}
					else if (cadena[i] == 'a' || cadena[i] == '(' || cadena[i] == ')') {
						if ((cadena[i] == '(' && cadena[i + 1] == 'a') || (cadena[i] == '(' && cadena[i + 1] == '(')) { //Despues de ( siempre debe haber "a" o mas (
							i++;
							contadorparentesis++;
							recursivo(cadena);
						}
						else if (cadena[i] == 'a' || (cadena[i - 1] == 'a' && cadena[i] == ')') || (cadena[i - 1] == ')' && cadena[i] == ')')) {  //Antes de ) siempre debe haber "a" o otro )
							if (cadena[i] == 'a') {
								i++;
								recursivo(cadena);
							}
							else if (cadena[i] == ')')
							{
								i++;
								contadorparentesis--;
								recursivo(cadena);
							}
							else {
								break;
							}
						}
						else {
							cout << "No se reconocio la cadena, debe abrir y cerrar ()" << endl;
							break;
						}
					}
					else {
						cout << "No se reconocio la cadena, despues de + o * debe haber una a o un (" << endl;
						break;
					}
				}
				else if (cadena[i] == 'a') {
					if (cadena[i] == 'a' && cadena[i + 1] == 'a') {
						cout << "No se reconocio la cadena, no puede haber dos a juntas" << endl;
						break;
					}
					else {
						i++;
						recursivo(cadena);
					}
				}
				else {
					if (contadorparentesis == 0) { //Si contador no esta en 0 significa que no se cerro algun parentesis
						cout << "Se reconocio la cadena" << endl;
						break;
					}
					else {
						cout << "No se reconocio la cadena, debe abrir y cerrar ()" << endl;
						break;
					}
				}

			}
			else {
				cout << "No se reconocio la cadena, algun caracter no pertenece" << endl;
				break;
			}
		}

		else {
			cout << "No se reconocio la cadena, debe empezar con a o (" << endl;
			break;
		}
		break;
	}
}