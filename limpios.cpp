

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

void contar_limpios(unsigned short &d, unsigned short alpha, t_num n, unsigned int s, int contador,int &c, int &sumDigs)
{

	if (s == sumDigs)
		c++;
	else
	{
		for (int i = 0; i <= 9; i++) //le vamos añadiendo digitos
		{
			d = d * 10 + i;

			if (d % 10 != 0)
			{
				if ((n / 10) == d && d % 10 == d) // d debe aparecer de nuevo
				{
					//le sumamos un digito
					sumDigs = sumDigs + n % 10;

					if (sumDigs < s) //Tiene que tener menor longitud que alpha
					{
						contador++; //contamos una recurrencia mas

						if (contador < alpha) //si el contador es menor, hemos encontrado un nuevo limpio
							c++;
						else
							contador = 0;
					}

					else
						contar_limpios(d, alpha, n / 10, s, contador, c, sumDigs);
				}
			}
				d = d /10;
		}
	}
}

int num_limpios(unsigned short d, unsigned short alpha, t_num n, unsigned int s) {
	// PUNTO DE ENTRADA DEL ALGORITMO
	int c = 0;
	//la suma empieza en 0
	//El contador de recurrencias sera 0
	int sumDigs = 0;
	contar_limpios( d, alpha, n, s, 0, c, sumDigs);

	return c;
}


bool ejecuta_caso() {
	int d;
	cin >> d;
	if (d == -1) {
		return false;
	}
	else {
		unsigned short alpha; 
		unsigned int s;
		t_num n;
		cin >> alpha >> s >> n;
		cout << num_limpios(d, alpha, n, s) << endl;
		return true;
	}
}


int main() {
	while (ejecuta_caso());
}