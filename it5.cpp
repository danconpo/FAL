#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habrá vectores de más de dos millones de elementos


/*
				ACLARACION DEL PROFESOR

Buenas tardes,

He observado que hay varias soluciones al problema "brillantes" que, siendo formalmente correctas,
obtienen 'worng answer' debido a los errores de redondeo propios de las operaciones en coma flotante.
Para evitar este problema, he modificado los casos de prueba para tener en cuenta una tolerancia en el
cálculo de la media. He fijado la tolerancia en 0.5 (de tal forma que todos aquellos números que estén a distancia 
menor que 0.5 se consideren iguales). De esta forma, para comparar si una puntuación 'p' está por encima de la media 'm',
debéis utilizar la condición p - m >= 0.5.

Con esta tolerancia los algoritmos formalmente correctos (es decir, correctos para aritmética de precisión infinita)
os deberían funcionar independientemente de cómo estéis calculando la media.

Un saludo,
JL

*/
/*

PRECONDICION DE LA FUNCION:
  ---Escribe aquí la precondición de la función.

	p={ 0< n <= tam(a)} //No admite vectores vacios
*/

int num_brillantes(float a[], int n);

/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aquí la postcondición de la función. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'



	Q={num_brillantes(resul,a,n)}
	num_brillantes(resul,a,n) = (resul = #i: 0<= i < n: a[i] > media(a,n)}

	media(a,n) = SUMA i: 0<=i<n: a[i]/n

 */



int num_brillantes(float a[], int n) {
	// Implementa aquí el algoritmo.
	// Para cada bucle, indica un invariante y una expresión 
	// de cota que permitan justificar la corrección del algoritmo

	int i = 0;
	float media = 0.0;
	int resul = 0;

	if (n > 0)
	{
		//Primer bucle: calculo la media
		while (i < n)
		{
			media = media + a[i];
			i++;
		}

		media = (media / n);

		i = 0;

		while (i < n)
		{
			//Es a[i] >= media pero debido a los decimales, hay que usar una precision del 0.5 para que pase el validador
			//Esta explicado al principio del archivo
			if ((a[i] - media) >= 0.5) 
				resul++; // Un alumno es superior a la media
			i++;
		}
	}

	return resul;
}

/* Complejidad: Determina justificadamente la complejidad del algoritmo


	T(n) = c0 + n*c1+ n*c2 = T(n) = c0 + n*(c1+ *c2)
	T(n) € THETA(n)
*/


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

void lee_vector(float a[], int & n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int main() {
	static float a[TMAX];
	int n;
	do {
		lee_vector(a, n);
		if (n >= 0) {
			cout << num_brillantes(a, n) << endl;
		}
	} while (n != -1);
}