/*
 * Point.cpp
 *
 *  Created on: 19 дек. 2015 г.
 *      Author: artemcherkasov
 */

#include "../Headers/Point.h"

int Point::getX() const {
	return x;
}

void Point::setX(int x) {
	this->x = x;
}

int Point::getY() const {
	return y;
}

void Point::setY(int y) {
	this->y = y;
}
