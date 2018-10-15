#ifndef PUNTEROS__H
#define PUNTEROS__H

int bisiesto(int *anio);
int diasDeMes(int *mes, int *anio);
void calcularDiaSiguiente(int *dia, int *mes, int *anio);
void mostrarFecha(int *dia, int *mes, int *anio);
int diasEntreDias(int *dia, int *dia1);
int diasEntreMeses(int *dia, int *dia1, int *mes, int *mes1, int *anio);
int diasEntreAnios(int *anio, int *anio1, int *mes, int *mes1, int *dia, int *dia1);

#endif