#pragma once
#include "Figure.h"
#include "stdafx.h"
#include "BaseTriangle.h"
#include "BaseRectangle.h"
#include "BaseTrapeze.h"
#include "BaseCircle.h"
class Object {
public:
	Object(int id);
	void addBaseTriangle(Point A, Point B, Point C);
	void addBaseRectangle(Point lowerLeft, double length, double height);
	void addBaseTrapeze(Point lowerLeft, Point lowerRight, Point upperLeft, Point upperRight);
	void addBaseCircle(Point middlePoint, double radius);
	virtual void rotate(int degrees);
	virtual void shift(double x, double y);
	bool isColliding(Object &other);
	int getId();
	~Object();
	
	
	
private:
	std::vector<Figure*> figures;
	int id;
	
};


