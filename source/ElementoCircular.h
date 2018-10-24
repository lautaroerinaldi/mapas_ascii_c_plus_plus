/* ElementoCircular.h */

#ifndef ELEMENTOCIRCULAR_H_
#define ELEMENTOCIRCULAR_H_

#include "ElementoMapa.h"

/*
 * Clase abstracta que puede representar en forma genérica a cualquier objeto
 * que sea de forma circular del mapa (es decir que tenga unas coordenadas de
 * latitud y longitud del punto central y un radio asociado)
 */
class ElementoCircular: public ElementoMapa {
protected:
	double radio;
	double x_centro;
	double y_centro;

public:
	/*
	 * Inicializa los atributos radio, x_centro e y_centro con el valor 0
	 */
	ElementoCircular();

	/*
	 * Libera los recursos utilizados por la clase.
	 */
	virtual ~ElementoCircular() {}

	/*
	 * Retorna el área de la superficie del elemento
	 */
	virtual double getArea();

	/*
	 * Retorna el radio de la figura circular en kilómetros.
	 */
	double getRadio() const;

	/*
	 * Retorna el valor de longitud (x)  en grados que se corresponde con el
	 * centro de la figura
	 */
	double getCentroX() const;

	/*
	 * Retorna el valor de latitud (y) en grados que se corresponde con el
	 * centro de la figura
	 */
	double getCentroY() const;

	/*
	 * Dado un valor de longitud (y) y otro de latitud (x) retorna true si esa
	 * coordenada es un punto contenido en el interior de la figura
	 */
	virtual bool pertenece(const double y, const double x);

	/*
	 * Parsea una linea con el formato:
	 * 		<latCento>,<longCentro>,<radio>
	 * 	y luego almacena sus valores como las coordenadas del centro (y, x) y
	 * 	el radio respectivamente.
	 * 	Luego, actualiza los valores extremos de la figura.
	 */
	virtual void parsear(std::stringstream & linea_a_parsear);
};

#endif /* ELEMENTOCIRCULAR_H_ */
