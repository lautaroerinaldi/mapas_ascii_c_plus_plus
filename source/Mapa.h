/* Mapa.h */

#ifndef MAPA_H_
#define MAPA_H_
#include <vector>
#include "Parser.h"

/*
 * Clase que genera el mapa en ASCII art y que puede calcular la superficie
 * arbolada, la edificada y las referencias de los edificios públicos.
 */
class Mapa {
	int alto;
	int ancho;

	double lat_sup;
	double lat_inf;
	double long_izq;
	double long_der;

	double ancho_celda_grados_long;
	double alto_celda_grados_lat;

	char ** mapa;
	Parser & parser;

	std::vector<ElementoMapa *> lista_objetos_vect;
	std::vector<Arbol *> lista_arboles;
	std::vector<EdificioPublico *> lista_edif_publicos;
	std::vector<EdificioPrivado *> lista_edif_privados;

	/*
	 * Calcula el ancho y el alto de cada celda del mapa en grados.
	 */
	void calcularParametros();

	/*
	 * Inicializa una matriz que representa el mapa (con tamaño según el ancho
	 * y el alto) obtenidos previamente del parser con el caracter que
	 * representa a la CALLE.
	 */
	void inicializarMapa();

	/*
	 * Recorre el vector que tiene los objetos (o elementos del mapa) y libera
	 * la memoria dinámica que ellos utilizan.
	 */
	void eliminarObjetos();

	/*
	 * Dada la longitud extrema izquieda que ocupa un elemento del mapa,
	 * calcula el número de la celda desde donde se debe empezar a iterar
	 * para saber si las celdas a su derecha están pertenecen a la figura.
	 */
	int calcularLongMinIteracion(const double long_min_objeto) const;

	/*
	 * Dada la longitud extrema derecha que ocupa un elemento del mapa, calcula
	 * el número de la celda hasta donde se debe iterar para saber si las
	 * celdas a su izquierda están pertenecen a la figura.
	 */
	int calcularLongMaxIteracion(const double long_max_objeto) const;

	/*
	 * Dada la latitud extrema superior que ocupa un elemento del mapa,
	 * calcula el número de la celda desde donde se debe empezar a iterar
	 * para saber si las celdas por encima de esta pertenecen a la figura.
	 * obs: para calcular la latitud mínima, se necesita la latitud máxima
	 */
	int calcularLatMinIteracion(const double lat_max_objeto) const;

	/*
	 * Dada la latitud extrema inferior que ocupa un elemento del mapa, calcula
	 * el número de la celda hasta donde se se debe iterar para saber si las
	 * celdas por encima de esta pertenecen a la figura.
	 * obs: para calcular la latitud mínima, se necesita la latitud máxima
	 */
	int calcularLatMaxIteracion(const double lat_min_objeto) const;

public:
	/*
	 * Inicializa los atributos de la clase con los valores obtenidos por el
	 * parser del archivo de configuración e inicializa las estructuras que van
	 * a representar al mapa.
	 */
	explicit Mapa(Parser & parser);

	/*
	 * A partir de los elementos que va leyendo el parser, genera la matriz que
	 * representa al mapa con los objetos representadas en ASCII art según el
	 * identificador que tiene cada uno de ellos.
	 */
	void generarMapa();

	/*
	 * Recorre el mapa y muestra por salida estándar los caracteres que
	 * representan a los objetos en ASCII art.
	 */
	void mostrarMapa() const;

	/*
	 * Libera los recursos utilizados por el mapa
	 */
	~Mapa();

	/*
	 * Retorna la superficie arbolada en el mapa redondeada a un entero.
	 */
	unsigned int getSuperficieArbolada() const;

	/*
	 * Retorna la superficie edificada en el mapa redondeada a un entero.
	 */
	unsigned int getSuperficieEdificada() const;

	/*
	 * Genera una lista con las referencias de los edificios públicos
	 * y los retorna en el atributo pasado por referencia
	 */
	void getReferencias(std::stringstream & referencias) const;
};

#endif /* MAPA_H_ */
