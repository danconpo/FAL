/*
N� DE GRUPO:
NOMBRE Y APELLIDOS DE LOS ESTUDIANTES QUE
HAN REALIZADO LA PRACTICA: VERONICA TERAN Y CARMEN SERRANO

EN CASO DE QUE ALGUNO DE LOS MIEMBROS DEL
GRUPO NO HAYA PARTICIPADO EN LA PRACTICA,
INDICARLO AQUI, EXPLICANDO TAMBI�N EL MOTIVO:



*/

#include <iostream>

using namespace std;


/*
(1) En caso de utilizar una generalizacion,
determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa.

int busca_min_fuerza(int enemigos[], int n, int max_duelos, int inf, int sup)
	enemigos[] -> array de enteros, parametro de entrada, indica los contricantes con la fuerza que se necesita para cada uno
	n -> entero, parametro de entrada, indica el numero de contrincantes, tamaño del array,
	max_duelos -> entero, parametro de entrada, indica el maximo de combates que pueden realizarse
	inf -> entero, parametro de entrada, indica el limite inferior del rango de potencias de 2 donde puede encontrarse la minima energia
	inf -> entero, parametro de entrada, indica el limite superior del rango de potencias de 2 donde puede encontrarse la minima energia

(2) An�lisis de casos:

(2.1) Casos base
	Comprueba si se puede luchar con el valor del punto medio del intervalo, si es asi, ademas comprueba si el valor es la minima fuerza que se puede
	utilizar comprobando de forma recursiva con el valor-1. Si no se puede completar la lucha con un valor m-1, el valor medio m es la fuerza minima que queremos.

(2.2) Casos recursivos
	Si se puede luchar con el valor medio del intervalo, y ademas este no es la fuerza minima y se puede luchar con un valor menor, realizamos las llamadas
	recursivas entre el principio del intervalo y como limite supuerio el valor m-1 hasta llegar a la fuerza minima necesaria.

	Por el contrario, si no se puede completar la lucha con el valor medio del intervalo ya que se necesita mas fuerza, realizamos las llamadas
	recursivas entre limite inferior m+1 y el limite superior, hasta llegar a la fuerza minima necesaria

(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.

(4) An�lisis de la complejidad del algoritmo
al utilizarse potencias de 2 como intervalos para comprobar cual puede ser la fuerza minima,
2^k < fuerza <= 2^k+1, haciendo el logaritmo k < log(fuerza) <= k+1, obtenemos que necesitamos log(f) iteraciones del bucle para encontrar la fuerza

T(0) = cte
T(n) = C1 + T(n/2), por lo que k=0, b=2, a=1 de forma que T(n) esta en el O(n^k log n) => O(log n)

*/

bool se_lucha(int enemigos[], int n, int max_duelos, int f) {
	int i = 0;
	int fuerzas = 0;
	int combates = 0;
	while (i < n && f >= enemigos[i]) {
		fuerzas += enemigos[i];//vamos sumando las fuerzas de necesarias con cada enemigo
		if (fuerzas > f) { //si la suma de las fuerzas para el enemigo i supera la fuerza minima, iniciamos un nuevo combate 
			combates++;
			fuerzas = enemigos[i];
		}
		i++;
	}
	if (i == n) {
		combates++;//al llegar al al ultimo enemigo hemos realizado el ultimo combate
		return (combates <= max_duelos);//SI HEMOS LUCHADO CONTRA TODOS LOS ENEMIGOS, DEVUELVE TRUE SI EL NUMERO DE COMBATES ES MENOR O IGUAL QUE EL MAXIMO
	}
	else return false;

}

void acota(int enemigos[], int n, int max_duelos, int &inf, int &sup) {
	for (int i = 0; i < n; i++) {
		sup += enemigos[i];
	}
	/*while (!se_lucha(enemigos, n, max_duelos, sup)) {
		inf = sup;
		sup *= 2;
	}*/
}

int busca_min_fuerza(int enemigos[], int n, int max_duelos, int inf, int sup) {
	int m = (sup + inf) / 2;
	if (se_lucha(enemigos, n, max_duelos, m)) {
		if (!se_lucha(enemigos, n, max_duelos, m - 1)) {
			return m;
		}
		else return busca_min_fuerza(enemigos, n, max_duelos, inf, m - 1);
	}
	else {
		return busca_min_fuerza(enemigos, n, max_duelos, m + 1, sup);
	}
}

int min_poder(int enemigos[], int n, int max_duelos) {
	// Punto de entrada al algoritmo: a implementar
	int inf = 0;
	int sup = 0;
	acota(enemigos, n, max_duelos, inf, sup);
	return 	busca_min_fuerza(enemigos, n, max_duelos, inf, sup);
}


const int MAX_ENEMIGOS = 1000;
bool ejecuta_caso() {
	int enemigos[MAX_ENEMIGOS];
	int num_enemigos;
	cin >> num_enemigos;
	if (num_enemigos == -1) {
		return false;
	}
	else {
		int max_torneos;
		cin >> max_torneos;
		for (int i = 0; i < num_enemigos; i++) {
			cin >> enemigos[i];
		}
		cout << min_poder(enemigos, num_enemigos, max_torneos) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}