#pragma once
#include <iostream>
#include <string>
#include <sstream>
class Point {
public:
	Point();
	Point(double x, double y);
	void shift(double x,double y);
	void rotate(int degrees);
	double getX();
	double getY();
	void setX(double x);
	void setY(double y);
	std::string toString();
	double magnitude();
	~Point();
protected:
	double x;
	double y;
};

