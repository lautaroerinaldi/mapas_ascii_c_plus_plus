/* EdificioPrivado.h */

#ifndef EDIFICIOPRIVADO_H_
#define EDIFICIOPRIVADO_H_

#include "ElementoPoligonal.h"

class EdificioPrivado: public ElementoPoligonal {
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

#endif /* EDIFICIOPRIVADO_H_ */
