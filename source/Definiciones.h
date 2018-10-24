/* Definiciones.h */

#ifndef DEFINICIONES_H_
#define DEFINICIONES_H_

/*
 * Prioridades para establecer el orden de dibujo
 */
#define PRIOR_AGUA 1
#define PRIOR_MANZANA 2
#define PRIOR_BOULEVARD 3
#define PRIOR_EDIF_PUBLICO 4
#define PRIOR_EDIF_PRIVADO 5
#define PRIOR_ARBOL 6
#define PRIOR_SEMAFORO 7

/*
 * Caracteres que identifican a cada objeto al dibujarlos
 * obs: el edificio publico no está porque el identificador es una letra
 * mayúscula que es diferente para cada instancia de la clase.
 */
#define IDENT_CALLE ' '
#define IDENT_AGUA '-'
#define IDENT_MANZANA 'm'
#define IDENT_BOULEVARD 'b'
#define IDENT_EDIF_PRIVADO 'e'
#define IDENT_ARBOL '@'
#define IDENT_SEMAFORO '#'

/*
 * Unidades de conversión
 */
#define KM2_A_M2 1000000
#define GRADO_LATITUD_EN_KM 111.131
#define GRADO_LONGITUD_EN_KM 111.319

#endif /* DEFINICIONES_H_ */
