/* ComparadorPorPrioridades.h */

#ifndef COMPARADORPORPRIORIDADES_H_
#define COMPARADORPORPRIORIDADES_H_
#include "ElementoMapa.h"

/*
 * Si las prioridades son distintas, compara por prioridades;
 * Sino, compara por identificador (para mantener el orden de los edificios
 * públicos)
 */
class ComparadorPorPrioridades {
public:
	/*
	 * Si las prioriodades de lhs y rhs son distintas, retorna true si la
	 * prioridad de lhs es mayor que la de rhs; Retorna false en otro caso.
	 *
	 * Si las prioridades de lhs y rhs son iguales, retorna true si el
	 * identificador de lhs es mayor que el de rhs; Retorna false en otro caso.
	 */
	bool operator()(ElementoMapa * lhs, ElementoMapa * rhs);
};

#endif /* COMPARADORPORPRIORIDADES_H_ */
