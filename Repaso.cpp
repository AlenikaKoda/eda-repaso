#include "Repaso.hpp"

#include <iostream> // nosotros lo usamos para NULL en estos casos
#include "Pila.hpp"

// NOLINTBEGIN

/*
[Parcial de 2018]
Dadas dos pilas de elementos enteros ordenadas, realizar un procedimiento que cree una tercera pila
ordenada también. Las pilas originales deberán quedar vacías.
void terceraPila (Pila &pil1, Pila &pil2, Pila &pil3);
*/

// pil1 y pil2 ya estan ordenadas (menor a mayor)
//
// Ejemplo:
//
//    cima
//       v
// pil1: 1 3 5 17 20
// pil2: 2 4 9
//
// deberiamos tener:
// pil3: 1 2 3 4 5 9 17 20

// NOTITA :3
// Si la cima contiene el MENOR, comparamos pil1 <= pil2
// Si la cima contiene el MAYOR, comparamos pil1 >= pil2

void terceraPila(Pila& pil1, Pila& pil2, Pila& pil3)
{
	// sabiendo que pil1 y pil2 ya estan ordenadas
	// [en este caso] consideramos que la cima contiene el
	// MENOR.




	Pila aux = NULL; // el auxiliar, contiene el resultado invertido

	// 1)
	// Si las 2 pilas aun contienen nodos
	// tendremos que verificar cual de la cima es menor y
	// las agregaremos a una pila
	while (pil1 && pil2)
	{
		// cima(pil1) es menor (o igual) a cima(pil2)
		// debemos mover cima(pil1) al resultado
		// con mover me refiero a desapilar y apliar en otra pila
		//
		// el problema es que al ir apilando guardariamos en orden
		// inverso, por lo que habria que apilar en un auxiliar
		// y luego invertirla en `pil3`
		if (cima(pil1)->valor <= cima(pil2)->valor)
		{
			apilar(aux, desapilar(pil1));
		}
		// en este caso movemos cima(pil2)
		else
		{
			apilar(aux, desapilar(pil2));
		}
	}

	// 2)
	// ahora, en el caso de que `pil1` y `pil2` tengan diferentes
	// cantidades de elementos, no podremos comparar las cimas.
	// por lo que tendremos que apilar lo que queda directamente
	// sin preguntar.
	//
	// que sean de tamano diferente quiere decir que 
	// en algun punto se cumple que: (pil1 && !pil2) o (!pil1 && pil2)
	// originados por desapilar, (o bien una de las pilas llego vacia)

	// apilamos lo que nos queda de pil1, sabemos que pil2 esta vacia
	// por lo que a pil1 solo le quedan elementos mayores a los que pil2 tenia.
	while (pil1)
	{
		apilar(aux, desapilar(pil1));
	}

	// apilamos lo que nos queda de pil2, sabemos que pil1 esta vacia
	// por lo que a pil2 solo le quedan elementos mayores a los que pil1 tenia.
	while (pil2)
	{
		apilar(aux, desapilar(pil2));
	}

	
	// 3)
	// finalmente para recuperar el orden desapilamos el auxiliar
	// y lo apilamos en la salida `pil3`
	while (aux)
	{
		apilar(pil3, desapilar(aux));
	}
}

// NOLINTEND
