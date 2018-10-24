/* tp3_mapa_ascii.cpp */

#include <iostream>
#include "Parser.h"
#include "Mapa.h"
#define EJECUCION_OK 0
#define EJECUCION_FALLO 1

int main(int argc, char ** argv) {
	Parser parser;
	if (parser.parsearLineaComandos(argc, argv) == EXITO) {
		parser.parsearConfiguracion();

		Mapa mapa(parser);
		mapa.generarMapa();

		std::stringstream referencias;
		mapa.getReferencias(referencias);

		std::cout << "Superficie total edificada: "
				<< mapa.getSuperficieEdificada() << " metros cuadrados."
				<< std::endl;
		std::cout << "Superficie total arbolada: "
				<< mapa.getSuperficieArbolada() << " metros cuadrados."
				<< std::endl;
		mapa.mostrarMapa();

		std::cout << referencias.str();

		return EJECUCION_OK;
	} else {
		std::cerr << "Archivo inexistente";
		return EJECUCION_FALLO;
	}
}
