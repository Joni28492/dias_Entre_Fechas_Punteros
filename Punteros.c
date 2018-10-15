#include "Punteros.h"

/**
*calcula si el año es bisiesto y retorna el resultado
*@param int año ->es un puntero
*@return int 0 o 1
*/
int bisiesto(int *anio) {


	//return (*anio % 400 == 0 || *anio % 100 != 0) ?  1 :  0;
	if ((*anio) % 400 == 0 || ((*anio) % 100) != 0)
		return 1;
	return 0;


}
/**
*calcula los dias que tiene un mes
*@param int dia ->es un puntero
*@param int mes ->es un puntero
*@param int año ->es un puntero
*@see int bisiesto( int *anio)
*@return int diasDelMes
*/
int diasDeMes(int *mes, int *anio) {

	int diasDelMes = 0;

	switch (*mes) {
	case 4: case 6: case 9: case 11:
		diasDelMes = 30;
		break;
	case 2:
		diasDelMes = 28;
		//tenemos en cuenta si es bisisesto
		if (bisiesto(anio)) { diasDelMes = 29; }
		break;
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		diasDelMes = 31;
		break;

	}


	return diasDelMes;

}
/**
*calcula el dia siguiente a la fecha dada
*@param int dia ->es un puntero
*@param int mes ->es un puntero
*@param int año ->es un puntero
*@see int bisiesto( int *anio)
*/
void calcularDiaSiguiente(int *dia, int *mes, int *anio) {


	//identificamos los dias que tiene cada mes
	int diasDelMes = diasDeMes(mes, anio);

	//sumamos el dia 
	if (*dia == diasDelMes)
		*dia = 1;
	else
		(*(dia))++;

	//tenemos en cuenta el mes
	if (*dia == 1) {

		if (*mes == 12) {
			*mes = 1;
		}
		else
			(*(mes))++;
	}

	//tenemos en cuenta el año
	if (*mes == 1 && *dia == 1)
		(*(anio))++;


}
/**
*Muestra la Fecha por pantalla
*@param int dia ->es un puntero
*@param int mes ->es un puntero
*@param int año ->es un puntero
*/
void mostrarFecha(int *dia, int *mes, int *anio) {


	printf("%d/%d/%d", *dia, *mes, *anio);


}
/**
*dias entre dias de un mes
*@param int dia ->es un puntero
*@param int dia1 ->es un puntero
*@return int totalDias entre un dia y otro
*/
int diasEntreDias(int *dia, int *dia1) {
	return (*dia1 - *dia);
}
/**
*dias entre meses
*@param int mes ->es un puntero
*@param int mes1 ->es un puntero
*@return int totalDias entre un mes y otro
*@see int diasDeMes(int *mes, int *anio)
*/
int diasEntreMeses(int *dia, int *dia1, int *mes, int *mes1, int *anio) {

	int totalDias = 0;
	int i = 0;

	for (i = (*(mes)+1); i < *mes1;i++) {
		totalDias += diasDeMes(&i, *anio);
	}

	totalDias += (diasDeMes(mes, anio) - *dia) + *dia1;//para los meses incompletos

	return totalDias;


}
/**
*dias entre años
*@param int anio ->es un puntero
*@param int anio1 ->es un puntero
*@return int totalDias entre un año y otro
*@see int diasDeMes(int *mes, int *anio)
*@see int bisiesto( int *anio)
*/
int diasEntreAnios(int *anio, int *anio1, int *mes, int *mes1, int *dia, int *dia1) {

	int totalDias = 0;
	int i = 0;


	for (i = *anio; i <= *anio1;i++) {//suma de los años quitando primero y ultimo
		totalDias += 365 + bisiesto(&i);
	}
	//restamos los dias iniciales
	for (i = 0; i < *mes; i++) {
		totalDias -= diasDeMes(&i, anio);
	}

	totalDias -= *dia;

	//restamos los posteriores
	for (i = 12; i >= *mes; i--) {
		totalDias -= diasDeMes(&i, anio1);
	}

	totalDias += *dia1;

	return totalDias;
}