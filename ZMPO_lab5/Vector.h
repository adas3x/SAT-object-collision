#pragma once
#include "Point.h"
class Vector : public Point{
public:
	Vector(double x, double y);
	Vector getNormal();
	static Vector makeVector(Point& first, Point& second);
	
	~Vector();
};

