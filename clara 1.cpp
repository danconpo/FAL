/*
NOMBRE Y APELLIDOS:


*/

#include <iostream>
using namespace std;

const int TMAX = 2000000;

/*

	p={ 0<= n <= tam(v) && k > 0 }


	Q= {todos_pares(resul,v,n,k)}


	todos_pares(resul,v,n,k) = (resul = max i,j: 0<= i <= j < n && segmento_par(i,j,v,k) : (j-i)+1)

	subsegmento(i,j,v) = # x: i< x<=v: a[i] %2 = a[i-1] <= k



	1)variables
	a,n,resul,k
	i,j 





	



*/


int todos_pares(int v[], int n, int k)
{
	int resul = 0;
	int i = 0;
	int j = 0;
	int num_pares = 0;

	while (j < n)
	{
		if (v[j] % 2 == 0)
		{
			num_pares++;
		}

		if (num_pares >= k)
		{
			if (num_pares == k)
			{
				if ((j - i) + 1 > resul)
					resul = (j - i) + 1;
			}
			else
			{
					num_pares = 0;
					j = i;
					j++;
			}

			i++;
		}
		
		j++;
	}
	return resul;
}



void lee_vector(int a[], int & n) {
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int main() {
	static int a[TMAX];
	int n = 0;
	do {
		if (n >= 0) {

			cin >> n;
			int k;
			cin >> k;

			for (int i = 0; i < n; i++) {
				cin >> a[i];
			}
			cout << todos_pares(a, n,  k) << endl;
		}
	} while (n != -1);
}
