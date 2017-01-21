#include "stdafx.h"
#include "Vector.h"


Vector::Vector(double x, double y):Point(x,y) {
}

Vector Vector::getNormal() {
	return Vector(-y,x);
}

Vector Vector::makeVector(Point & first, Point & second) {
	return Vector(second.getX() - first.getX(), second.getY() - first.getY());
}


Vector::~Vector() {
}
