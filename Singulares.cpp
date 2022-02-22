#include <iostream>

// Si se comenta esta definición, el programa
// autocomprobará su funcionamiento comparando
// la implementación realizada con una 
// implementación 'naif' del algoritmo
#define DOM_JUDGE

#ifndef DOM_JUDGE
#include <ctime>
#include <stdlib.h>
#endif 

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

	Podemos determinar dos ecuaciones en funcion de el tamaño que escojamos

	-Si el tamaño del problema es d, como numero de digitos d de n
	
	T(1) = c0
	T(d) = c1+ T(d-1)
	Patron por substraccion:

	a = 1, b = 1, k = 0
	como a = 1, Entonces T(d) € O(d^k+1) = O(d)


	-Si el tamaño del problema es n

	T(1) = c0
	T(n) = c1 + T(n/10)
	Patrom por division 

	a = 1, b = 10, k = 0

	como a = b^k = 1, entonces T(n) € O(n^k log n) = O(log n)







*/

void comprueba_singul(t_num n, t_num &c, t_num &primer_dig, bool &es_singular)
{
	//caso base 
	if (n <= 9)
	{
		//Todos los numeros de un digito son singulares
		c = n;
		es_singular = true;
		primer_dig = n;
	}

	else
	{

		comprueba_singul(n / 10, c, primer_dig, es_singular);

		//Los que son de la forma < n/10

		//a cada numero le puedo añadir 9 digitos, en cada decena habrá 9 que sean singulares, a excepcion del que 
		// repite digito
		c = 9 * c; 
		//El 0 lo contamos aparte pues si lo hacemos con este metodo, el 00 no es singular, pero 0 si que lo es
		c++;


		//Ahora los que son de la forma = n/10

		if (es_singular)
		{
			if (n % 10 > primer_dig)
				c = c + (n % 10 - 1);
			else
				c = c + n % 10;
		}

		es_singular = es_singular && (primer_dig != n % 10);

		//Aqui no hay que actualizar el primer digito , pues ya es el mas significativo desde el principio
	}
}

t_num num_singulares_menoresque(t_num n) {
	// Punto de entrada al algoritmo.
	// A implementar
	t_num c;
	t_num primer_dig;
	bool es_singular;

	comprueba_singul(n, c, primer_dig, es_singular);

	return c;
}


#ifndef DOM_JUDGE
unsigned short digito_mas_significativo(t_num n) {
	while (n > 9) {
		n = n / 10;
	}
	return (unsigned short) n;
}
bool es_singular(t_num n) {
	unsigned short msd = digito_mas_significativo(n);
	bool loes = true;
	while (n > 9 && loes) {
		loes = (n % 10 != msd);
		n = n / 10;
	}
	return loes;
}

t_num num_singulares_menoresque_naif(t_num n) {
	t_num num = 0;
	for (t_num i = 0; i < n; i++) {
		if (es_singular(i)) {
			num++;
		} 
	}
	return num;
}
#endif

#ifdef DOM_JUDGE
bool ejecuta_caso() {
	long long n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		cout << num_singulares_menoresque(n) << endl;
		return true;
	}
}
#endif

int main() {

#ifndef DOM_JUDGE
	srand(time(NULL));
	for (int i = 1; i < 1000; i++) {
		t_num  n = (t_num)rand();
		if (num_singulares_menoresque_naif(n) != num_singulares_menoresque(n)) {
			cout << "NO FUNCIONA" << endl;
			cout << n << ":" << num_singulares_menoresque_naif(n) << "..." << num_singulares_menoresque(n) << endl;
			break;
		}
	}
	cout << "OK" << endl;
	system("pause");
#endif

#ifdef DOM_JUDGE
	while (ejecuta_caso());
#endif
}
