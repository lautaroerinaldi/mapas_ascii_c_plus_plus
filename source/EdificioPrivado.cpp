/* EdificioPrivado.cpp */

#include "EdificioPrivado.h"
#include "Definiciones.h"

unsigned int EdificioPrivado::prioridad = PRIOR_EDIF_PRIVADO;
char EdificioPrivado::identificador = IDENT_EDIF_PRIVADO;

unsigned int EdificioPrivado::getPrioridad() {
	return EdificioPrivado::prioridad;
}

char EdificioPrivado::getIdentificador() {
	return EdificioPrivado::identificador;
}
