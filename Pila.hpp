#ifndef PILA_H

#define PILA_H

struct NodoPila
{
	int valor;
	NodoPila* siguiente;
};

typedef NodoPila* Pila;

Pila crearNodo(int);
void apilar(Pila&, Pila);
Pila cima(Pila);
void mostrarP(Pila);
Pila desapilar(Pila&);

#endif
