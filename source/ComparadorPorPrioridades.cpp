/* ComparadorPorPrioridades.cpp */

#include "ComparadorPorPrioridades.h"

bool ComparadorPorPrioridades::operator()(ElementoMapa * lhs,
		ElementoMapa * rhs) {
	if (lhs->getPrioridad() != rhs->getPrioridad())
		return (lhs->getPrioridad() > rhs->getPrioridad());
	else
		return (lhs->getIdentificador() > rhs->getIdentificador());
}
