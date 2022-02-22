/* NOMBRE Y APELLIDOS:

*/

#include <iostream>

using namespace std;

typedef unsigned long long t_num;

/*

(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
sirven cada uno de ellos

(2) �C�mo son las soluciones parciales de este problema?

(3) �Cu�ndo una soluci�n parcial es viable?

(4) �Cu�ndo una soluci�n parcial es una soluci�n final al problema?

(5) Dada una soluci�n parcial, �c�mo se generan las siguientes soluciones
parciales viables?

(6) An�lisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
a partir de la misma, por inmersi�n.



*/

void resuelve(long long int & d, int n, int k, int nivel, int& res, int sumDigs) {
	for (int i = 0; i < 10; i++) { //Genero hijos
		if (d % 10 != i) { //Si los d�gitos son distintos entonces los sumo en sumDigs
			sumDigs += i;
			d = d * 10 + i; //El n�mero literal (20, 21, 22....)
			if (sumDigs <= k) { //Si la suma de los d�gitos no excede k
				if (nivel + 1 == n)  //Si el nivel coincide con el n�mero de d�gitos entonces es una soluci�n, por ejemplo, 20, 21 y 23 ->> 3.
					res++;
				else
					resuelve(d, n, k, nivel + 1, res, sumDigs);	
			}
			d = d / 10; //Dejo el n�mero solo con el comienzo, con la d
			sumDigs -= i; //Dejo la suma de los d�gitos a d (2 en el primer ejemplo)
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