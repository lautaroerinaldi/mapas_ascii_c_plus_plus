/* ElementoMapa.cpp */

#include "ElementoMapa.h"

ElementoMapa::ElementoMapa():lat_min(0), lat_max(0), long_min(0), long_max(0){
}

double ElementoMapa::getLatMax() const {
	return lat_max;
}

double ElementoMapa::getLatMin() const {
	return lat_min;
}

double ElementoMapa::getLongMax() const {
	return long_max;
}

double ElementoMapa::getLongMin() const {
	return long_min;
}
