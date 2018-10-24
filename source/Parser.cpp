/* Parser.cpp */

#include "Parser.h"
#include <sstream>
#include <string>
#include <fstream>
#include <queue>
#include <vector>
#include "ComparadorPorPrioridades.h"

#include "Agua.h"
#include "Manzana.h"
#include "Boulevard.h"
#include "EdificioPublico.h"
#include "EdificioPrivado.h"
#include "Arbol.h"
#include "Semaforo.h"
#include "ElementoMapa.h"
#include "Definiciones.h"

#define CANT_ARGS_ESPERADOS 3

Parser::Parser() :
		lat_sup(0), lat_inf(0), long_izq(0), long_der(0), altura_pantalla(0),
		ancho_pantalla(0) {
	this->inicializarCodificacion();
}

int Parser::parsearLineaComandos(int argc, char ** argv) {
	if (argc == CANT_ARGS_ESPERADOS) {
		this->arch_configuracion = argv[1];
		this->arch_objetos = argv[2];

		configuracion.open(this->arch_configuracion.c_str(), std::ifstream::in);
		mapa.open(this->arch_objetos.c_str(), std::ifstream::in);
		if (mapa.is_open() && configuracion.is_open()) {
			return EXITO;
		} else {
			this->cerrarArchivo(mapa);
			this->cerrarArchivo(configuracion);
		}
	}
	return ERROR;
}

void Parser::cerrarArchivo(std::ifstream & archivo) {
	if (archivo.is_open())
		archivo.close();
}

int Parser::parsearConfiguracion() {
	if (this->configuracion.is_open()) {
		this->configuracion >> this->lat_sup >> this->lat_inf >> this->long_izq
				>> this->long_der >> this->altura_pantalla
				>> this->ancho_pantalla;
		this->cerrarArchivo(this->configuracion);
		return EXITO;
	} else {
		return ERROR;
	}
}

void Parser::inicializarCodificacion() {
	this->codificacion_objetos["agua"] = agua;
	this->codificacion_objetos["manzana"] = manzana;
	this->codificacion_objetos["boulevard"] = boulevard;
	this->codificacion_objetos["edificio-publico"] = edificiopublico;
	this->codificacion_objetos["edificio-privado"] = edificioprivado;
	this->codificacion_objetos["arbol"] = arbol;
	this->codificacion_objetos["semaforo"] = semaforo;
}

void Parser::copiarColaEnVector(
		std::priority_queue<ElementoMapa *, std::vector<ElementoMapa *>,
				ComparadorPorPrioridades> & lista_objetos,
		std::vector<ElementoMapa *> & lista_objetos_vect) {
	while (!lista_objetos.empty()) {
		lista_objetos_vect.push_back(lista_objetos.top());
		lista_objetos.pop();
	}
}

int Parser::parsearMapa(std::vector<ElementoMapa *> & lista_objetos_vect,
		std::vector<Arbol *> & lista_arboles,
		std::vector<EdificioPublico *> & lista_edif_publicos,
		std::vector<EdificioPrivado *> & lista_edif_privados) {
	if (this->mapa.is_open()) {
		std::priority_queue<ElementoMapa *, std::vector<ElementoMapa *>,
				ComparadorPorPrioridades> lista_objetos;
		std::string linea("");
		while (!this->mapa.eof()) {
			std::getline(this->mapa, linea);
			std::stringstream linea_stream(linea);
			std::string tipo_objeto("");
			std::getline(linea_stream, tipo_objeto, ',');

			ElementoMapa * elemento_actual;

			switch (this->codificacion_objetos[tipo_objeto]) {
			case agua: {
				elemento_actual = new Agua;
				break;
			}
			case manzana: {
				elemento_actual = new Manzana;
				break;
			}
			case boulevard: {
				elemento_actual = new Boulevard;
				break;
			}
			case edificiopublico: {
				elemento_actual = new EdificioPublico;
				lista_edif_publicos.push_back(
						(EdificioPublico*) elemento_actual);
				break;
			}
			case edificioprivado: {
				elemento_actual = new EdificioPrivado;
				lista_edif_privados.push_back(
						(EdificioPrivado*) elemento_actual);
				break;
			}
			case arbol: {
				elemento_actual = new Arbol;
				lista_arboles.push_back((Arbol *) elemento_actual);
				break;
			}
			case semaforo: {
				elemento_actual = new Semaforo;
				break;
			}
			}

			elemento_actual->parsear(linea_stream);
			lista_objetos.push(elemento_actual);
		}
		this->copiarColaEnVector(lista_objetos, lista_objetos_vect);
		this->cerrarArchivo(this->mapa);
		return EXITO;
	} else {
		return ERROR;
	}
}

int Parser::getAlturaPantalla() const {
	return altura_pantalla;
}

int Parser::getAnchoPantalla() const {
	return ancho_pantalla;
}

double Parser::getLatInf() const {
	return lat_inf;
}

double Parser::getLatSup() const {
	return lat_sup;
}

double Parser::getLongDer() const {
	return long_der;
}

double Parser::getLongIzq() const {
	return long_izq;
}
