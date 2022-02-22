#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habrá vectores de más de dos millones de elementos


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aquí la precondición de la función.
  
	P = {0 <= n <= tam(a)}

*/
int num_chupiguays(const int a[], int n); 

/*
POSTCONDICION DE LA FUNCION: 
  -- Escribe aquí la postcondición de la función. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
     
	 Q={num_chupiguays(a,n,resul)}

	 num_chupiguays(a,n,resul) = (resul = #u: 0 <= u < n: es_multiplo(a[u], suma_preceden(a,u))

	 suma_preceden(a, u) = SUMATORIO v: 0 <= v < u: a[v] //Le pasamos el vector y la posicion que lo precede!

	 es_multiplo(a,b) = (a=0) || (a%b = 0 && b!= 0)

	 //Otra manera sería: EXISTE c: 0<= c <= |a|: |b|*c = |a|

 */
 

/*
DISEÑO DEL ALGORITMO:
-- Especifica cada paso del diseño en cada apartado indicado

Paso 1. Variables
a,n,resul 
i, suma //Todas las variables tienen que aparecer en el invariante

Paso 2. Invariante
Vamos resolviendo hasta un cierto i
inv = num_chupiguays(a,i,resul) && 0 <= i <= n && suma = suma_preceden(a,i) 

Paso 3. Inicialización
Si partimos de la posicion 1 para que se pueda dividir entre la

Si i = 1, entonces num_chupiguays(a,0,resul) = (resul = #u: 0 <= u < 1: es_multiplo(a[u], suma_preceden(a[u]))
													  = #u: 0: es_multiplo(a[u], suma_preceden(a[u]))
													  = 0) por tanto resul es 0

Además suma_preceden(1) = SUMATORIO i: 0 <= i < 1: a[i]
					    = SUMATORIO i: 0: a[0], por lo tanto, suma = a[0]


Paso 4. Condicion del bucle, y código tras el bucle
i < n

Cuando se sale del bucle, la condición se hace falsa y queda i >= n, además por el invariante  i <= n, por lo que se deduce que i = n,
entonces num_chupiguays(a,i,resul) = num_chupiguays(a,n,resul) = Q, que es la postcondicion

Paso 5. Cuerpo del bucle
Como por la condicion del bucle i < n y además por el invariante 0<= i <= n, podemos deducir que la posicion a[i] existe y tiene sentido

	2 casos: 

		-Si a[i] % suma == 0
			Incrementamos i, num_chupiguays(a,i,resul) se viola, pues tenemos un chupiguay menos, asi que para restablecerlo
			hacemos resul++
			suma = suma_preceden(a,i) tambien se viola pues me falta el termino actual, por lo que tenemos que hacer
			suma = suma + a[i]

		-Si a[i] % suma != 0
			Incrementamos i, pero no se viola num_chupiguays(a,i,resul) pues no hay un nuevo multiplo
			pero si se viola suma = suma_preceden(a,i), ya que hay que actualizar la suma: suma = suma + a[i]


Paso 6. Justificación de que el algoritmo siempre termina
Una posible cota será n-i, ya que n decrece en cada iteracion y como minimo n va a ser 0

Paso 7. Complejidad
	
	c0 = coste de inicializacion y devolucion de resultado
	c1 = coste de operaciones dentro del bucle

	T(n) = c0 + n*c1

*/



int num_chupiguays(const int a[], int n) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */

	int resul = 0;
	int suma = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{

			if (suma == 0)
				resul++;
			else if (a[i] % suma == 0)
				resul++;
		}

		else
		{
			if (suma != 0)
			{
				if (a[i] % suma == 0)
					resul++;
			}

		}

		suma += a[i];
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
		   cout << num_chupiguays(a, n) << endl;
	   }
   }
   while (n != -1);
}