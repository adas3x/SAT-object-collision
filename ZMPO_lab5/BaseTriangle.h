#pragma once
#include "Figure.h"
class BaseTriangle:public Figure {
public:
	BaseTriangle(Point &A,Point &B,Point &C);
	~BaseTriangle();

protected:
	BaseTriangle();
	
	
	
};

