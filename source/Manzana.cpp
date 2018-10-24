/* Manzana.cpp */

#include "Manzana.h"
#include "Definiciones.h"

unsigned int Manzana::prioridad = PRIOR_MANZANA;
char Manzana::identificador = IDENT_MANZANA;

unsigned int Manzana::getPrioridad(){
	return Manzana::prioridad;
}

char Manzana::getIdentificador(){
	return Manzana::identificador;
}
