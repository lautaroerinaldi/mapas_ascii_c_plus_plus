/* Manzana.h */

#ifndef MANZANA_H_
#define MANZANA_H_

#include "ElementoPoligonal.h"

class Manzana: public ElementoPoligonal {
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

#endif /* MANZANA_H_ */
