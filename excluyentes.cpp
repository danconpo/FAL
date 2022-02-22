#include <iostream>

// Si se comenta esta definici�n, el programa
// autocomprobar� su funcionamiento comparando
// la implementaci�n realizada con una 
// implementaci�n 'naif' del algoritmo
#define DOM_JUDGE

#ifndef DOM_JUDGE
#include <ctime>
#include <stdlib.h>
#endif 

using namespace std;


/*
DISE�O DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de dise�o realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada
-- par�metro (en caso de que utilices una generalizaci�n), los casos base, y los
-- casos recursivos

ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo dise�ado.
-- Escribe y resuelve las ecuaciones de recurrencia.

	Si el tama�o escogido es el n�mero de d�gitos d:
	T(1) = c0;
	T(d) = c1 + T(d-1);

	a = 1, b = 1, k = 0
	Patr�n por substracci�n: Como a = 1, T(d) � O(d*k+1) = O(d)
	------------------------------
	------------------------------
	Si el tama�o escogido es el n:
	T(1) = c0;
	T(n) = c1 + T(n/10);

	a = 1, b = 10, k = 0
	Patr�n por divisi�n: Como a = b^k = 1, T(n) � O(n^k log n) = O(log n)

*/
typedef long long tnum;


void comprueba_sind(tnum n, unsigned short d, tnum &c, bool &sin_d)
{
	if (n <= 9) 
	{
		if (n <= d)
			c = n;
		else
			c = n - 1; //Quitamos el digito que coincide con d

		//Solamente se sabe si contiene dicho d�gito si el n�mero que te dan es igual a d
		sin_d = (d == n);
	}
	else
	{
	
		comprueba_sind(n / 10, d, c, sin_d);

		//El 0 hay que a�adirlo expl�citamente antes de empezar a contar, o se podr�a a�adir despu�s con el c = c + 9 
		// Ya que con el 0, no se podr�an hacer los 9 primeros, pero los podemos contar despu�s
		/*if (d == 0)
			c++;
		*/

		c *= 9; //Ya que a cada numero < n/10 le puedo a�adir 10 digitos pero uno de ellos siempre ser� d

		//Con esta l�nea funciona igual que a�adir el 0 antes de contear
		//simplemente a�adimos los 9 primeros que se forman con el 0 
		if (d == 0)
			c = c + 9;

		if (!sin_d)
		{
			if (d < n % 10)
				c = c + (n % 10) - 1;
			else
				c = c + (n % 10);
		}

		//Es una or!!!
		//no tendr� d cuando no haya d � cuando el �ltimo digito sea d
		sin_d = sin_d || (n % 10) == d;
	}
}

tnum num_sin_digito_menoresque(tnum n, unsigned short d) {
	// PUNTO DE ENTRADA AL ALGORITMO

	tnum c;
	bool sin_d;

	comprueba_sind(n, d, c, sin_d);

	return c;
}


#ifndef DOM_JUDGE
bool contiene_digito(t_num n, unsigned short d) {
	if (n == 0) {
		return d == 0;
	}
	else {
		bool lo_contiene = false;
		while (n > 0 && !lo_contiene) {
			lo_contiene = (n % 10 == d);
			n = n / 10;
		}
		return lo_contiene;
	}
}

t_num num_sin_digito_menoresque_naif(t_num n, unsigned short d) {
	t_num num = 0;
	for (t_num i = 0; i < n; i++) {
		if (!contiene_digito(i, d)) {
			num++;
		}
	}
	return num;
}
#endif

#ifdef DOM_JUDGE
bool ejecuta_caso() {
	tnum n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		unsigned short d;
		cin >> d;
		cout << num_sin_digito_menoresque(n, d) << endl;
		return true;
	}
}
#endif

int main() {

#ifndef DOM_JUDGE
	bool ok = true;
	srand(time(NULL));
	int i = 0;
	while (i < 1000 && ok) {
		t_num  n = (t_num)rand();
		unsigned short d = (unsigned short)(rand() % 10);
		if (num_sin_digito_menoresque_naif(n, d) != num_sin_digito_menoresque(n, d)) {
			cout << "NO FUNCIONA" << endl;
			cout << n << " " << d << ":" << num_sin_digito_menoresque_naif(n, d) << "..." << num_sin_digito_menoresque(n, d) << endl;
			ok = false;
		}
		i++;
	}
	if (ok) cout << "OK" << endl;
	system("pause");
#endif

#ifdef DOM_JUDGE
	while (ejecuta_caso());
#endif
}
