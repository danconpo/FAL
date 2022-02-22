#include <iostream>

using namespace std;

const int TMAX = 1000000;  // No habrá vectores de más de un millón de elementos



/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aquí la precondición de la función.
    
	p={ 0 < n = tam(a) && PARATODO i: 0< i < n: a[i-1] <= a[i]}

	//no es estrictamente creciente, puede haber elementos con el mismo valor, por lo que sera a[i-1] <= a[i]

*/
int menor_moda(const int a[], int n); 

/*
POSTCONDICION DE LA FUNCION: 
  -- Escribe aquí la postcondición de la función. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
 
	 numero_ocurrencias(v,a,n) = # i: 0 <= i < n: a[i] 
	 moda(v,a,n) =  numero_ocurrencias(v,a,n) = max i: 0<= i < n: numero_ocurrencias(a[i],a,n)

	menor_moda(resul,a,n) =  moda(resul,a,n) && PARATODO i: 0<= i < n && moda(a[i],a,n): a[i] >= resul 
*/


/*
DISEÑO DEL ALGORITMO:
-- Especifica cada paso del diseño en cada apartado indicado

Paso 1. Variables
a,n,resul
i


Paso 2. Invariante

INV= 


Paso 3. Inicialización



Paso 4. Condición del bucle, y código tras el bucle



Paso 5. Cuerpo del bucle



Paso 6. Justificación de que el algoritmo siempre termina



Paso 7. Complejidad

	Como solo hay una variable, el bucle dará n vueltas, desde i = 0, hasta n

	c0 = coste de inicializacion y finalizacion
	c1 = coste del cuerpo del bucle

	t(n) = c0 + n* c1;
	t(n) esta en THTEHA(n)

*/

 
 
int menor_moda(const int a[], int n) {
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */

	int resul = a[0]; //como el vector no es vacio, sabemos que el primer elemento existe
	int i = 1; 
	int num_actual = 1;
	int num_max = 1;

	while (i < n)
	{
		if (a[i - 1] == a[i])
		{
			num_actual++; //nuevo elemento consecutivo

			if (num_actual > num_max) //actualizamos la moda
			{
				resul = a[i];
				num_max = num_actual;
			}
		}

		else 
			num_actual = 1; //reseteamos el contador pues los elementos ya no son iguales

		i++;
	}

	return resul;
} 


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

void lee_vector(int a[], int & n) {
	cin >> n; 
   for (int i=0; i < n; i++) {
	   cin >> a[i]; 
   }   
}

int main() {
	static int a[TMAX];
	int n;
   do {
	   lee_vector(a,n); 
	   if (n>=0) {
		   cout << menor_moda(a, n) << endl;
	   }
   }
   while (n != -1);
}