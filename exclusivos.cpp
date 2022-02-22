

// Si se comenta esta definición, el programa
// autocomprobará su funcionamiento comparando
// la implementación realizada con una 
// implementación 'naif' del algoritmo
#define DOM_JUDGE

#include <iostream>

#ifndef DOM_JUDGE 
#include <ctime>
#include <stdlib.h>
#include <climits>
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

*/

t_num num_sinrepetidos_menoresque(t_num n) {
	// PUNTO DE ENTRADA AL ALGORITMO
	t_num c;

	return c;
}


// No modificar el código que sigue

#ifndef DOM_JUDGE

bool digs_reps(t_num n) {
	bool digs[10];
	for (unsigned short d = 0; d < 10; d++) {
		digs[d] = false;
	}
	while (n > 0 && !digs[n % 10]) {
		digs[n % 10] = true;
		n /= 10;
	}
	return n != 0;
}

t_num num_sinrepetidos_menoresque_naif(t_num n) {
	t_num num = 0;
	for (t_num i = 0; i < n; i++) {
		if (!digs_reps(i)) num++;
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
		cout << num_sinrepetidos_menoresque(n) << endl;
		return true;
	}
}
#endif


int main() { 
#ifdef DOM_JUDGE
	while (ejecuta_caso());
#endif

#ifndef DOM_JUDGE

	srand(time(NULL));
	int i=0;
	bool ok;
	while (i < 1000 && ok) {
		t_num  n = (t_num)rand();
		if (num_sinrepetidos_menoresque_naif(n) != num_sinrepetidos_menoresque(n)) {
			cout << "NO FUNCIONA" << endl;
			cout << n << ":" << num_sinrepetidos_menoresque_naif(n) << "..." << num_sinrepetidos_menoresque(n) << endl;
			ok=false;
		}
		i++;
	}
	if (ok) {
   	  cout << "OK" << endl;
	}   
	system("pause"); 
#endif

}

