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

void ejercicio1()
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

void ejercicio2()
{
	Pila pila = NULL;
	int i = 0;

	cout << "Ingresar pila:\n";
	ingresarPila(pila);

	cout << "Pila:\n";
	mostrarP(pila);


	cout << "Estoy vago para hacer un menu, para apagar el programa usa CTRL + C (jijij)\n";
	while (true)
	{
		cout << "\nIngrese i: ";
		cin >> i;

		Pila elemento = obtenerIesimo(pila, i);
		// tener en cuenta que elemento puede ser NULL
		if(!elemento)
		{
			cout << "No existe el elemento " << i << '\n';
		}
		else
		{
			cout << "Elemento " << i << ": " << elemento->valor << '\n';
		}
	}

	// para ver si no se rompio, uyuyu
	cout << "Pila:\n";
	mostrarP(pila);
}

# Uso

Ejecuta `make run` para ejecutar el programa.
puedes cambiar el ejercicio a ejecutar modificando `main.cpp`

int main(int argc, char* argv[])
{
  ejercicio1();
  return 0;
}

// NOLINTEND
