#include "stdafx.h"
#include "BaseRectangle.h"





BaseRectangle::BaseRectangle(Point lowerLeft,double length, double height) {
	Point A = lowerLeft;
	Point B = A;
	Point C = A;
	Point D = A;
	B.shift(length, 0);
	C.shift(length, height);
	D.shift(0, height);

	points.push_back(new Point(A));
	points.push_back(new Point(B));
	points.push_back(new Point(C));
	points.push_back(new Point(D));
	

}

BaseRectangle::~BaseRectangle() {
}



BaseRectangle::BaseRectangle() {
}


