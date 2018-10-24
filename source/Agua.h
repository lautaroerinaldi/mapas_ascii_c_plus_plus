/* Agua.h */

#ifndef AGUA_H_
#define AGUA_H_

#include "ElementoPoligonal.h"

class Agua: public ElementoPoligonal {
	static unsigned int prioridad;
	static char identificador;

public:
	/*
	 * Retorna la prioridad en el orden de dibujo de la clase
	 */
	unsigned int getPrioridad();

	/*
	 * Retorna el caracter ASCII que se utiliza para representar a la clase
	 * al dibujarla
	 */
	char getIdentificador();
};

#endif /* AGUA_H_ */
