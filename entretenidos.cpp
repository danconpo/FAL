#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef unsigned long long t_num;

// Si se comenta, el programa se ejecuta en modo de autocomprobación.
#define DOM_JUDGE

/*
DISEÑO DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de diseño realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada 
-- parámetro (en caso de que utilices una generalización), los casos base, y los 
-- casos recursivos

ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo diseñado.
-- Escribe y resuelve las ecuaciones de recurrencia.


	Si el tamaño escogido es el número de dígitos d:
	T(1) = c0;
	T(d) = c1 + T(d-1);

	a = 1, b = 1, k = 0
	Patrón por substracción: Como a = 1, T(d) € O(d*k+1) = O(d)
	------------------------------
	------------------------------
	Si el tamaño escogido es el n:
	T(1) = c0;
	T(n) = c1 + T(n/10);

	a = 1, b = 10, k = 0
	Patrón por división: Como a = b^k = 1, T(n) € O(n^k log n) = O(log n)

*/

void comprueba_entretenidos(t_num n, t_num &c,int &dig_ant, bool &es_entretenido)
{
	//Hacemos la funcion para contar los numeros entretenidos < n, y despues le sumaremos uno

	//caso base 
	if (n <= 9)
	{
		c = n;
		dig_ant = n;
		//Todos los numeros de un digito son entretenidos
		es_entretenido = true;
	}

	else
	{

		comprueba_entretenidos(n / 10, c, dig_ant, es_entretenido);

		//Todos los que son de la forma  < n/10
		//Con cada numero < n/10 puedo formar u d con d variando entre 0 y 9, a excepcion del digito repetido
		c = c * 9;

		//Sumamos el 0 a parte, ya que el 00 no se puede formar por tener 2 digitios repetidos
		c++;

		//Todos los que son de la forma = n/10

		if (es_entretenido)
		{
			if (n % 10 > dig_ant)
				c = c + (n % 10) - 1;
			else 
				c = c + (n % 10);
		}

		es_entretenido = es_entretenido && (n % 10 != dig_ant);

		//Actualizamos el nuevo digito del que partiremos
		dig_ant = n % 10;
	}
}

t_num num_entretenidos(t_num n) {
	// PUNTO DE ENTRADA AL ALGORITMO.

	t_num c;
	int dig_ant;
	bool es_entretenido;

	comprueba_entretenidos(n, c, dig_ant, es_entretenido);

	//Si el numero es entretenido, como nos piden todos los entretenidos que son <= n, le tenemos que sumar 1

	if (es_entretenido) 
		c++;

	return c;


	
}


#ifndef DOM_JUDGE
/* Implementación naif */

bool es_entretenido(t_num n) {
	bool resul = true;
	while (n >= 10 && resul) {
		unsigned short d = n % 10;
		n = n / 10;
		if (d == n%10) {
		  resul = false;	
		}
	}
	return resul;
}

t_num num_entretenidos_naif(t_num n) {
	t_num num = 0;
	for (t_num i = 0; i <= n; i++) {
		if (es_entretenido(i)) num++;
	}
	return num;
}

const int NUM_PRUEBAS = 1000;

#endif


#ifdef DOM_JUDGE

bool ejecuta_caso() {
	long long n;
	cin >> n;
	if (n == -1) {
	  return false;	
	}
	else {
		cout << num_entretenidos((t_num)n) << endl;
		return true;
	}
}

#endif


int main() {
	#ifndef DOM_JUDGE
	srand(time(NULL));
	int i = 0;
	bool ok = true;
	while ((i < NUM_PRUEBAS) && ok) {
		int n = rand();
		if (num_entretenidos_naif(n) != num_entretenidos(n)) {
			ok = false;
			cout << "NO FUNCIONA PARA " << n <<": " << num_entretenidos_naif(n) << "..." << num_entretenidos(n) << endl;
		}
		i++;
	}
	if (ok) {
		cout << "OK. CONTRAEJEMPLO NO ENCONTRADO!" << endl;
	}
	system("pause");
	#endif
	#ifdef DOM_JUDGE
	while(ejecuta_caso()); 
	#endif 
	
}