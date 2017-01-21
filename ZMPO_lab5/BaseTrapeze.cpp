#include "stdafx.h"
#include "BaseTrapeze.h"




BaseTrapeze::BaseTrapeze(Point &lowerLeft, Point &lowerRight, Point &upperRight, Point &upperLeft) {
	points.push_back(new Point(lowerLeft));
	points.push_back(new Point(lowerRight));
	points.push_back(new Point(upperRight));
	points.push_back(new Point(upperLeft));
}

BaseTrapeze::~BaseTrapeze() {
}



