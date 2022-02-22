#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habrá vectores de más de dos millones de elementos


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aquí la precondición de la función.

  !!!No puede haber vectores vacios
  P={ 0 < n <= tam(a) && k > 0 && PARATODO i: 0<= i < n: a[i] >= k && a[i] > 0 }
  
*/

int llena_mochila(const int a[], int n, int k); 

/*
POSTCONDICION DE LA FUNCION: 
  -- Escribe aquí la postcondición de la función. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
     
	 Q={lmax(resul,a,n,k)}
	 lmax(resul,a,n,k) = max u,v: 0<= u <= v < n && suma(a,u,v) <= k: (v-u)+1 

	 suma(a,u,v) = SUMATORIO w: u<=w<=v:a[w]
	 
 */
 

/*
DISEÑO DEL ALGORITMO:

Paso 1. Variables
a,n,k,resul

i,j,suma


Paso 2. Invariante
Suponemos el problema resuelto hasta la posicion anterior a J

!!J marca la posicion siguiente a la rejilla, por tanto la suma llega hasta j-1
INV = mochila(resul,a,J,k) && 0<= i <= J <= n && suma = suma(a,i,J-1) && suma <=k
     

Paso 3. Inicialización

Si empezamos la rejilla en la posicion 0
Como el vector no es vacio, i puede ser la primera posicion y como j es la posicion siguiente a la rejilla, deberá ser 1

i = 0, j = 1, entonces lmax(resul,a,1,k) = resul = max u,v: 0 <= u < v < 1:suma(a,u,v) <= k: (v-u)+1 
											        =  max u, v: 1:. ..... 
													= 1
Ya que hay un elemento en el tramo

ademas suma = suma(a,0,1-1) = SUMATORIO i: 0<=i<=0:a[0], por lo tanto, suma contendra el primer elemento del array

Paso 4. Condición del bucle, y código tras el bucle.
Como vamos a iterar hasta la posicion anterior a J
(j < n)
Cuando se hace falsa esta condicion: j>= n, y como por el invariante  J <= n , podemos deducir que j = n
entonces lmax(resul,a,J,k) = lmax(resul,a,n,k) = Q, que es la postcondicion
	
Paso 5. Cuerpo del bucle
Como por la condicion del bucle j < n y por el invariante 0 <= i <= J <= n, por tanto a[i] y a[j] son posiciones que estan en rango, 
tienen sentido y existen


	2 casos:

		1)if(suma + a[j] <= k): Anexamos un elemento a la rejilla sumandolo
	     suma = suma(a,i,J-1) si se viola, pues al añadir un nuevo elemento a la rejilla (no llegará a j-1, si no a j)
		 tenemos que restablecer el valor de j:j++
		 0<= i <= J <= n este termino no se violaria, pues por la condicion del bucle j < n
		Al añadir un nuevo elemento, se puede violar lmax(resul,a,J,k)
		ya que como buscamos el maximo, si hemos encontrado un nuevo max, hay que actualizar  
		if((j-i) > resul) : resul: resul = (j-i)
		

		3)if(suma + a[j] > k) En este caso hay que encojer la rejilla quitando el primer elemento
		Para ello suma = suma - a[i]. 
		Entonces se viola suma = suma(a,i,J-1), ya que  ahora lo que se cumple es suma(a,i,J-1), ya que hemos quitado a[i].
		Para restablecerlo debemos incrementar i++. Ahora tras este incremento ocurre:
		-Potencialmente 0<= i <= J <= n, pero como antes de incrementar i, podemos asegurar que i < j
		Supongamos que  antes de incrementar i, i = j, suma = suma(a,i,J-1) = 0 ya que la rejilla esta vacia. Por tanto
		como suma + a[j] > k, debe ser a[j] > k. Pero esto no es posible, por la precondicion. Como resultado, tras incrementar
		i, se preserva 0<= i <= J <= n 

Paso 6. Justificación de que el algoritmo siempre termina.
 Como no siempre se incrementa la misma variable, o bien se incrementa j o bien se incrementa i,
 una posible cota puede (n-j) + (n-i), ya que n decrece en cada iteracion y como mucho va a ser 0
 

Paso 7. Complejidad:

	Como hay 2 variables que o bien se incrementa una, o bien se incrementa la otra, como mucho el bucle dara 2n vueltas

	c0 = coste de inicializacion y devolucion de resultados
	c1: coste de instrucciones dentro del bucle

	T(n) = c0 + 2n* c1
	T(n) esta en THETA(n)
 
*/

int llena_mochila(const int a[], int n, int k) {
	  // A IMPLEMENTAR

	int i = 0;
	int j = 1;
	int resul = 1;
	int suma = a[0]; //Será el primer elemento

	while (j < n)
	{
		if (suma + a[j] <= k)
		{
			suma = suma + a[j];
			j++;

			if ((j - i) > resul)
				resul = (j - i);	
		}

		else
		{
			//Le quitamos el primero
			suma = suma - a[i];
			i++;
		}
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
		   int k;
		   cin >> k;
		   cout << llena_mochila(a, n, k) << endl;
	   }
   }
   while (n != -1);
}