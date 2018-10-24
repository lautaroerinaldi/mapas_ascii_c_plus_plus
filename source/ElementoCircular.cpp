/* ElementoCircular.cpp */

#include <math.h>
#include "ElementoCircular.h"
#include "Definiciones.h"

ElementoCircular::ElementoCircular(): radio(0), x_centro(0), y_centro(0){
}

double ElementoCircular::getRadio() const {
	return this->radio;
}

double ElementoCircular::getCentroX() const {
	return this->x_centro;
}

double ElementoCircular::getCentroY() const {
	return this->y_centro;
}

bool ElementoCircular::pertenece(const double y, const double x) {
	double dist_y = pow((y - this->y_centro) * GRADO_LATITUD_EN_KM, 2);
	double dist_x = pow((x - this->x_centro) * GRADO_LONGITUD_EN_KM, 2);
	if (dist_x + dist_y <= pow(this->radio, 2))
		return true;
	else
		return false;
}

void ElementoCircular::parsear(std::stringstream & linea_a_parsear) {
	double latitud, longitud, radio;
	char indic;
	linea_a_parsear >> latitud >> indic >> longitud >> indic >> radio >> indic;
	this->y_centro = latitud;
	this->x_centro = longitud;
	this->radio = radio;
	this->lat_min = this->y_centro - this->radio / GRADO_LATITUD_EN_KM;
	this->lat_max = this->y_centro + this->radio / GRADO_LATITUD_EN_KM;
	this->long_min = this->x_centro - this->radio / GRADO_LONGITUD_EN_KM;
	this->long_max = this->x_centro + this->radio / GRADO_LONGITUD_EN_KM;
}

double ElementoCircular::getArea() {
	return ( M_PI * pow(this->radio, 2) * KM2_A_M2);
}
