// NOLINTBEGIN
#include <cstring> // esto es para mi menu, en clase no lo dimos :c
#include <iostream>
#include "Pila.hpp"
#include "Repaso.hpp"
using namespace std;

void ingresarPila(Pila& pila)
{
	char entradaLiteral[100];
	int entradaNumerica;
	
	while (true)
	{
		cout << "> ";
		cin >> entradaLiteral;
		if (strcmp(entradaLiteral, "x") == 0)
			break;

		entradaNumerica = atoi(entradaLiteral);
		apilar(pila, crearNodo(entradaNumerica));
	}
}

int main()
{
	Pila pila1 = NULL;
	Pila pila2 = NULL;
	Pila pila3 = NULL;

	cout << "Ingresar pila 1:\n";
	ingresarPila(pila1);

	cout << "Ingresar pila 2:\n";
	ingresarPila(pila2);

	cout << "Pila 1:\n";
	mostrarP(pila1);
	cout << "\n";

	cout << "Pila 2:\n";
	mostrarP(pila2);
	cout << "\n";

	terceraPila(pila1, pila2, pila3);

	cout << "Pila 3:\n";
	mostrarP(pila3);
	cout << "\n";
}

// NOLINTEND
