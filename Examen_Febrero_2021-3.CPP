/*
NOMBRE Y APELLIDOS:

*/

#include <iostream>
using namespace std;

const int MAX_OBJS = 20;

// Lista con los objetos a portar 
typedef struct {
	int tamanios[MAX_OBJS];  // Array en cuyas primeras posiciones se guardan
							 // los tamaños de los objetos
	int n_objetos;           // Numero de objetos
} tObjetos;



/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

(2) ¿Cómo son las soluciones parciales de este problema?

(3) ¿Cuándo una solución parcial es viable?

(4) ¿Cuándo una solución parcial es una solución final al problema?

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?
Como estamos recorriendo un árbol en el que vamos insertando objetos, cada

(6) Análisis de casos

(6.1) Caso(s) base



(6.2) Caso(s) recursivos

Probamos el siguiente objeto a meter dentro de la caja con la capacidad de la caja actualizada  (es decir, el tamaño de la caja, más el
tamaño del objeto)

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.



*/

typedef struct
{
	int min_cajas;
}tSolucion;

/*

	objeto_actual = es la posicion del objeto que estamos mirando
	capacidad_caja = es la capacidad predeterminada de la caja
	capacidad_actual = será la capacidad de la caja que estamos mirando y que vamos a modificar al meter un objeto
	num_cajas = el numero de cajas que hay actualmente

*/
//Funcion para comprobar si un objeto puede insertarse en su caja 
bool comprueba_objeto(const tObjetos& objetos, bool marcadores[], int objeto_actual, int capacidad_caja,
	int &capacidad_actual, int &num_cajas)
{
	//Si el objeto está ya marcado, quiere decir que está dentro de alguna caja
	// entonces no se puede meter en otra
	if (marcadores[objeto_actual] == true)
		return false;
	//Si el objeto cabe en la caja, se puede meter
	if (capacidad_actual + objetos.tamanios[objeto_actual] <= capacidad_caja)
		return true;
	else
	{
		//pasamos a la siguiente caja
		num_cajas++;
		//Como es una nueva caja, tendrá capacidad 0
		capacidad_actual = 0;
	}
}
void cajas(const tObjetos& objetos, tSolucion& sol, bool marcadores[], int objeto_actual, int capacidad_caja,
	int capacidad_actual, int num_cajas)
{
	//creamos un contador de cajas
	int num_cajas_actual = num_cajas;

	//Pruebo los objetos 
	//Mientras no se llegue al final del array de objetos o no se exceda la capacidad de objetos, seguimos insertando
	for (int objeto = 0; objeto < objetos.n_objetos; objeto++)
	{
		//Comprobamos si el objeto se puede meter dentro de la caja
		//Le tenemos que pasar el numero de las cajas que estamos contando actualmente, porque si no. dará siempre 1
		//Le tenemos que pasar el objeto del for como objeto_actual
		if (comprueba_objeto(objetos, marcadores, objeto, capacidad_caja, capacidad_actual, num_cajas_actual))
		{
			//Añadimos el objeto
			marcadores[objeto] = true; //Marco el objeto actual como añadido

			//Si hemos metido todos los objetos, hemos llegado al final
			if (objeto_actual == objetos.n_objetos - 1)
			{
				//Actualizamos el minimo
				if (num_cajas_actual < sol.min_cajas)
					sol.min_cajas = num_cajas_actual;
			}

			//Si no, hacemos la recursión para el siguiente objeto con los datos modificados y el num de cajas que hay hasta ahora
			else
			{
				//Pasamos al siguiente objeto
				//Modificamos el tamaño de la caja con el nuevo objeto
				cajas(objetos, sol, marcadores, objeto_actual + 1, capacidad_caja, capacidad_actual + objetos.tamanios[objeto],
					num_cajas_actual);
			}

			//Lo sacamos el objeto
			marcadores[objeto] = false;
		}
	}
}

int min_numero_de_cajas(const tObjetos& objetos, int capacidad_caja) {
	// A IMPLEMENTAR

	bool marcadores[MAX_OBJS]; //Array para marcar los objetos que entran en la caja
	//inicializo los marcadores a false, es decir, que no están en ninguna caja
	for (int i = 0; i < objetos.n_objetos; i++)
		marcadores[i] = false;
	//Inicializamos la solucion
	tSolucion sol;
	sol.min_cajas = objetos.n_objetos;

	//El objeto actual es el primero = 0
	//La capacidad de la caja será = 0, ya que está vacía en primer lugar
	//El número de cajas será 1, pues por lo menos hay una caja donde guardar cosas
	cajas(objetos, sol, marcadores, 0, capacidad_caja, 0, 1);

	return sol.min_cajas;
}

/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

bool ejecuta_caso() {
	int capacidad;
	cin >> capacidad;
	if (capacidad != -1) {
		tObjetos objetos;
		cin >> objetos.n_objetos;
		for (int i = 0; i < objetos.n_objetos; i++) {
			cin >> objetos.tamanios[i];
		}
		cout << min_numero_de_cajas(objetos, capacidad) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (ejecuta_caso());
}
