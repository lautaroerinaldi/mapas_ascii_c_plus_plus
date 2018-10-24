/* ElementoPoligonal.h */

#ifndef ELEMENTOPOLIGONAL_H_
#define ELEMENTOPOLIGONAL_H_

#include "ElementoMapa.h"
#include <vector>
#include <utility>

/*
 * Clase abstracta que puede representar en forma genérica a cualquier objeto
 * que sea de forma poligonal del mapa (es decir que pueda representarse como
 * un conjunto de pares (latitud, longitud) que representan los vértices del
 * polígono.
 */
class ElementoPoligonal: public ElementoMapa {
protected:
	std::vector<std::pair<double, double> > frontera; // (y, x)
	int cant_vertices;

	/*
	 * Recalcula los valores extremos que ocupa la figura dado los valores del
	 * nuevo vértice (y, x) = (latitud, longitud) a agregar
	 */
	void actualizarExtremos(const double y, const double x);

	/*
	 * Agrega un vértice a la figura dados los valores de la coordenada
	 * (y, x) = (latitud, longitud)
	 */
	void agregarVertice(const double y, const double x);

public:
	/*
	 * Inicializa la instancia con 0 vertices
	 */
	ElementoPoligonal();

	/*
	 * Libera los recursos utilizados por la clase.
	 */
	virtual ~ElementoPoligonal() {}

	/*
	 * Retorna el área de la superficie del elemento, calculada mediante el
	 * algoritmo PRODUCTO CRUZ.
	 */
	virtual double getArea();

	/*
	 * Dado un valor de longitud (y) y otro de latitud (x) retorna true si esa
	 * coordenada es un punto contenido en el interior de la figura mediante el
	 * algoritmo PNPOLY.
	 */
	virtual bool pertenece(const double y, const double x);

	/*
	 * Retorna la cantidad de vértices que tiene la figura
	 */
	int getCantidadVertices() const;

	/*
	 * Parsea una linea con el formato:
	 * 		<lat1>,<long1>,...<latN>,<longN>
	 * 	y luego almacena cada uno de los pares como un nuevo vértice (y, x)
	 * 	Luego, actualiza los valores extremos de la figura.
	 */
	virtual void parsear(std::stringstream & linea_a_parsear);
};

#endif /* ELEMENTOPOLIGONAL_H_ */
