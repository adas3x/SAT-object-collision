#include "stdafx.h"
#include "BaseTriangle.h"





BaseTriangle::BaseTriangle(Point &A, Point &B, Point &C) {
	points.push_back(new Point(A));
	points.push_back(new Point(B));
	points.push_back(new Point(C));
}

BaseTriangle::~BaseTriangle() {
}

BaseTriangle::BaseTriangle() {
}




