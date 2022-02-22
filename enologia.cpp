/*
Nº DE GRUPO:
NOMBRE Y APELLIDOS DE LOS ESTUDIANTES QUE
HAN REALIZADO LA PRACTICA:

EN CASO DE QUE ALGUNO DE LOS MIEMBROS DEL
GRUPO NO HAYA PARTICIPADO EN LA PRACTICA,
INDICARLO AQUI, EXPLICANDO TAMBIÉN EL MOTIVO:



*/

#include <iostream>
using namespace std;

/* Estructura utilizada para almacenar la información de un tema */
typedef struct {
	float tiempo_req;  // tiempo requerido para estudiar el tema
	float nota_prim;   // aportación a la nota de la primera parte
	float nota_sec;    // aportación a la nota de la segunda parte
} tInfoTema;



/*
DISEÑO DEL ALGORITMO

Para superar este ejercicio, aparte de programar el algoritmo, debes
describir aqui detalladamente su diseño (parámetros y variables utilizados,
y su cometido, cometido de los resultados devueltos por las funciones,
idea general del algoritmo, estructura de las soluciones,
análisis de casos, acciones realizadas para cada caso...)

Este es otro problema típico de búsqueda de una solución óptima mediante un algoritmo “vuelta atrás”.
De hecho, puede pensarse en él como una variante del problema de la mochila, en el que la mochila tiene dos compartimentos.
El problema puede resolverse satisfactoriamente con ayuda de una generalización que acepte los siguientes parámetros:
- El vector de puntuaciones (parámetro de entrada), que permite determinar, para cada tema,
  la puntuación del tema en la primera parte, y la puntuación en la segunda parte.
- El tema actual a considerar (parámetro de entrada).
- La nota acumulada hasta el momento en la primera parte (parámetro de entrada)
- La nota acumulada hasta el momento en la segunda parte (parámetro de entrada)
- El tiempo del que aún se dispone (parámetro de entrada)
- La mejor nota encontrada hasta el momento (parámetro de entrada / salida)

Cada solución parcial al problema vendrá dada por: (i) los temas seleccionados hasta el momento
(representados por las respectivas notas acumuladas); (ii) el tema actual a considerar; y (iii) el tiempo disponible.

Las soluciones parciales serán viables cuando el tiempo disponible sea mayor o igual que 0.



*/


void encuentra_mejor_puntuacion(const tInfoTema info_temas[], int num_temas,
	int tema_actual, float nota_prim, float nota_sec, float tiempo_disponible, float& mejor_nota)
{
	bool generada = false;

	for (int nuevo_tema = tema_actual; nuevo_tema < num_temas; nuevo_tema++)
	{
		float ntiempo_disponible = tiempo_disponible - info_temas[nuevo_tema].tiempo_req;

		if (ntiempo_disponible >= 0)
		{
			generada = true;
			float nnota_prim = nota_prim + info_temas[nuevo_tema].nota_prim;
			float nnota_sec = nota_sec + info_temas[nuevo_tema].nota_sec;
			encuentra_mejor_puntuacion(info_temas, num_temas, nuevo_tema + 1, nnota_prim, nnota_sec, ntiempo_disponible, mejor_nota);
		}
	}

	if (!generada)
	{
		if (nota_prim >= 5.0 && nota_sec >= 5.0)  //Ambas notas tienen que superar el 5
		{
			//Actualizamos la mejor nota
			float nueva_nota = (nota_prim + nota_sec) / 2;

			if (nueva_nota > mejor_nota)
				mejor_nota = nueva_nota;
		}
	}
}

/* temas: Información sobre los temas de los que consta el examen (ver tInfoTema)
   num_temas: Numero de temas de los que consta el examen -su información aparece
			  al principio de info_temas
   tiempo_disponible: Tiempo total disponible para realizar el examen.
   Valor devuelto: La puntuación media máxima que se puede conseguir, o -1 si no
				   es posible aprobar el examen */
float mejor_puntuacion(const tInfoTema info_temas[], unsigned int num_temas, float tiempo_disponible) {
	/* ESTA FUNCIÓN SERÁ EL PUNTO DE ENTRADA AL ALGORITMO. Puedes, después, utilizar las
	   funciones auxiliares que consideres oportuno, pero debes incluir la justificación para ello
	   en el comentario de descripción detallado del diseño de dicho algoritmo */
	float mejor_nota = -1;
	encuentra_mejor_puntuacion(info_temas, num_temas, 0, 0, 0, tiempo_disponible, mejor_nota);
	return mejor_nota;
}

/* Código para leer y ejecutar casos de prueba: no debe modificarse */
const unsigned int MAX_TEMAS = 20;

bool procesa_caso() {
	int num_temas;
	tInfoTema info_temas[MAX_TEMAS];
	cin >> num_temas;
	if (num_temas != -1) {
		float tiempo_disponible;
		cin >> tiempo_disponible;
		for (int i = 0; i < num_temas; i++) {
			cin >> info_temas[i].tiempo_req;
			cin >> info_temas[i].nota_prim;
			cin >> info_temas[i].nota_sec;
		}
		cout << mejor_puntuacion(info_temas, num_temas, tiempo_disponible) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (procesa_caso());
}