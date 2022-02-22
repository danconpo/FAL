
#include <iostream>
using namespace std;


const int TMAX = 300000;  // No habrá vectores de más e 300000 elementos


/*
(1) En caso de utilizar una generalizacion, 
determinación de los parámetros de la generalización.
Determina los parámetros de la generalización. Para cada parámetro
indica: (i) su tipo; (ii) su nombre; (iii) si es un parámetro
de entrada, de salida, o de entrada / salida; (iv) su propósito,
descrito de manera clara y concisa.


(2) Análisis de casos:

(2.1) Casos base


(2.2) Casos recursivos

(3) En caso de utilizar una generalizacion, definición por inmersión 
del algoritmo. Describe de manera clara y concisa cómo se lleva a 
cabo el algoritmo, en qué punto o puntos se invoca a la generalización,
con qué parámetros reales, y cómo se genera el resultado
a partir de los devueltos por la generalización.



(4)Determina justificadamente la complejidad del algoritmo

(4.1) Determinación de las ecuaciones de recurrencia para la generalización

(4.2) Resolución utilizando los patrones vistos en clase

(4.3) Determinación justificada de la complejidad del algoritmo final.


	Tamaño del problema: (j-i) +1
	T(2) = c0 //Cuando solo hay 2 elementos como minimo
	T(n) = c1 + T(n/2)

	 a = 1, b = 2, k = 0
	 patron por division
	 como a = b ^k = 1, entonces T(n) esta en O(n ^k log n) = O(log n)
*/

int aux_num_perdido(int a[], int ini, int fin)
{
	//Si solo hay 2 elementos, ya que el enunciado nos dice que como minimo hay 2
	if (ini == fin - 1)
	{
		if (a[ini] != a[fin] - 1)
			return a[fin]-1;
	}

	else 
	{
		int m = (ini + fin) / 2;

		if ((fin - (m + 1)) + 1 != (a[fin] - a[m + 1]) + 1) 
			return aux_num_perdido(a, m + 1, fin);
		
		else if (a[m + 1] - a[m]>1) 
			return aux_num_perdido(a, m, m+1);

		else if ((m - (ini)) + 1 != (a[m] - a[ini]) + 1) 
			return aux_num_perdido(a, ini, m);
		
	}
}

int num_perdido(int a[], int n) {
	// A IMPLEMENTAR

	return aux_num_perdido(a, 0, n - 1);
}


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

bool procesa_caso() {
	static int a[TMAX];
	int n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
   	   for (int i=0; i < n; i++) {
         cin >> a[i];		
	   }
	   cout << num_perdido(a,n) << endl;
	   return true;
	}
}


int main() {
    while (procesa_caso());
}