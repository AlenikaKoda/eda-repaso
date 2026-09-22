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

Pila obtenerIesimo(Pila& p, int i)
{
	// Como la funcion devuelve un puntero (Pila), si no encontramos el valor
	// o la pila esta vacia devolvemos NULL. 
	// (Si devolviera un int, podriamos devolver -1, depende de la letra).

	// Para poder movernos por la pila hay que ir desapilando.
	// Para no perder los nodos que sacamos, los guardamos en un auxiliar.
	
	// NOTITA :3
	// Aca habia que tener cuidado. Casi pongo un 'return' directo si la pila 
	// quedaba vacia despues de buscar el elemento, pero la pila hubiera quedado desarmada.
	// El tema es que tenemos que armarla de vuelta siempre (encuentre o no el elemento).
	// Por eso, mas abajo evaluamos si NO quedo vacia para guardar el resultado, 
	// y luego armamos todo de nuevo tranquilamente.

	// BASICAMENTE (para i = 3, desapilamos 2 veces)
	// 
	// p: 10 20 30 40 50
	// x: 
	// 
	// p: 20 30 40 50
	// x: 10
	//
	// p: 30 40 50
	// x: 20 10
	// 
	// resultado = 30 (cima de p)
	// 
	// p: 20 30 40 50
	// x: 10
	// 
	// p: 10 20 30 40 50
	// x:
	// 
	// retornar: 30 (como un nodo nuevo)

	Pila auxPila = NULL;
	Pila resultado = NULL;

	// En nuestro caso el indice buscado comienza en 1 (la cima es el elemento 1).
	// Si nos piden un indice invalido (<= 0) o la pila ya viene vacia, 
	// ni nos gastamos y devolvemos NULL directo.
	if (i <= 0 || !p)
	{
		return NULL;
	}

	// Usaremos un contador empezando en 0 para saber cuantas veces vamos desapilando.
	int contador = 0; 

	// Como funciona la condicion del contador y el indice?
	// La intencion es que al terminar el bucle, el elemento buscado quede en la cima.
	// Para llegar al elemento 'i', debemos quitar los que estan arriba de el.
	// Es decir, necesitamos desapilar exactamente (i - 1) elementos.
	//
	// Ejemplo 1: queremos la cima (i = 1).
	// Tenemos que desapilar (1 - 1) = 0 veces. 
	// Como el contador arranca en 0, la condicion "0 < 0" da FALSO y no desapila nada. ¡Perfecto!
	//
	// Ejemplo 2: queremos el 3er elemento (i = 3).
	// Tenemos que desapilar (3 - 1) = 2 veces.
	// El bucle corre con contador=0 y luego contador=1. Al llegar a 2, "2 < 2" da FALSO y frena.
	while (p && contador < (i - 1))
	{
		// desapilamos p en auxPila para no perder el nodo
		apilar(auxPila, desapilar(p));

		// indicamos que ya hemos desapilado un nodo sumando 1 al contador
		contador++;
	}

	// Ahora la pila tiene el resultado en la cima O quedo vacia (si i > longitud de la pila)
	resultado = NULL;

	// Si la pila no quedo vacia, entonces la cima contiene el resultado buscado
	if (p)
	{
		// Resulta que no debemos compartir memoria ni devolver el nodo original
		// para no romper la estructura externa, asi que guardamos una copia de la cima.
		resultado = crearNodo(cima(p)->valor);
	}

	// Ahora tenemos que re-armar la pila original.
	// Recuperamos los nodos que habiamos guardado en el auxiliar
	while (auxPila)
	{
		apilar(p, desapilar(auxPila));
	}

	// devolvemos la copia del nodo resultado (o NULL si no se encontro)
	return resultado;
}

// NOLINTEND
