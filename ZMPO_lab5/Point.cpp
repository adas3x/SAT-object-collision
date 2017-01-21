#include "stdafx.h"
#include "Point.h"
#include <math.h>  
#define PI 3.14159265

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}

void Point::shift(double x, double y) {
	this->x += x;
	this->y += y;
}

void Point::rotate(int degrees) {
	double angle = degrees*PI / 180;
	double sinus = sin(angle);
	double cosinus = cos(angle);
	double newX = round(cosinus * x - sinus * y);
	double newY = round(sinus * x + cosinus * y);
	x = newX;
	y = newY;
}

double Point::getX() {
	return x;
}


double Point::getY() {
	return y;
}

void Point::setX(double x) {
	this->x = x;
}

void Point::setY(double y) {
	this->y = y;
}

std::string Point::toString() {
	std::ostringstream  ss;
	ss << x << ";" << y;
	return ss.str();
}

double Point::magnitude() {
	return sqrt(x*x + y*y);
}

Point::~Point() {
}
