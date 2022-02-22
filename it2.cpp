#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habrá vectores de más de dos millones de elementos


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aquí la precondición de la función.
  
  P= {0 <= n <= tam(a)}


*/
bool es_gaspariforme(const int a[], int n); 

/*
POSTCONDICION DE LA FUNCION: 
  -- Escribe aquí la postcondición de la función. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
     
	 Q={gasp(a,n,resul)}

	 gasp(a,n,resul) = 
	 (resul = (PARATODO u:0<=u< n:(SUMATORIO j:0<= j<= u:a[j]) > 0) && (SUMATORIO u: 0<= u < n:a[u])=0) ) 

	suma(a,u)= SUMATORIO v: 0<= v <= u: a[v]
 */
 
	

/*
DISEÑO DEL ALGORITMO:
-- Especifica cada paso del diseño en cada apartado indicado

Paso 1. Variables
a,n,resul 
i

Paso 2. Invariante
INV =  gasp(a,i,resul) && 0<= i <= n && suma = 

Paso 3. Inicialización



Paso 4. Condición del bucle, y código tras el bucle



Paso 5. Cuerpo del bucle



Paso 6. Justificación de que el algoritmo siempre termina



Paso 7. Complejidad


*/

 
  
 bool es_gaspariforme(const int a[], int n) {
    /* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
       CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	

	 bool resul = true;
	 int i = 0;
	 int suma = 0;

	 while (i < n && suma >= 0)
	 {
		 suma = suma + a[i];
		 i++;
	 }

	 return (suma == 0);
	 /*
	 while (i < n && resul)
	 {
		 suma = suma + a[i];

		 if (suma < 0)
			 resul = false;
		 i++;
	 }

	 if(suma != 0)
		 resul = false;
	
	 return resul;
	  */
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
		 if (es_gaspariforme(a,n)) 
           cout << "SI" << endl;
         else  
           cout << "NO" << endl;			 
	   }
   }
   while (n >= 0);	
}