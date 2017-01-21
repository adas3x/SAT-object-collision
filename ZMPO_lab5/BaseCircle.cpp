#include "stdafx.h"
#include "BaseCircle.h"


BaseCircle::BaseCircle(Point &middle, double radius) {
	points.push_back(new Point(middle));
	this->radius = radius;
}

BaseCircle::~BaseCircle() {
}

bool BaseCircle::isColliding(Figure & other) {
	if (isCollidingCircle(other)) {
		Figure* pointer = &other;
		BaseCircle *otherCircle = dynamic_cast<BaseCircle*>(pointer);
		return isCirclesColliding(*otherCircle);
	}
	
	if (isCircleContainFigure(other) || ifCircleIsInsideFigure(other)) { return true; }

	for (int i = 1; i < other.getPoints().size() - 1; i++) {
		bool result = isCollidingAlgorithm(*other.getPoints().at(i - 1), *other.getPoints().at(i));
		if (result) {
			return true;
		}
	}
	if (isCollidingAlgorithm(*other.getPoints().at(other.getPoints().size() - 1), *other.getPoints().at(0))) {
		return true;
	}
	return false;
	
}
bool BaseCircle::isCollidingAlgorithm(Point &pointA, Point &pointB) {
	Point middle(*points.at(0));
	double a;
	double b;
	double minX;
	double maxX;
	double minY;
	double maxY;
	double middleX;
	double middleY;
	if (pointB.getX() - pointA.getX() != 0) {
		a = (pointB.getY() - pointA.getY()) / (pointB.getX() - pointA.getX());
		b = pointA.getY() - (a*pointA.getX());
		 minX = std::min(pointA.getX(), pointB.getX());
		 maxX = std::max(pointA.getX(), pointB.getX());
		 minY = std::min(pointA.getY(), pointB.getY());
		 maxY = std::max(pointA.getY(), pointB.getY());
		middleX = middle.getX();
		middleY = middle.getY();
	}
	else {
		a = (pointB.getX() - pointA.getX()) / (pointB.getY() - pointA.getY());
		b = pointA.getX() - (a*pointA.getY());
		minX = std::min(pointA.getY(), pointB.getY());
		maxX = std::max(pointA.getY(), pointB.getY());
		minY = std::min(pointA.getX(), pointB.getX());
		maxY = std::max(pointA.getX(), pointB.getX());
		middleX = middle.getY();
		middleY = middle.getX();
	}
	
	

	double i = 1 + (a*a);
	double j = -2 * middleX + 2 * a*b - 2 * a*middleY;
	double k = middleX*middleX - 2 * b*middleY + b*b + middleY*middleY - radius*radius;

	double delta = j*j - 4 * i*k;

	if (delta < 0) {
		return false;
	}
	if (delta > 0) {
		double x1 = (-j - sqrt(delta)) / 2 * i;
		double x2 = (-j - sqrt(delta)) / 2 * i;
		double y1 = a*x1 + b;
		double y2 = a*x2 + b;
		
		if (minX <= x1 && x1 <= maxX && minY <= y1 && y1 <= maxY) {
			return true;
		}
		else if (minX <= x2 && x2 <= maxX && minY <= y2 && y2 <= maxY) {
			return true;
		}

	}
	if (delta == 0) {
		double x1 = (-j ) / 2 * i;
		double y1 = a*x1 + b;
		if (minX <= x1 && x1 <= maxX && minY <= y1 && y1 <= maxY) {
			return true;}
		
		
	}
	return false;
	
}

bool BaseCircle::isCircleContainFigure(Figure & other) {
	Point middle(*points.at(0));
	for (Point *point : other.getPoints()) {
		double lengthFromPointToMiddle;
		lengthFromPointToMiddle = sqrt(((point->getX() - middle.getX())*(point->getX() - middle.getX())) + ((point->getY() - middle.getY())*(point->getY() - middle.getY())));
		if (lengthFromPointToMiddle <= radius) {
			return true;
		}
	}
	return false;

}

bool BaseCircle::ifCircleIsInsideFigure(Figure & other) {
	Point middle(*points.at(0));
	double minX = other.getPoints().at(0)->getX();
	double maxX = other.getPoints().at(0)->getX();
	double minY = other.getPoints().at(0)->getY();
	double maxY = other.getPoints().at(0)->getY();
	for (int i = 1; i < other.getPoints().size() - 1; i++) {
		double x = other.getPoints().at(i)->getX();
		double y = other.getPoints().at(i)->getY();
		if (x < minX) { minX = x; }
		if (x > maxX) { maxX = x; }
		if (y < minY) { minY = y; }
		if (y > maxY) { maxY = y; }
	}
	return minX <= middle.getX() && middle.getX() <= maxX && minY <= middle.getY() && middle.getY() <= maxY;
		
	
}

bool BaseCircle::isCollidingCircle(Figure & other) {
	return other.getPoints().size() == 1;
}

bool BaseCircle::isCirclesColliding(BaseCircle & other) {
	Point middle(*points.at(0));
	Point otherMiddle(*other.points.at(0));
	double lengthFromMiddleToMiddle = sqrt((otherMiddle.getX() - middle.getX())*(otherMiddle.getX() - middle.getX()) + (otherMiddle.getY() - middle.getY())*(otherMiddle.getY() - middle.getY()));
	return lengthFromMiddleToMiddle < radius + other.radius;
}





