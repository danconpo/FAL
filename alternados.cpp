#include <iostream>
using namespace std;


typedef unsigned long long t_num;


/*
DISEÑO DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de diseño realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada 
-- parámetro (en caso de que utilices una generalización), los casos base, y los 
-- casos recursivos

ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo diseñado.
-- Escribe y resuelve las ecuaciones de recurrencia.


Tomando n como un digito
	T(1)= C0
	T(d) = C0 + T(d-1);

	Al ser un dígito, es una substracción, porque le vas restando a n, un dígito cada vez
	a = 1, b = 1, k = 0;

	T(d) € O(d^(k+1)) = O(d^1) = O(d)


Tomando el tamaño como n

	T(0)= C0
	T(d) = C0 + T(n/10);

	a = 1, b = 10, k = 0, ya que no existe término w(n)
	Entonces b ^k = 1;
	Como a = b = 1, entonces T(n) € O(n^k log n) = O(n ^0*log n) = O(log n);

*/



void comprueba_alternados(t_num n, t_num &c, int &digito_ant, bool &es_alternado)
{

	if (n <= 9)
	{
		//Todos los numeros de un digito se cuentan como alternados
		c = n;
		es_alternado = true;
		digito_ant = n;
	}

	else
	{
		comprueba_alternados(n / 10, c, digito_ant, es_alternado);

		//Los de la forma < n/10

		//Cada decena tiene 5 numeros que son alternados (que cumplen que sean par-impar, impar-par)
		c = 5 * c; 
		//Como con el 0 formara 5 numeros par-impar, le tengo que sumar los otros 5 aparte,
		//pues los numeros de 1 digito son todos alternados, pero como los hago a partir del 0
		//hay que contarlos aparte
		c = 5 + c;

		//Los de la forma n/10

		if (es_alternado)
		{
			if (digito_ant % 2 != 0)
				c = c + (n % 10 + 1) / 2;
			else
				c = c + (n % 10) / 2;
		}
		//Sera alternado  si las paridades del digito anterior y el ultimo digito NO coinciden 
		es_alternado = es_alternado && (digito_ant % 2 != (n % 10) % 2);
		digito_ant = n % 10;
	}
}



t_num num_alternados(t_num n) {
	// PUNTO ENTRADA AL ALGORITMO

	t_num c;
	int digito_ant;
	bool es_alternado;

	comprueba_alternados(n, c, digito_ant, es_alternado);

	return c;
}

bool procesa_caso() {
	long long n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		cout << num_alternados((t_num)n) << endl;
		return true;
	}

}

int main() {
    while (procesa_caso());

}