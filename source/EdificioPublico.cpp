/* EdificioPublico.cpp */

#include "EdificioPublico.h"
#include "Definiciones.h"
#include <string>

char EdificioPublico::idx = 'A';
unsigned int EdificioPublico::prioridad = PRIOR_EDIF_PUBLICO;

EdificioPublico::EdificioPublico() :
		identificador(EdificioPublico::idx) {
	EdificioPublico::avanzarIdx();
}

void EdificioPublico::avanzarIdx() {
	++EdificioPublico::idx;
	if (EdificioPublico::idx > 'Z')
		EdificioPublico::idx = 'A';
}

const std::string & EdificioPublico::getNombre() const {
	return this->nombre;
}

unsigned int EdificioPublico::getPrioridad() {
	return EdificioPublico::prioridad;
}

char EdificioPublico::getIdentificador() {
	return this->identificador;
}

void EdificioPublico::parsear(std::stringstream & linea_a_parsear) {
	std::string nombre_edificio("");
	std::getline(linea_a_parsear, nombre_edificio, ',');
	this->nombre = nombre_edificio;
	ElementoPoligonal::parsear(linea_a_parsear);
}

std::string EdificioPublico::getReferencia() const{
	std::ostringstream auxiliar;
	auxiliar << this->identificador << ": " << this->nombre;
	return auxiliar.str();
}
