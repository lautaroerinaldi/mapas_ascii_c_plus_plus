/* EdificioPublico.h */

#ifndef EDIFICIOPUBLICO_H_
#define EDIFICIOPUBLICO_H_

#include "ElementoPoligonal.h"
#include <string>

/*
 * Clase que representa un objeto de tipo Edificio Público del mapa.
 * Tiene las particularidad de que este tipo de edificios tienen un nombre,
 * y un identificador en letra mayúscula que se incrementa automáticamente
 * desde la 'A' hasta la 'Z', y luego vuelve a comenzar con la 'A'.
 */
class EdificioPublico: public ElementoPoligonal {
	static unsigned int prioridad;
	char identificador;
	static char idx;
	std::string nombre;

	/*
	 * Incrementa el atributo de clase idx, que va a ser el identificador de la
	 * próxima instancia edificio publico creada.
	 * "idx" son letras mayúsculas. Cuando se llega a la Z, vuelve a comenzar
	 * con la letra A.
	 */
	static void avanzarIdx();

public:
	/*
	 * Inicializa la instancia utilizando como identificador la letra que esta
	 * almacenada en "idx", cuyo valor se incrementa automáticamente por cada
	 * objeto que se instancie.
	 */
	EdificioPublico();

	/*
	 * Retorna el nombre del edificio público.
	 */
	const std::string & getNombre() const;

	/*
	 * Parsea una linea con el formato:
	 * 		<nombre_edificio_publico>,<lat1>,<long1>,...<latN>,<longN>
	 * 	y luego almacena el nombre del edificio, y cada uno de los pares como
	 * 	un nuevo vértice (y, x)
	 * 	Luego, actualiza los valores extremos de la figura.
	 */
	virtual void parsear(std::stringstream & linea_a_parsear);

	/*
	 * Retorna la prioridad en el orden de dibujo de la clase.
	 */
	unsigned int getPrioridad();

	/*
	 * Retorna el caracter ASCII que se utiliza para representar a la instancia
	 * actual la clase al dibujarla.
	 */
	char getIdentificador();

	/*
	 * Retorna el caracter identificador y el nombre del edificio público con
	 * el formato:
	 * 		identificador: nombre
	 */
	std::string getReferencia() const;
};

#endif /* EDIFICIOPUBLICO_H_ */
