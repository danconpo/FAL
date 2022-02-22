/* NOMBRE Y APELLIDOS:

*/

#include <iostream>

using namespace std;

typedef unsigned long long t_num;

/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

(2) ¿Cómo son las soluciones parciales de este problema?

(3) ¿Cuándo una solución parcial es viable?

(4) ¿Cuándo una solución parcial es una solución final al problema?

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

(6) Análisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.



*/

void resuelve(long long int &d, int n, int k, int nivel, int& c, int sumDigs)
{
	for (int i = 0; i <= 9; i++)  //añado los 10 digitos
	{
		if (d % 10 != i) //Si los dígitos son distintos entonces pruebo a sumar
		{ 
			sumDigs = sumDigs + i;
			if (sumDigs <= k) //Si la suma de los dígitos no excede k
			{ 
				d = d * 10 + i; //Formo con d el numero con el nuevo digito ( 20,...21...)
				if (nivel + 1 == n)  //Si el nivel coincide con el número de dígitos entonces es una solución, por ejemplo, 20, 21 y 23 ->> 3.
					c++;
				else
					resuelve(d, n, k, nivel + 1, c, sumDigs); //Le tengo que pasar el nivel siguiente

				d = d / 10; //deshacemos la vuelta atras, para que solo quede d
			}
			sumDigs = sumDigs - i; //Devolvemos la suma al estado inicial que sera d
		}
	}
}

t_num  cuenta_entretenidos(unsigned short d, unsigned short n, unsigned int k) {
	// PUNTO DE ENTRADA AL ALGORITMO
	int c = 0; //en 
	long long int d1 = d;
	resuelve(d1, n, k, 1, c, d);//la suma de los digitos contendra el primer digito

	return c;
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
	while(ejecuta_caso()); 	
}