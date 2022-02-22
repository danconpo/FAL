/*
NOMBRE Y APELLIDOS: 


*/

#include <iostream>

using namespace std;


/*
(1) En caso de utilizar una generalizacion,
determinación de los parámetros de la generalización.
Determina los parámetros de la generalización. Para cada parámetro
indica: (i) su tipo; (ii) su nombre; (iii) si es un parámetro
de entrada, de salida, o de entrada / salida; (iv) su propósito,
descrito de manera clara y concisa.

utilizamos el metodo min_capacidad_aux(int etapas[], int n, int repostajes_permitidos, int inf, int sup) para utilizar el metodo divide y venceras dividiendo el vector de entrada
a la mitad en cada recursion
(2) Análisis de casos:

(2.1) Casos base
si con la mitad del vector de combustibles podemos hacer la ruta, y con uno menos no podemos, hemos encontrado el combustible minimo.

(2.2) Casos recursivos
en caso contrario hacemos la recursion hasta encontrar el combustible minimo

(3) En caso de utilizar una generalizacion, definición por inmersión
del algoritmo. Describe de manera clara y concisa cómo se lleva a
cabo el algoritmo, en qué punto o puntos se invoca a la generalización,
con qué parámetros reales, y cómo se genera el resultado
a partir de los devueltos por la generalización.



(4)Determina justificadamente la complejidad del algoritmo

la complejidad depene de dos factores, el numero de etapas y el tamaño del intervalo, la complejidad se realiza por expansion:

t(n,1) = c1;
t(e,s) = w(e) + t(e,s/2)

(4.1) Determinación de las ecuaciones de recurrencia para la generalización

(4.2) Resolución utilizando los patrones vistos en clase

(4.3) Determinación justificada de la complejidad del algoritmo final.



*/

bool puede_hacer_ruta(int etapas[], int n, int repostajes_permitidos, int combustible) {
	bool poco_combustible = false;
	int r = repostajes_permitidos;
	int c_actual = combustible;
	int e = 0;
	while (e < n && !poco_combustible) {
		if (c_actual >= etapas[e]) {
			c_actual -= etapas[e];
		}
		else {
			if (r > 0) {
				r--;
				c_actual = combustible;
				if (c_actual < etapas[e]) {
					poco_combustible = true;

				}
				else {
					c_actual -= etapas[e];
				}
			}
			else {
				poco_combustible = true;
			}
		}
		e++;
	}
	return (e == n && !poco_combustible);
}

int calculo_maximo(int etapas[], int n) {
	int suma = 0;
	for (int i = 0; i < n; i++) {
		suma += etapas[i];
	}
	return suma;
}

int calculo_minimo(int etapas[], int n) {
	int max = etapas[0];
	for (int i = 1; i < n; i++) {
		if (etapas[i] > max) {
			max = etapas[i];
		}
	}
	return max;
}

int min_capacidad_aux(int etapas[], int n, int repostajes_permitidos, int inf, int sup) {
	int m = (inf + sup) / 2;
	if (puede_hacer_ruta(etapas, n, repostajes_permitidos, m)) {
		if (!puede_hacer_ruta(etapas, n, repostajes_permitidos, m - 1)) {
			return m;
		}
		else {
			return min_capacidad_aux(etapas, n, repostajes_permitidos, inf, m - 1);
		}
	}
	else {
		return min_capacidad_aux(etapas, n, repostajes_permitidos, m+1, sup);
	}
}

int min_capacidad(int etapas[], int n, int repostajes_permitidos) {
	// A IMPLEMENTAR
	int sup = calculo_maximo(etapas, n);
	int inf = calculo_minimo(etapas,n);
	return min_capacidad_aux(etapas, n, repostajes_permitidos, inf, sup);
}

int v[100000];
int n, c;

int main() {

	while (cin >> n, n != -1) {
		cin >> c;
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		cout << min_capacidad(v, n, c) << '\n';
	}

	return 0;
}