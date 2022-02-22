
#include <iostream>
using namespace std;

const unsigned int MAX_CLIENTES = 10; // maximo numero de clientes
  // Representación de la matriz de afinidades
typedef struct {
	unsigned int n_clientes;                              // numero de clientes. 
	unsigned int afinidades[MAX_CLIENTES][MAX_CLIENTES];  // la matriz se almacena en las 'n_clientes' primeras filas,
	                                                      // 'n_clientes' primeras columnas	                                                      
} tMatrizAfinidad;

						 
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

int maxima_afinidad(const tMatrizAfinidad& as) {
	// Punto de entrada al algoritmo: as representa la matriz de afinidades 
	// (ver definición de tMatrizAfinidad). Una vez finalizado el algoritmo,
	// deberá devolverse el valor pedido. Pueden definirse todas las 
	// funciones auxiliares que se considere oportuno.
}


void ejecuta_caso() {
	tMatrizAfinidad as;
	cin >> as.n_clientes;
	for (unsigned int i = 0; i < as.n_clientes; i++) {
		for (unsigned int j = 0; j < as.n_clientes; j++) {
			cin >> as.afinidades[i][j];
		}
	}
	cout << maxima_afinidad(as) << endl;
}


int main() {
	unsigned int num_casos;
	cin >> num_casos;
	for (unsigned int i = 0; i < num_casos; i++) {
		ejecuta_caso();
	}
}