/* Semaforo.cpp */

#include "Semaforo.h"
#include "Definiciones.h"

unsigned int Semaforo::prioridad = PRIOR_SEMAFORO;
char Semaforo::identificador = IDENT_SEMAFORO;

unsigned int Semaforo::getPrioridad(){
	return Semaforo::prioridad;
}

char Semaforo::getIdentificador(){
	return Semaforo::identificador;
}
