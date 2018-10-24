/* Mapa.cpp */

#include "Mapa.h"
#include "Definiciones.h"
#include <iostream>
#include <vector>
#include <math.h>

Mapa::Mapa(Parser & parser) :
		alto(parser.getAlturaPantalla()), ancho(parser.getAnchoPantalla()),
		lat_sup(parser.getLatSup()), lat_inf(parser.getLatInf()),
		long_izq(parser.getLongIzq()), long_der(parser.getLongDer()),
		ancho_celda_grados_long(0), alto_celda_grados_lat(0), parser(parser) {
	this->mapa = new char *[alto];
	for (int i = 0; i < alto; ++i)
		this->mapa[i] = new char[ancho];
	this->calcularParametros();
	this->inicializarMapa();
}

void Mapa::inicializarMapa() {
	// inicializo todas las celdas con calle
	for (int i = 0; i < this->alto; ++i) {
		for (int j = 0; j < this->ancho; ++j) {
			this->mapa[i][j] = IDENT_CALLE;
		}
	}
}

void Mapa::calcularParametros() {
	this->ancho_celda_grados_long = (this->long_der - this->long_izq)
			/ this->ancho;
	this->alto_celda_grados_lat = (this->lat_sup - this->lat_inf) / this->alto;
}

int Mapa::calcularLongMinIteracion(const double long_min_objeto) const {
	int long_min = floor(
			((long_min_objeto - this->long_izq) / this->ancho_celda_grados_long)
					- 0.5);
	if (long_min < 0)
		long_min = 0;
	return long_min;
}

int Mapa::calcularLongMaxIteracion(const double long_max_objeto) const {
	int long_max = ceil(
			((long_max_objeto - this->long_izq) / this->ancho_celda_grados_long)
					- 0.5);
	if (long_max > this->ancho)
		long_max = this->ancho;
	return long_max;
}

int Mapa::calcularLatMinIteracion(const double lat_max_objeto) const {
	int lat_min = floor(
			((this->lat_sup - lat_max_objeto) / this->alto_celda_grados_lat)
					- 0.5);
	if (lat_min < 0)
		lat_min = 0;
	return lat_min;
}

int Mapa::calcularLatMaxIteracion(const double lat_min_objeto) const {
	int lat_max = ceil(
			((this->lat_sup - lat_min_objeto) / this->alto_celda_grados_lat)
					- 0.5);
	if (lat_max > this->alto)
		lat_max = this->alto;
	return lat_max;
}

void Mapa::generarMapa() {
	this->parser.parsearMapa(this->lista_objetos_vect, this->lista_arboles,
			this->lista_edif_publicos, this->lista_edif_privados);
	for (unsigned int idx = 0; idx < this->lista_objetos_vect.size(); ++idx) {
		int long_min = this->calcularLongMinIteracion(
				lista_objetos_vect[idx]->getLongMin());
		int long_max = this->calcularLongMaxIteracion(
				lista_objetos_vect[idx]->getLongMax());
		int lat_min = this->calcularLatMinIteracion(
				lista_objetos_vect[idx]->getLatMax());
		int lat_max = this->calcularLatMaxIteracion(
				lista_objetos_vect[idx]->getLatMin());

		for (int i = lat_min; i < lat_max; ++i) {
			for (int j = long_min; j < long_max; ++j) {
				// se suma 0.5 para que mida el centro de las celdas
				double y = this->lat_sup
						- this->alto_celda_grados_lat * (i + 0.5);
				double x = this->ancho_celda_grados_long * (j + 0.5)
						+ this->long_izq;
				if (this->lista_objetos_vect[idx]->pertenece(y, x))
					this->mapa[i][j] =
							this->lista_objetos_vect[idx]->getIdentificador();
			}
		}
	}
}

void Mapa::mostrarMapa() const {
	for (int i = 0; i < this->alto; ++i) {
		for (int j = 0; j < this->ancho; ++j) {
			std::cout << this->mapa[i][j];
		}
		std::cout << std::endl;
	}
}

Mapa::~Mapa() {
	this->eliminarObjetos();
	for (int i = 0; i < alto; ++i)
		delete[] this->mapa[i];
	delete[] this->mapa;
}

unsigned int Mapa::getSuperficieArbolada() const {
	double supeficie_acum = 0;
	for (unsigned int i = 0; i < this->lista_arboles.size(); ++i) {
		supeficie_acum += this->lista_arboles[i]->getArea();
	}
	return round(supeficie_acum);
}

void Mapa::eliminarObjetos() {
	for (unsigned int idx = 0; idx < this->lista_objetos_vect.size(); ++idx)
		delete this->lista_objetos_vect[idx];
}

unsigned int Mapa::getSuperficieEdificada() const {
	double supeficie_acum = 0;
	for (unsigned int i = 0; i < this->lista_edif_publicos.size(); ++i) {
		supeficie_acum += this->lista_edif_publicos[i]->getArea();
	}
	for (unsigned int i = 0; i < this->lista_edif_privados.size(); ++i) {
		supeficie_acum += this->lista_edif_privados[i]->getArea();
	}
	return round(supeficie_acum);
}

void Mapa::getReferencias(std::stringstream & referencias) const {
	for (unsigned int i = 0; i < this->lista_edif_publicos.size(); ++i) {
		referencias << lista_edif_publicos[i]->getReferencia() << std::endl;
	}
}
