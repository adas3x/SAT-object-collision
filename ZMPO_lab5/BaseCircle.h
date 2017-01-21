#pragma once
#include "Object.h"
#include <iostream>
#include <algorithm>
class BaseCircle : public Figure{
public:
	BaseCircle(Point &middle,double radius);
	~BaseCircle();
protected:
	
	double radius;
	
	bool isColliding(Figure &other);
private:
	bool isCollidingAlgorithm(Point &pointA, Point &pointB);
	bool isCircleContainFigure(Figure & other);
	bool ifCircleIsInsideFigure(Figure & other);
	bool isCollidingCircle(Figure & other);
	bool isCirclesColliding(BaseCircle & other);
	
};

