/*
NOMBRE Y APELLIDOS:


*/

#include <iostream>
using namespace std;



typedef unsigned long long t_num;

/*
(1) En caso de utilizar una generalizacion, 
determinación de los parámetros de la generalización.
Determina los parámetros de la generalización. Para cada parámetro
indica: (i) su tipo; (ii) su nombre; (iii) si es un parámetro
de entrada, de salida, o de entrada / salida; (iv) su propósito,
descrito de manera clara y concisa.


(2) Análisis de casos:
(2.1) Casos base

Si el número es <= 9
 c = n y es_escalonado = true porque todos los números de una cifra son escalonados
 digito anterior será ese mismo n

(2.2) Casos recursivos
Para n > 9
Invocamos a la recursion para n/10
Primero calculamos los números que son < n/10
A cada número de la forma < n/10 le podemos añadir digitos del 0 al 9 pero  solo
habrá 2 que añadir al conjunto que cumplan subir o bajar
		c = 2 * c;
Los números de 1 dígito son todos escalonados y como no los podemos obtener de esa forma,
los sumamos a parte pero como ya hemos formado 2 por cada n/10, solo quedan 8 por sumar
		c = c + 8;
Faltan los numeros de la forma n/10
Con el booleano comprobamos si son escalonados, en el caso de que lo sean, comprobamos si el dígito actual es
mayor que ambas funciones para el dígito anterior (que será (n/10)%10)
if (n % 10 > subir((n/10)%10)) && n % 10 > bajar((n/10)%10))) En este caso sería un máximo de 2
ya que habrá 2 como mucho subir y bajar.
Y en caso contrario if (n % 10 > subir((n/10)%10)) || n % 10 > bajar((n/10)%10))) se cumplirá uno de los dos,
subir o bajar, por lo que solo sumamos 1: c = c+1

Por último actualizamos el booleano que será :
es_escalon = es_escalon && (n % 10 == subir((n/10)%10))) || n % 10 == bajar((n/10)%10))));
Ya que si un digito conicide con  el resultado de las funciones subir o con bajar del digito anterior, es escalonado


(3) En caso de utilizar una generalizacion, definición por inmersión
del algoritmo. Describe de manera clara y concisa cómo se lleva a
cabo el algoritmo, en qué punto o puntos se invoca a la generalización,
con qué parámetros reales, y cómo se genera el resultado
a partir de los devueltos por la generalización.

Para la generalización he usado una función con 3 parametros
void comprueba_escalonado(t_num n, t_num& c, bool& es_escalon)

t_num n, el número que nos dan
t_num& c, la cantidad de números para hacer el conteo
bool& es_escalon, el booleano para saber si un número es escalonado o no

después en la función t_num num_escalonados(t_num n), invoco a la función
comprueba_escalonado con los parámetros sin inicializar pues son de entrada y salida
después devuelvo la cantidad c

(4)Determina justificadamente la complejidad del algoritmo

(4.1) Determinación de las ecuaciones de recurrencia para la generalización

(4.2) Resolución utilizando los patrones vistos en clase

(4.3) Determinación justificada de la complejidad del algoritmo final.



Dependiendo del tamaño elegido podemos calcular 2 tipos de ecuaciones

	Si el tamaño escogido es n : Patrón por división

	T(1) = c0
	T(n) = c1 + T(n/10)

	donde a = 1, b = 10, k = 0

	como a = b^k = 1, entonces T(n) € O(n^k log n) = O(log n)


	Si el tamaño escogido es d (él número de digitos) : Patrón por substracción

	T(1) = c0
	T(d) = c1 + T(d-1)

	donde a = 1, b = 1, k = 0

	como a = 1, entonces T(d) € O(d^k+1) = O(d)


*/

int subir(t_num d)
{
	if (d < 9)
		return d + 1;
	else
		return 0;
}

int bajar(t_num d)
{
	if (d > 0)
		return d -1;
	else
		return 9;
}

void cuenta_escalonados(t_num n, t_num &c, bool &es_escalonado)
{

	if (n <= 9)
	{
		//Todos los numeros de un digito son escalonados
		c = n;
		es_escalonado = true;
	}

	else 
	{

		cuenta_escalonados(n/10, c, es_escalonado);

		//Numeros de la forma  u d, con u < n/10

		c = c * 2; //Cada decena hay 2 escalonados

		//Hay que sumarles 8, ya que de los numeros que se forman a partir del 0, solo van a ser escalonados 2,
		// pero todos los numeros de un digito son escalonados, asi que hay que sumarle los otros 8 aparte

		// 01 y 09 son escalonados, pero 00,02,03,04,05,06,07,08 no lo son por llevar el 0 delante, asi que los sumamos aparte
		c = c + 8;


		//Numeros de la forma  u d, con u = n/10

		//Solamente formaremos escalonados si el numero ya es escalonado
		if (es_escalonado)
		{
			if (n % 10 > subir((n / 10) % 10) && n % 10 > bajar((n / 10) % 10))
				c = c + 2;
			else if (n % 10 > subir((n / 10) % 10) || n % 10 > bajar((n / 10) % 10))
				c = c + 1;
		}

		//Sera escalonado si es escalonado y hay algun digito que sube o baja
		es_escalonado = es_escalonado && (n % 10 == subir((n / 10) % 10) || n % 10 == bajar((n / 10) % 10));
	}
}

t_num num_escalonados(t_num n) {
	// A IMPLEMENTAR
	t_num c;
	bool es_escalonado;

	cuenta_escalonados(n, c, es_escalonado);

	return c;
}

/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */


bool procesa_caso() {
	long long n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		cout << num_escalonados((t_num)n) << endl;
		return true;
	}

}

int main() {
    while (procesa_caso());
}