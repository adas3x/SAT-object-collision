#include "stdafx.h"
#include "Figure.h"

void Figure::rotate(int degrees) {
	for (Point *point:points) {
		point->rotate(degrees);
	}
}

void Figure::shift(double x, double y) {
	for (Point *point : points) {
		point->shift(x,y);
	}
}

bool Figure::isColliding(Figure &other) {
	if (isOtherCircle(other)) {
		return other.isColliding(*this);
	}
	else {
		setNormals();
		other.setNormals();
		for (Vector* normal : normals) {
			if (isGap(other, *normal)) {
				return false;
			}
		}
		for (Vector *otherNormal : other.normals) {
			if (other.isGap(*this, *otherNormal)) {
				return false;
			}
		}

		return true;

	}
}




std::string Figure::toString() {
	std::ostringstream  ss;
	for (Point *point:points) {
		ss << "Point(";
		ss<<point->toString();
		ss << ");";
	}
	return ss.str();
}

std::vector<Point*> Figure::getPoints() {
	return points;
}

void Figure::setNormals() {
	if (normals.empty()) {
		for (int i = 0; i < points.size()-1 ; i++) {
			Vector vectorBetwenPoints = Vector::makeVector(*points.at(i), *points.at(i+1));
			Vector *normal = new Vector(vectorBetwenPoints.getNormal());
			normals.push_back(normal);
		}
		Vector vectorBetwenFirstAndLast = Vector::makeVector(*points.at(points.size() - 1), *points.at(0));
		Vector *normal = new Vector(vectorBetwenFirstAndLast.getNormal());
		normals.push_back(normal);
	}
	
}

double Figure::minDotProduct(Vector & axis) {
	double minValue = dotProduct(*points.at(0), axis);
	for (Point *point:points) {
		double valueOfDotProduct = dotProduct(*point, axis);
		if (minValue > valueOfDotProduct) {
			minValue = valueOfDotProduct;
		}
	}
	return minValue;
}

double Figure::maxDotProduct(Vector & axis) {
	double maxValue = dotProduct(*points.at(0), axis);
	for (Point *point : points) {
		double valueOfDotProduct = dotProduct(*point, axis);
		if (maxValue < valueOfDotProduct) {
			maxValue = valueOfDotProduct;
		}
	}
	return maxValue;
}

bool Figure::isGap(Figure & other, Vector & axis) {
	double figureMaxDotProduct = maxDotProduct(axis);
	double figureMinDotProduct = minDotProduct(axis);
	double otherFigureMaxDotProduct = other.maxDotProduct(axis);
	double otherFigureMinDotProduct = other.minDotProduct(axis);

	if (otherFigureMinDotProduct > figureMaxDotProduct || figureMinDotProduct > otherFigureMaxDotProduct) {
		return true;
	}
	return false;
}

bool Figure::isOtherCircle(Figure & other) {
	return other.points.size() == 1;
}

double Figure::dotProduct(Point & first, Point & second) {
	return (first.getX() * second.getX()) + (first.getY() * second.getY());
}

Figure::~Figure() {
	for (Point *point : points) {
		delete point;
	}
	for (Vector *normal : normals) {
		delete normal;
	}
	
}