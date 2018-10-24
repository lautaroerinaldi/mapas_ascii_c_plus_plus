/* ElementoPoligonal.cpp */

#include "ElementoPoligonal.h"
#include "Definiciones.h"
#include <utility>
#include <vector>

ElementoPoligonal::ElementoPoligonal() :
		cant_vertices(0) {
}

bool ElementoPoligonal::pertenece(const double y, const double x) {
	int i, j, c = 0;
	// uso una referencia al vector que contiene los vertices del poligono
	// para que el codigo sea más legible
	std::vector<std::pair<double, double> > & v = this->frontera;
	for (i = 0, j = this->cant_vertices - 1; i < this->cant_vertices; j = i++) {
		if (((v[i].first > y) != (v[j].first > y))
				&& (x
						< (v[j].second - v[i].second) * (y - v[i].first)
								/ (v[j].first - v[i].first) + v[i].second))
			c = !c;
	}
	return c;
}

void ElementoPoligonal::actualizarExtremos(const double y, const double x) {
	if (this->cant_vertices == 1) {
		this->lat_min = y;
		this->lat_max = y;
		this->long_min = x;
		this->long_max = x;
	} else {
		if (y < this->lat_min)
			this->lat_min = y;
		if (y > this->lat_max)
			this->lat_max = y;
		if (x < this->long_min)
			this->long_min = x;
		if (x > this->long_max)
			this->long_max = x;
	}
}

void ElementoPoligonal::agregarVertice(const double y, const double x) {
	this->frontera.push_back(std::pair<double, double>(y, x));
	++this->cant_vertices;
	this->actualizarExtremos(y, x);
}

int ElementoPoligonal::getCantidadVertices() const {
	return this->cant_vertices;
}

void ElementoPoligonal::parsear(std::stringstream & linea_a_parsear) {
	double latitud, longitud;
	char indicador;
	while (!linea_a_parsear.eof() && !linea_a_parsear.fail()) {
		linea_a_parsear >> latitud >> indicador >> longitud >> indicador;
		this->agregarVertice(latitud, longitud);
	}
}

double ElementoPoligonal::getArea() {
	double sum = 0;
	int & n = this->cant_vertices;

	std::vector<std::pair<double, double> > & v = this->frontera;

	double y0 = this->lat_min;
	double x0 = this->long_min;
	// las referencias tienen que ser desde el (0,0), por eso resto (y0, x0)
	sum = (v[0].second - x0) * (v[n - 1].first - y0)
			- (v[n - 1].second - x0) * (v[0].first - y0);

	for (int i = 0; i < n - 1; ++i)
		sum += (v[i + 1].second - x0) * (v[i].first - y0)
				- (v[i].second - x0) * (v[i + 1].first - y0);

	// hay que hacer la conversion de latitudes y longitudes a kilometros
	double area = (sum / 2) * KM2_A_M2 * GRADO_LATITUD_EN_KM
			* GRADO_LONGITUD_EN_KM;

	return area;
}
