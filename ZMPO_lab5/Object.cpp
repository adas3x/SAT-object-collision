#include "stdafx.h"
#include "Object.h"


Object::Object(int id) {
	this->id = id;
}



void Object::addBaseTriangle(Point A, Point B, Point C) {
	figures.push_back(new BaseTriangle(A, B, C));
}

void Object::addBaseRectangle(Point lowerLeft, double length, double height) {
	figures.push_back(new BaseRectangle(lowerLeft, length, height));
}

void Object::addBaseTrapeze(Point lowerLeft, Point lowerRight, Point upperLeft, Point upperRight) {
	figures.push_back(new BaseTrapeze(lowerLeft, lowerRight, upperLeft, upperRight));
}

void Object::addBaseCircle(Point middlePoint, double radius) {
	figures.push_back(new BaseCircle(middlePoint, radius));
}

void Object::rotate(int degrees) {
	for (Figure* figure : figures) {
		figure->rotate(degrees);
	}
}

void Object::shift(double x, double y) {
	for (Figure *figure : figures) {
		figure->shift(x, y);
	}
}

bool Object::isColliding(Object &other) {
	for (Figure *figure : figures) {
		for (Figure *otherFigure : other.figures) {
			if (figure->isColliding(*otherFigure)) {
				return true;
			}
		}
	}
	return false;
	
}

int Object::getId() {
	return id;
}


Object::~Object() {
	for (int i = figures.size() - 1; i = 0; i--) {
		delete figures.at(i);
	}
}
