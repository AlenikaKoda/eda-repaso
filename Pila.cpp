#include "Pila.hpp"
#include <iostream>
using namespace std;

Pila crearNodo(int val)
{
	Pila aux = new NodoPila;
	if (aux)
	{
		aux->valor = val;
		aux->siguiente = nullptr;
		return aux;
	}
	else
	{
		return nullptr;
	}
}

// 1.
// pila -> NULL
// aux[valor: ?, siguiente] -> ?

// 2.
// pila -> NULL
// aux[valor: ?, siguiente] -> NULL

// 3.
// pila
// |
// v
// aux[valor: ?, siguiente] -> NULL

void apilar(Pila& pila, Pila aux) // insertar al ppio.
{
	//2.
	aux->siguiente = pila;

	//3.
	pila = aux;
}

Pila cima(Pila pil)
{
	return (pil);
}

void mostrarP(Pila p)
{
	Pila aux;
	aux = p;
	while (aux)
	{
		cout << "\t" << aux->valor << endl;
		aux = aux->siguiente;
	}
}

// NOLINTBEGIN
Pila desapilar(Pila& p)
{
	Pila aux, dev = new NodoPila;

	// guardamos un puntero a la cima para no perderlo
	aux = p;

	// en el caso de que la pila este vacia, no podemos desapilar.
	// por lo que terminamos la ejecucion y retornamos NULL
	if (!p) // p == NULL
		return NULL;

	// dev es un nodo nuevo, no compartimos memoria.
	// debemos "mover" los datos de la cima a ese nodo
	// nuevo antes de eliminar la cima de la pila.
	// dev significa devolver
	dev->valor = p->valor;

	// movemos el puntero de la pila para que apunte al siguiente
	// de la cima actual
	// 
	// ejemplo: si teniamos p -> 3 -> 2 -> 1 -> NULL
	// ahora: p -> 2 -> 1 -> NILL
	p = p->siguiente;

	// ahora tenemos de que en nuestro ejemplo,
	// el nodo original 3 debemos eliminarlo para
	// evitar fugas de memoria
	delete (aux);

	// finalmente retornamos la copia creada de ese 3
	return dev;
}

// 

// NOLINTEND
