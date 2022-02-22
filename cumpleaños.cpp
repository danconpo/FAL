#include <iostream>
#include <vector>
using namespace std;

const unsigned int MAX_NINIOS = 20; // maximo numero de ni?os
									// el n?mero de sitios siempre
									// ser? menor o igual que el
									// n?mero de ni?os

									// Representaci?n de la matriz de satisfacciones
typedef struct {
	int n_ninios;	// numero de ni?os.
	int n_sitios;	// numero de sitios
	int sat[MAX_NINIOS][MAX_NINIOS];  // la posici?n i,j representa la satisfaccion
									  // que siente el ninio i si se le asigna el ninio j											   
} tMatrizSatisfacciones;


/*
(1) En caso de utilizar una generalizaci?n, indicar su par?metros, y explicar para que
sirven cada uno de ellos

(2) ?C?mo son las soluciones parciales de este problema?
Las soluciones parciales a este problema vienen dadas por, los niños sentados hasta el momento, la satisfaccion acumulada de esas asignaciones,


(3) ?Cu?ndo una soluci?n parcial es viable?

(4) ?Cu?ndo una soluci?n parcial es una soluci?n final al problema?

(5) Dada una soluci?n parcial, ?c?mo se generan las siguientes soluciones
parciales viables?

(6) An?lisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalizaci?n, explicar c?mo se define el algoritmo final
a partir de la misma, por inmersi?n.



*/

bool es_buena_asignacion(const tMatrizSatisfacciones& sats, int h, int ninio_a_sentar, int sitio, vector<bool> sitios_ocupados, int &supersticiosos) {
	bool ok = true;
	if (sitios_ocupados[sitio]) {
		ok = false;
	}
	if (ok && sats.sat[ninio_a_sentar][sitio] < 0) {
		ok = false;
	}
	if (ok) {
		if (ninio_a_sentar == ninio_a_sentar%sats.n_sitios) {
			supersticiosos++;
			if (supersticiosos >= sats.n_sitios / 3) {
				ok = false;
			}
		}
	}
	// si estamos evaluando un niño por detras de mi hermano, y mi hermano no lo hemos sentado antes, no es valida
	/*if (ok && (sitio_a_ocupar==sats.n_sitios-1 && ninio>h && !sitios_ocupados[h])) {
		ok = false;
	}*/

	return ok;

}

//void satisfaccion_maxima_aux(const tMatrizSatisfacciones& sats, int h, int ninio_a_sentar, int &satMejor, int &sumaSat,
//	vector<int> estimacion_maxima, vector<bool> &sitios_ocupados, int &supersticiosos, bool &hay_mejor) {
//
//	if (ninio_a_sentar == sats.n_sitios) {
//		if (!hay_mejor || sumaSat > satMejor) {
//
//			satMejor = sumaSat;
//			hay_mejor = true;
//		}
//	}
//	else {
//		for (int ninio = 0; ninio < sats.n_ninios; ninio++) {
//
//			if (es_buena_asignacion(sats, h, ninio_a_sentar, ninio, sitios_ocupados, supersticiosos)) {
//				sitios_ocupados[ninio] = true;
//				sumaSat += sats.sat[ninio][ninio_a_sentar];
//				satisfaccion_maxima_aux(sats, h, ninio_a_sentar + 1, satMejor, sumaSat, estimacion_maxima, sitios_ocupados, supersticiosos, hay_mejor);
//				sitios_ocupados[ninio] = false;
//				sumaSat -= sats.sat[ninio][ninio_a_sentar];
//			}
//		}
//
//	}
//
//}

void satisfaccion_maxima_aux(const tMatrizSatisfacciones& sats, int h, int ninio_a_sentar, int &satMejor, int &sumaSat,
	int estimacion_maxima, vector<bool> &sitios_ocupados, int &supersticiosos, bool &hay_mejor) {
	int nsuma_sat = sumaSat;
		if (ninio_a_sentar == sats.n_ninios) {
			if (!hay_mejor || sumaSat > satMejor) {
	
				satMejor = sumaSat;
				hay_mejor = true;
			}
		}
		else {
		for (int sitio = 0; sitio < sats.n_sitios; sitio++) {
			int n_supersticiosos = supersticiosos;
			estimacion_maxima -= sats.sat[ninio_a_sentar][sitio];
			if (!sitios_ocupados[sitio]) {
				if (sats.sat[ninio_a_sentar][sitio] >= 0) {
					int i = ninio_a_sentar%sats.n_sitios;
					if (sitio == i) {
						n_supersticiosos++;
					}
					if (n_supersticiosos <= sats.n_sitios / 3) {
						if (estimacion_maxima + sumaSat > satMejor) {
							sitios_ocupados[sitio] = true;
							nsuma_sat += sats.sat[ninio_a_sentar][sitio];
							satisfaccion_maxima_aux(sats, h, ninio_a_sentar + 1, satMejor, nsuma_sat, estimacion_maxima, sitios_ocupados, n_supersticiosos, hay_mejor);
							nsuma_sat -= sats.sat[ninio_a_sentar][sitio];
							sitios_ocupados[sitio] = false;
						}
					}
				}
				//else {//PASAMOS AL SIGUIENTE NIÑO
				//	satisfaccion_maxima_aux(sats, h, ninio_a_sentar + 1, satMejor, nsuma_sat, estimacion_maxima, sitios_ocupados, supersticiosos, hay_mejor);
				//}
			}
		}
		if (ninio_a_sentar != h) {
			satisfaccion_maxima_aux(sats, h, ninio_a_sentar + 1, satMejor, nsuma_sat, estimacion_maxima, sitios_ocupados, supersticiosos, hay_mejor);
		}
	}
}

int estimacion_satis(const tMatrizSatisfacciones& sats) {
	int max = 0;
	int estimacion = 0;
	vector<int> maximos(sats.n_sitios);
	for (int sitio = 0; sitio < sats.n_sitios; sitio++) {
		max = sats.sat[0][sitio];
		for (int ninio = 1; ninio < sats.n_ninios; ninio++) {
			if (max < sats.sat[ninio][sitio]) {
				max = sats.sat[ninio][sitio];
			}
			maximos[sitio] = max;
		}
	}

	for (int i = 0; i < maximos.size(); i++) {
		estimacion += maximos[i];
	}

	return estimacion;
}

int satisfaccion_maxima(const tMatrizSatisfacciones& sats, int h) {
	// A IMPLEMENTAR
	std::vector<bool> sitios_ocupados(sats.n_sitios, false);
	int estimacion_maxima = estimacion_satis(sats);//vector para almacenar la maxima estimacion posible por la asignacion de sitios

	int ninio_a_sentar = 0;
	int suma_sat = 0;

	int satMejor = 0;//la inicializamos a la suma de los valores stas[i][j] donde i=j
	//for (int i = 0; i < sats.n_sitios; i++) {
	//	satMejor += sats.sat[i][i];
	//}

	int supersticiosos = 0;
	bool hay_mejor = false;
	satisfaccion_maxima_aux(sats, h, ninio_a_sentar, satMejor, suma_sat, estimacion_maxima, sitios_ocupados, supersticiosos, hay_mejor);

	return satMejor;
}


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

bool ejecuta_caso() {
	tMatrizSatisfacciones sats;
	cin >> sats.n_ninios;
	if (sats.n_ninios != -1) {
		cin >> sats.n_sitios;
		int h;
		cin >> h;
		for (int sitio = 0; sitio < sats.n_sitios; sitio++) {
			for (int ninio = 0; ninio < sats.n_ninios; ninio++) {
				cin >> sats.sat[ninio][sitio];
			}
		}
		cout << satisfaccion_maxima(sats, h) << endl;
		return true;
	}
	else {
		return false;
	}
}


int main() {
	while (ejecuta_caso());
}