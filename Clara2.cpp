#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 20;


typedef struct
{
	int total; //Guardaremos el  producto o la suma de los pares/impares según la mitad
	bool es_extrano; //booleano que nos indica si el vector es impar o par
	//Booleanos que indican si es una mitad u otra para realizar las comprobaciones
	bool es_derecha;
	bool es_izq;

} tSolucion;

void comprueba_extrano(int v[], int n, int inic, int fin, tSolucion &sol, bool parte_iz, bool parte_der)
{
	if (fin - inic == 1) //Solo hay 2 elemento
	{
		if (v[inic] <= v[fin])
			sol.es_extrano = true;
		else
			sol.es_extrano = false;

		//Si es la primera mitad 
		// El total es la suma de los numeros pares de la primera mitad mas el producto de los numeros impares

		if (parte_iz)
		{
			if (v[inic] % 2 == 0 && v[fin] % 2 == 0) //Si son pares se suman
				sol.total = v[inic] + v[fin];
			else  //si son impares se multiplican
				sol.total = v[inic] * v[fin];
		}

		//Si es la segunda mitad es al revés
		if (parte_der)
		{
			if (v[inic] % 2 == 0 && v[fin] % 2 == 0) //Si son pares se multiplican
				sol.total = v[inic] * v[fin];
			else  //si son impares se suman
				sol.total = v[inic] * v[fin];
		}
	}

	else
	{
		//Hallamos la mitad 
		int m = (inic + fin) / 2;

		tSolucion izq;
		tSolucion der;

		//Hacemos la recursión para la iz y la derecha  
		//Aqui uso m y m+1, no llegamos al m-1, pues no hay mitad exacta
		comprueba_extrano(v, n, inic, m, izq, true, false); //Mitad izq con la solucion de la izq
		comprueba_extrano(v, n, m + 1, fin, der, true, false); //Mitad derecha con la solucion de la derecha


		//El vector será extraños si:
		// 1.Al menos una de las dos mitades es extraña 
		// 2 .si la suma de los numeros pares de la primera mitad mas el producto de los 
		//   numeros impares de la primera mitad es menor o igual que el producto de los numeros 
		//  pares de la segunda mitad mas la suma de los numeros impares de la segunda mitad

		sol.es_extrano = (izq.es_extrano || der.es_extrano) && (izq.total <= der.total);
	}



}

bool extrano(int v[], int n) {

	tSolucion sol;

	comprueba_extrano(v, n, 0, n - 1, sol, false, false);

	return sol.es_extrano;

}


int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		int n;
		cin >> n;
		int v[MAX];
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		if (extrano(v, n)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return true;
}

