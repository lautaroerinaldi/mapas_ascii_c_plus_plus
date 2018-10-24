/* Semaforo.h */

#ifndef SEMAFORO_H_
#define SEMAFORO_H_

#include "ElementoCircular.h"

class Semaforo: public ElementoCircular {
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

#endif /* SEMAFORO_H_ */
