/* ElementoMapa.h */

#ifndef ELEMENTOMAPA_H_
#define ELEMENTOMAPA_H_

#include <sstream>

/*
 * Clase abstracta que puede representar en forma genérica a cualquier objeto
 * que puede poseer el mapa.
 */
class ElementoMapa {
protected:
	double lat_min;
	double lat_max;
	double long_min;
	double long_max;

public:
	/*
	 * Inicializa los extermos que ocupa la figura con el valor de 0.
	 */
	ElementoMapa();

	/*
	 * Libera los recursos utilizados por la clase.
	 */
	virtual ~ElementoMapa() {}

	/*
	 * Dado un valor de longitud (y) y otro de latitud (x) retorna true si esa
	 * coordenada es un punto contenido en el interior de la figura
	 */
	virtual bool pertenece(const double y, const double x)= 0;

	/*
	 * Retorna el caracter ASCII que se utiliza para representar a la clase
	 * al dibujarla
	 */
	virtual char getIdentificador()= 0;

	/*
	 * Parsea los valores que identifican a la figura, los almacena y
	 * luego, actualiza los valores extremos de la figura.
	 */
	virtual void parsear(std::stringstream & linea_a_parsear)= 0;

	/*
	 * Retorna la prioridad en el orden de dibujo de la clase
	 */
	virtual unsigned int getPrioridad()= 0;

	/*
	 * Retorna el área de la superficie del elemento
	 */
	virtual double getArea()= 0;

	/*
	 *  Retorna el valor de latitud extremo superior que ocupa la figura
	 */
	double getLatMax() const;

	/*
	 * Retorna el valor de latitud extremo inferior que ocupa la figura
	 */
	double getLatMin() const;

	/*
	 * Retorna el valor de longitud extremo derecho que ocupa la figura
	 */
	double getLongMax() const;

	/*
	 * Retorna el valor de longitud extremo izquierdo que ocupa la figura
	 */
	double getLongMin() const;
};

#endif /* ELEMENTOMAPA_H_ */
