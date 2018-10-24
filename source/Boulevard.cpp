/* Boulevard.cpp */

#include "Boulevard.h"
#include "Definiciones.h"

unsigned int Boulevard::prioridad = PRIOR_BOULEVARD;
char Boulevard::identificador = IDENT_BOULEVARD;

unsigned int Boulevard::getPrioridad(){
	return Boulevard::prioridad;
}

char Boulevard::getIdentificador(){
	return Boulevard::identificador;
}
