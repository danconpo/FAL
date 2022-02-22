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

(6) Análisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.



*/



typedef struct {
	int cajas[MAX_OBJS];
	int n_cajas;
}tCajas;


//Funcion para comprobar si un objeto puede insertarse en su caja 
bool esValida(const tObjetos &objetos, tCajas cajas, int &i, int &k, int capacidad_caja){
	//Si el objeto cabe en la caja, se puede meter
	if (objetos.tamanios[k] + cajas.cajas[i] > capacidad_caja) 
		return false;

	return true;
}

void resuelve(const tObjetos& objetos, tCajas cajas, const int capacidad_caja, int k,  int& min_cajas){

	if (k == objetos.n_objetos) {
		if (min_cajas > cajas.n_cajas)
			min_cajas = cajas.n_cajas;
	}
	else if (min_cajas > cajas.n_cajas) {
		for (int i = 0; i < cajas.n_cajas; i++) {
			if(esValida(objetos, cajas, i, k, capacidad_caja)){
				cajas.cajas[i] += objetos.tamanios[k];
				resuelve(objetos, cajas, capacidad_caja, k + 1, min_cajas);
				cajas.cajas[i] -= objetos.tamanios[k];

			}
		}
		cajas.n_cajas++;
		cajas.cajas[cajas.n_cajas-1] += objetos.tamanios[k];
		resuelve(objetos, cajas, capacidad_caja, k + 1, min_cajas);
		cajas.cajas[cajas.n_cajas - 1] -= objetos.tamanios[k];
		cajas.n_cajas--;
	
	}
}

int min_numero_de_cajas(const tObjetos& objetos, int capacidad_caja) {
	// A IMPLEMENTAR
	int min_cajas = objetos.n_objetos;
	tCajas cajas;
	cajas.n_cajas = 0; //Contador de las cajas
	int k = 0;

	for (int i = 0; i < objetos.n_objetos; ++i)
		cajas.cajas[i] = 0;

	resuelve(objetos, cajas, capacidad_caja, k, min_cajas);

	return min_cajas;
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
