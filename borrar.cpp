/* NOMBRE Y APELLIDOS:

*/

#include <iostream>

using namespace std;

typedef unsigned long long t_num;

/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

(2) ¿Cómo son las soluciones parciales de este problema?

(3) ¿Cuándo una solución parcial es viable?

(4) ¿Cuándo una solución parcial es una solución final al problema?

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

(6) Análisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.



*/

void resuelve(long long int & d, int n, int k, int nivel, int& res, int sumDigs) {
	for (int i = 0; i < 10; i++) { //Genero hijos
		if (d % 10 != i) { //Si los dígitos son distintos entonces los sumo en sumDigs
			sumDigs += i;
			d = d * 10 + i; //El número literal (20, 21, 22....)
			if (sumDigs <= k) { //Si la suma de los dígitos no excede k
				if (nivel + 1 == n)  //Si el nivel coincide con el número de dígitos entonces es una solución, por ejemplo, 20, 21 y 23 ->> 3.
					res++;
				else
					resuelve(d, n, k, nivel + 1, res, sumDigs);	
			}
			d = d / 10; //Dejo el número solo con el comienzo, con la d
			sumDigs -= i; //Dejo la suma de los dígitos a d (2 en el primer ejemplo)
		}
	}

}
t_num  cuenta_entretenidos(unsigned short d, unsigned short n, unsigned int k) {
	// PUNTO DE ENTRADA AL ALGORITMO
	int res = 0;
	long long int d1 = d;

	resuelve(d1, n, k, 1, res, d);

	return res;
}


bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		unsigned short d;
		unsigned int k;
		cin >> d >> k;
		cout << cuenta_entretenidos((unsigned short)d, n, k) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}