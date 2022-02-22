/*
NOMBRE Y APELLIDOS:

N� USUARIO DOMJUDGE:

*/


#include <iostream>

using namespace std;


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aqu� la precondici�n de la funci�n.
  
  P={ 0 <= n <= tam(a) && PARATODO i: 0<= i < n: a[i] > 0} //Vector no vacio y numeros no negativos

*/

int max_integral(int v[], int n);

/*
POSTCONDICION DE LA FUNCION: 
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
     
	Q={max_escalera(resul,a,n)}
	mayor_esc(resul,v,n) = (resul = max x,y: 0<=x<=y<=n && escalera(v,x,y): integral(v,x,y))

	escalera(a,u,v) = PARATODO i: u < i <= v:(a[v] = a[i] +1 || a[v] = a[i] - 1)
	integral(a,u,v) = SUMATORIO i: u <= i <= v: a[i]
 */
 

/*
DISE�O DEL ALGORITMO:

Paso 1. Variables
v,n,resul
variable de control i
suma variable que almacenar� la suma de los elementos (hace referencia a integral, pero lo he llamado suma para que sea m�s c�modo)

Paso 2. Invariante
Suponemos que se resuelve el problema hasta J-1, es decir, J es la posici�n siguiente a la rejilla
Si i = 0 y j = 1

0 <= i <= j <= n 
suma = escalera(a,0,1-1) = SUMATORIO i : u <= i <= v :a[i] 
					     = SUMATORIO i : 0 <= i <= 0 :a[i] 
						 = 0

     
Paso 3. Inicializaci�n





Paso 4. Condici�n del bucle, y c�digo tras el bucle.


	
Paso 5. Cuerpo del bucle



Paso 6. Justificaci�n de que el algoritmo siempre termina.



Paso 7. Complejidad:



*/
int max_integral(int v[], int n) {
	// A IMPLEMENTAR

	int i = 1;
	int resul = v[0];
	int suma = v[0]; //Suma contiene el primer elemento del vector 

	while (i < n)
	{
		if (v[i - 1] == v[i] + 1 || v[i - 1] == v[i] - 1) //es un tramo en escalera
			suma = suma + v[i]; //acumulamos la suma	
		
		else
			suma = v[i]; //Reseteamos la suma

		if (suma > resul) //actualizamos el m�ximo 
			resul = suma;

		i++; 
	}
	return resul;
}

int v[300000];
int n;
int main() {

  while (cin >> n, n != -1) {
	 for (int i = 0; i < n; ++i)
		cin >> v[i];
	 cout << max_integral(v, n) << '\n';
  }

  return 0;
}
