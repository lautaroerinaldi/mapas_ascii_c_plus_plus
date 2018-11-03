# Sistema de información geográfica, con representaciones mediante mapas en ASCII Art.

## Descripción

En el presente proyecto, se desarrolla un sistema de graficación de información geográfica en el que la cartografía de la ciudad no contempla únicamente el trazado de las manzanas, sino también la ubicación de luminarias, semáforos, árboles y los planos de las edificaciones.

Este sistema recibe por medio de un archivo la especificación de los distintos elementos geográficos y sus posiciones en latitud­-longitud para graficarlos en un plano en formato simple ASCII Art. La graficación de elementos se realiza en un archivo de tipo texto.

Además de la herramienta de graficación, cuenta con un generador de estadísticas sobre los elementos que se encuentran en la pantalla. De esa forma, el usuario puede comparar cantidades como el espacio edificado con el espacio verde que posee cierta área.


## Motivación

El presente proyecto fue elaborado como trabajo práctico académico para la materia Taller de Programación I de la Facultad de Ingeniería de la Universidad de Buenos Aires. El mismo, se desarrolló durante el segundo cuatrimestre del año 2015.

## Compilación:

Desde la consola de linux, una vez dentro de la carpeta **source**, ejecutar la siguiente instrucción:
```
make -f Makefile
```
Si se desean eliminar los archivos generados por dicho Makefile, se debe ejecutar:
```
make clean
```

## Modo de uso:

Consultar **enunciado_mapas_ascii.pdf**

## Autor
   - Lautaro Ezequiel Rinaldi.
