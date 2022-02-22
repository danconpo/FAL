
#include <iostream>

using namespace std;


/*
DISEÑO DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de diseño realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada 
-- parámetro (en caso de que utilices una generalización), los casos base, y los 
-- casos recursivos

ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo diseñado.
-- Escribe y resuelve las ecuaciones de recurrencia.


Tamaño: d número de dígitos

	T(1) = c0;
	T(d) = c1 + T(d-1); //Porque le restamos un dígito en cada llamada

	k = 0, a = 1, b = 1
	Patrón de substracción, como a = 1, entonces T(d) € O(d^k+1) = O(d)


	Tamaño: n

	T(1) = c0;
	T(n) = c1 + T(n/10); //Porque dividimos n entre 10 en cada llamada recursiva

	k = 0, a = 1, b = 10
	Patrón de división, como a = b ^k = 1, entonces T(n) € O(n^k log n) = O(log n)

*/

void comprueba_sum_div(int n, int &suma_digs, int &num_digs, bool &es_sum_div)
{
	//Caso base
	if (n <= 9)
	{
		suma_digs = n;
		num_digs = 1;
		//todos los numeros de 1 digitos son sum_div
		es_sum_div = true;
	}

	else
	{
		comprueba_sum_div(n / 10, suma_digs, num_digs, es_sum_div);

		suma_digs = suma_digs + n % 10;
		num_digs++;

		es_sum_div = es_sum_div && (suma_digs % num_digs == 0);
	}
}

bool sumdivisible(int n) {
	/* IMPLEMENTACION:
	   Esta función será el punto de entrada a tu algoritmo.
	   Puedes implementar, además, las funciones auxiliares
	   que consideres oportuno.
	   -- n: El número cuya sumdivisibilidad debes determinar.
	   -- La función deberá devolver 'true' si n es sumdivisible,
	   -- y 'false' en otro caso
	*/

	bool es_sum_div;
	int num_digs, sum_digs;
	comprueba_sum_div(n, sum_digs, num_digs, es_sum_div);

	return es_sum_div;
}   


/* CODIGO DE LECTURA Y EJECUCION DE CASOS DE PRUEBA: 
   NO MODIFICAR */

int main() {
	int n;
	do {
		cin >> n;
		if (n > 0) {
			if (sumdivisible(n)) 
				 cout << "SI" << endl;
			else 
                 cout << "NO" << endl;				
		}
	} while (n > 0);
}
	
	