/* Agua.cpp */

#include "Agua.h"
#include "Definiciones.h"

unsigned int Agua::prioridad = PRIOR_AGUA;
char Agua::identificador = IDENT_AGUA;

unsigned int Agua::getPrioridad(){
	return Agua::prioridad;
}

char Agua::getIdentificador(){
	return Agua::identificador;
}
