/* Parser.h */

#ifndef PARSER_H_
#define PARSER_H_

#define EXITO 0
#define ERROR -1

#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include "ElementoMapa.h"
#include "Arbol.h"
#include "EdificioPrivado.h"
#include "EdificioPublico.h"
#include "ComparadorPorPrioridades.h"

/*
 * Clase responsable de abrir y parsear los archivos de entrada de
 * configuración y objetos y que puede retornar los elementos a graficar
 * en el mapa en una estructura ordenada según la prioridad de dibujo que
 * tiene cada uno de ellos.
 */
class Parser {
	std::string arch_configuracion;
	std::string arch_objetos;

	std::ifstream configuracion;
	std::ifstream mapa;

	double lat_sup;
	double lat_inf;
	double long_izq;
	double long_der;
	int altura_pantalla;
	int ancho_pantalla;

	enum clases_en_int {
		agua,
		manzana,
		boulevard,
		edificiopublico,
		edificioprivado,
		arbol,
		semaforo
	};

	/*
	 * Si el archivo recibido como argumento está abierto, lo cierra.
	 */
	void cerrarArchivo(std::ifstream & archivo);

	std::map<std::string, int> codificacion_objetos;

	/*
	 * Inicializa el map de codificacion_objetos asignando un valor entero del
	 * enum a cada uno de los id_objeto en string que se leen desde el archivo
	 * de entrada.
	 */
	void inicializarCodificacion();

	/*
	 * Copia la cola de prioridades que tienen los elementos ordenados según
	 * el orden en que hay que graficarlos en el vector que se pasó por
	 * referencia.
	 * obs: la cola de prioridades queda vacía al finalizar por ser pasada por
	 * referencia.
	 */
	void copiarColaEnVector(
			std::priority_queue<ElementoMapa *, std::vector<ElementoMapa *>,
					ComparadorPorPrioridades> & lista_objetos,
			std::vector<ElementoMapa *> & lista_objetos_vect);

public:
	/*
	 * Inicializa los atributos con valor 0, y luego inicializa la codificación
	 * necesaria para poder interpretar el archivo de objetos.
	 */
	Parser();

	/*
	 * Parsea la línea de comandos recibida por el programa y extrae
	 * los nombres del archivo de configuración y del archivo de
	 * objetos.
	 * Luego abre los archivos para verificar que existan y retorna EXITO;
	 * Si la cantidad de argumentos no coincide con la esperada, o alguno de
	 * los archivos no existe o no pudo ser abierto, retorna ERROR.
	 */
	int parsearLineaComandos(int argc, char ** argv);

	/*
	 * Si el archivo de configuración está abierto, parsea los atributos que
	 * contiene y los guarda en variables que luego pueden ser consultadas,
	 * luego cierra el archivo y retorna EXITO.
	 * Si el archivo no estaba abierto, retorna ERROR.
	 * Se espera que el archivo esté bien formado de la siguiente forma:
	 * 		<latitud_superior>\n
	 * 		<latitud_inferior>\n
	 * 		<longitud_izquierda>\n
	 * 		<longitud_derecha>\n
	 * 		<altura_pantalla>\n
	 * 		<ancho_pantalla>\n
	 */
	int parsearConfiguracion();

	/*
	 * Si el archivo de objetos está abierto, genera la lista de objetos
	 * ordenados según el orden de prioridad en que deben dibujarse y estos se
	 * almacenan en lista_objetos_vect pasado por referencia.
	 * También genera una lista de arboles, de edificios privados y de edificios
	 * públicos en los vectores pasados por referencia.
	 * Luego cierra el archivo y retorna EXITO.
	 * Si el archivo no estaba abierto, retorna ERROR.
	 */
	int parsearMapa(std::vector<ElementoMapa *> & lista_objetos_vect,
			std::vector<Arbol *> & lista_arboles,
			std::vector<EdificioPublico *> & lista_edif_publicos,
			std::vector<EdificioPrivado *> & lista_edif_privados);

	/*
	 *  Retorna el alto en cantidad de celdas de la pantalla obtenida del
	 *  archivo de configuración.
	 */
	int getAlturaPantalla() const;

	/*
	 *  Retorna el ancho en cantidad de celdas de la pantalla obtenida del
	 *  archivo de configuración.
	 */
	int getAnchoPantalla() const;

	/*
	 * Retorna la latitud inferior obtenida del archivo de configuración.
	 */
	double getLatInf() const;

	/*
	 * Retorna la latitud superior obtenida del archivo de configuración.
	 */
	double getLatSup() const;

	/*
	 * Retorna la longitud derecha obtenida del archivo de configuración.
	 */
	double getLongDer() const;

	/*
	 * Retorna la longitud izquiera obtenida del archivo de configuración.
	 */
	double getLongIzq() const;
};

#endif /* PARSER_H_ */
