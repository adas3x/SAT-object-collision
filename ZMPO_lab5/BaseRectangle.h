#pragma once
#include "BaseTriangle.h"
class BaseRectangle:public BaseTriangle  {
public:
	BaseRectangle(Point lowerLeft,double length,double height);
	~BaseRectangle();
protected:
	
	BaseRectangle();
	
	
};

