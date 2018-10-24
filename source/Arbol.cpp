/* Arbol.cpp */

#include "Arbol.h"
#include "Definiciones.h"
#include <math.h>

unsigned int Arbol::prioridad = PRIOR_ARBOL;
char Arbol::identificador = IDENT_ARBOL;

unsigned int Arbol::getPrioridad(){
	return Arbol::prioridad;
}

char Arbol::getIdentificador(){
	return Arbol::identificador;
}
