#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Point.h"
#include "Vector.h"
#define DEF_TRIANGLE "triangle"
#define DEF_RECTANGLE "rectangle"
#define DEF_TRAPEZE "trapeze"
#define DEF_ElLIPSE "ellipse"
#define DEF_CIRCLE "circle"

class Figure {

	
public:
	//friend class BaseCircle;
	void rotate(int degrees) ;
	void shift(double x, double y) ;
	virtual bool isColliding(Figure &other);
	std::string toString();
	std::vector<Point*> getPoints();
	~Figure();
	
protected:
	
	std::vector<Vector*> normals;
	std::vector<Point*> points;
private:
	void setNormals();
	double minDotProduct(Vector &axis);
	double maxDotProduct(Vector &axis);
	double dotProduct(Point &first, Point &second);
	bool isGap(Figure &other, Vector & axis);
	bool isOtherCircle(Figure &other);
	
	
	
};