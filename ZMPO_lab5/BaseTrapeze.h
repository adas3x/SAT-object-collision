#pragma once
#include "BaseRectangle.h"
class BaseTrapeze : public BaseRectangle {

public:
	BaseTrapeze(Point &lowerLeft, Point &lowerRight, Point &upperLeft, Point &upperRight);
	
	~BaseTrapeze();

};
