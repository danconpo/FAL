/*
NOMBRE Y APELLIDOS:

*/


#include <iostream>

using namespace std;


const int TMAX = 300000;  // No habrá vectores de más de trescientos mil elementos


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aquí la precondición de la función.

	P={ 0 <= n <= tam(a) && k > 0 && PARATODO i: 0<= i < n: a[i] != 0}
*/

int num_sec_multiplos(const int a[], int n, int k);

/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aquí la postcondición de la función. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'

	Q={sec_mul(a,n,k,resul)}

	sec_mul(a,n,k,resul) = #u,v: 0< u <= v < n: es_multiplo(a[u],a[v]): (j-i) = k

	es_multiplo(a,b) = (a=0) || (a%b = 0 && b!= 0)
	
	
	//?¿?¿ no sería asi?¿?
	
	 Q= {multiplos(a,n,k,resul) }
	 multiplos(a,n,k,resul) = (resul : #u,v: 0<= u <= v < n && sec_mulktiplos(u,v,a) <= k : j-i +1)

	 sec_mulktiplos(u,v,a) = PARTODO i : u < i <= v : es_multiplo(a[v] , a[u])
	 es_multiplo (a , b) = (a = 0 || a% b = 0 && b!= 0)
	
	///


 */


 /*
 DISEÑO DEL ALGORITMO:

 Paso 1. Variables
 a,n,resul,k

 Paso 2. Invariante

 Supongamos Que se resuelve hasta la posicion anterior a J

 INV = sec_mul(a,J,k,resul) && 0 < i <= J <= n  

 Paso 3. Inicialización




 Paso 4. Condición del bucle, y código tras el bucle.

 Paso 5. Cuerpo del bucle


 Paso 6. Justificación de que el algoritmo siempre termina.

 En cada iteracion aumenta la j, podemos elegir n-j, ya que n siempre decrece y como mínimo va a ser 0

 Paso 7. Complejidad:


	T(n) = c0 + n * c1

	Complejidad lineal
 

 */


int num_sec_multiplos(const int a[], int n, int k) {

	int resul = 0; //no hay 
	int i = 0;
	int j = 1;

	if (k == 1) //Todos son multiplos
		resul = n;
	else
	{
		while (j < n)
		{
			if (a[j] % a[j - 1] == 0) // a[j] es multiplo de i
			{

				if ((j - i) +1 == k) // al ser la longitud = k, hemos encontrado una nueva secuencia de longitud k
				{
					resul++;
					i++; //reseteamos la secuencia
				}

				j++; //añado un valor a la rejilla
			}

			else  //no es multiplo, se rompe la rejilla
			{
				i = j; //reseteamos la secuencia
				j++; //j siempre está por encima de i
			}
		}
	}
	
	return resul;
}



/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */


bool ejecuta_caso() {
	static int a[TMAX];
	int n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		int k;
		cin >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << num_sec_multiplos(a, n, k) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}