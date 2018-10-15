
#include "Punteros.h"
#include "Calculadora.h"
#include "Principal.h"






/**
*lee por teclado una fecha
*@param int dia ->es un puntero
*@param int mes ->es un puntero
*@param int año ->es un puntero
*/
void introducirFecha(int *dia, int *mes, int *anio) {

	printf("introduce dia\n");
	scanf_s("%d", dia);
	printf("introduce mes\n");
	scanf_s("%d", mes);
	printf("introduce anio\n");
	scanf_s("%d", anio);

}



/**
*dias entre 2 fechas, este metodo compara si estamos en el mismo mes y año 
*@param int dia ->es un puntero
*@param int dia1 ->es un puntero
*@param int mes ->es un puntero
*@param int mes1 ->es un puntero
*@param int anio ->es un puntero
*@param int anio1 ->es un puntero
*@return int totalDias entre una fecha y otra
*@see int diasEntreDias(int *dia, int *dia1)
*@see int diasEntreMeses(int *dia, int *dia1, int *mes, int *mes1, int *anio)
*@see int diasEntreAnios(int *anio, int *anio1, int *mes, int *mes1, int *dia, int *dia1)
*/
int diasEntreFechas(int *dia, int *mes, int *anio, int *dia1, int *mes1, int *anio1) {

	int totalDias = 0;
	
	if (*mes == *mes1   &&  *anio == *anio1) {
		totalDias += diasEntreDias(dia, dia1);

	}


	else if (*mes != *mes1   &&  *anio == *anio1) {
		totalDias += diasEntreMeses(dia, dia1, mes, mes1, anio);

	}
	
	else {

		totalDias += diasEntreAnios(anio, anio1, mes, mes1, dia, dia1);
	}



}
/////Fin de Metodos de Fechas


void mostrarMatriz(int *ptrMatriz) {

	int i = 0;

	for (i = 1; i <=9; i++) {
		printf("%d ", *(ptrMatriz + (i - 1)));
		if (i % 3 == 0)	printf("\n");
	}
}


int simetria(int *ptrMatriz) {

	int i = 0;

	for (i = 1;i <= 9; i++) {

		//if(!(*((ptrMatriz)+i) == *((ptrMatriz)+j)))


	}


}



/////////MAIN///////
int main(int argc, char** argv) {
	//variables fechas
	int mes = 0, dia = 0, anio = 0;
	int mes1 = 0, dia1 = 0, anio1 = 0;
	
	//variables matrices
	/*int matriz[9] = {3,2,1,2,0,3,1,3,4};//esta es simetrica
	int *ptrMatrizSimetrica = &matriz[0];*/

	//1-Escribir un programa que dada una fecha (dia mes y año) nos diga la del día siguiente
	
	introducirFecha(&dia, &mes, &anio);
	mostrarFecha(&dia, &mes, &anio);
	printf("\n");

	calcularDiaSiguiente(&dia, &mes, &anio);
	printf("Dia Siguiente: ");
	mostrarFecha(&dia, &mes, &anio);
	
	printf("\n");
	printf("\n");
	//2-Escribir un programa que calcule el numero de dias entre dos fechas.
	introducirFecha(&dia1, &mes1, &anio1);
	mostrarFecha(&dia1, &mes1, &anio1);
	printf("\n");
	printf("hay %d entre esas fechas\n", diasEntreFechas(&dia, &mes, &anio, &dia1, &mes1, &anio1));
	

	//3-Escribir un programa que lea una matriz cudrada de números reales e indique si es simétrica o no
	//simetria();

	//mostrarMatriz(ptrMatrizSimetrica);




	//4-Escribir un programa que lea una matriz cuadrada de números reales e indique si algún elemento de la diagonal principal es nulo o no. Imprimir la transpuesta.
	//diagonal();
	//transpuesta();

	//5-En un tablero de ajedrez (8x8) se coloca una reina cuya posición se indica por teclado, indicar donde se pueden poner otras reinas sin que se ataquen entre sí.
	//reinas();

	//6-Escribir una versión rudimentaria de calculadorea matricial:
		
				/*Leer matriz cuadrada
					sumar matrices
					restar matrices
					multiplicar matrices
					escribir matrices
				*/


	//7-Escribir un programa que dado un mes y un año nos genere el calendario de dicho mes.

	system("PAUSE");
	return 0;
}