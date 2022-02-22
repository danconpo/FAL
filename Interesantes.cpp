
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


	-Si tomamos el tamaño del problema como d como el numero de digitos de n

	T(1) = c0
	T(d) = c1 + T(d-1)

	a = 1, b = 1, k = 0
	patron por substraccion

	Como a = 1, entonces T(d) € O(d^k+1) = O(d)


	-Si tomamos el tamaño del problema como n

	T(1) = c0
	T(n) = c1 + T(n/10)

	a= 1, b = 10,  k = 0
	patron por division

	como a = b^k = 1, entonces T(n) € (n^k log n) = O(log n)



*/


void comprueba_interes(unsigned int n, int suma_der, int &suma_izq, bool &es_interesante)
{
	//Caso base
	if (n > 0 && n <= 9)
	{
		suma_izq = n;
		//!!!!sera interesante si la suma de la derecha entre el ulrimo digito (n) es = 0
		es_interesante = (suma_der % n == 0);
	}

	//Si el digito es 0 o la suma derecha no es divisible por el digito actual, no va a ser interesante
	else if ((n % 10) == 0 || suma_der % (n % 10) != 0)
		es_interesante = false;

	else 
	{
		suma_der = suma_der + n % 10;

		comprueba_interes(n / 10, suma_der, suma_izq, es_interesante);

		es_interesante = es_interesante && ((suma_izq % (n%10)) == 0);
		
		suma_izq = suma_izq + n % 10;
	}
}


bool es_interesante(unsigned int n) {
	// A IMPLEMENTAR

	int suma_izq; 
	bool es_interes;

    comprueba_interes(n, 0, suma_izq, es_interes);

	return es_interes;
}

void ejecuta_caso() {
	unsigned int n;
	cin >> n;
	if (es_interesante(n)) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	unsigned int num_casos;
	cin >> num_casos;
	for (unsigned int i = 0; i < num_casos; i++) {
		ejecuta_caso();
    }
}