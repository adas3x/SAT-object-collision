

#include "Object.h"
#include "stdafx.h"
#include "include.h"

void test1(){
	Point pointA(1, 1);
	Point pointB(2, 1);
	Vector vector(Vector::makeVector(pointA, pointB));
	std::cout << "wspolrzedne wektora:" << vector.toString() << std::endl;
	Vector normal(vector.getNormal());
	std::cout << "normalna wektora" << normal.toString() << std::endl;
}
void test2() {
	Object object1(1);
	Object object2(2);
	object1.addBaseTrapeze(Point(1, 1), Point(4, 1), Point(2, 2), Point(4, 2));
	object2.addBaseTrapeze(Point(1, 0), Point(4, 0), Point(2,1.5),Point(3,1.5));
	std::cout << object1.isColliding(object2) << std::endl; // 1
	object2.shift(0, -1);
	std::cout << object1.isColliding(object2) << std::endl; // 0
}

void test3() {
	Object object1(1);
	Object object2(2);

	object1.addBaseTriangle(Point(2, 1), Point(3, 3), Point(1, 3));
	object2.addBaseTriangle(Point(2, 0), Point(3, 2), Point(4, 0));

	std::cout << object1.isColliding(object2) << std::endl;

	object2.shift(-1, 0);

	std::cout << object1.isColliding(object2) << std::endl;
}
void test4() {
	Object object1(1);
	Object object2(2);

	//object1.addBaseRectangle(Point(0, 0), 10, 10);
	object1.addBaseCircle(Point(1, 1), 0.5);
	//object1.addBaseTriangle(Point(2, 1), Point(3, 3), Point(1, 3));
	object2.addBaseCircle(Point(0, 0),1);

	std::cout << object1.isColliding(object2) << std::endl;

	object2.shift(-500, 0);
	
	std::cout << object2.isColliding(object1) << std::endl;
}

void mainTest1() {
	Scene scene;
	Object *object1, *object2;
	int idObject1, idObject2;
	idObject1 = scene.addObject();
	idObject2 = scene.addObject();

	object1 = scene.getObject(idObject1);
	object2 = scene.getObject(idObject2);

	object1->addBaseTriangle(Point(0, 0), Point(2, 2), Point(0, 1));
	object1->addBaseCircle(Point(50, 50), 20);
	object1->shift(50, 50);
	object1->rotate(144);

	object2->addBaseCircle(Point(10, 10), 5);
	std::cout << object2->isColliding(*object1) << std::endl;

	scene.setCollidingPairs();
	std::cout << scene.collidingPairsToString() << std::endl;
}
void mainTest2() {
	Scene scene;
	Object *object0,*object1, *object2,*object3;
	int idObject0,idObject1, idObject2,idObject3;

	idObject0 = scene.addObject();
	idObject1 = scene.addObject();
	idObject2 = scene.addObject();
	idObject3 = scene.addObject();

	object0 = scene.getObject(idObject0);
	object1 = scene.getObject(idObject1);
	object2 = scene.getObject(idObject2);
	object3 = scene.getObject(idObject3);

	object0->addBaseCircle(Point(0, 0), 1000);

	object1->addBaseTriangle(Point(0, 0), Point(2, 2), Point(0, 1));
	object1->addBaseCircle(Point(50, 50), 20);
	object1->shift(50, 50);
	object1->rotate(144);

	object2->addBaseTrapeze(Point(1, 1), Point(4, 1), Point(2, 2), Point(4, 1));
	object2->addBaseCircle(Point(0, 0), 10);
	object2->shift(50, 50);
	object2->rotate(144);
	
	object3->addBaseCircle(Point(10, 10), 5);
	
	scene.setCollidingPairs();
	std::cout << scene.collidingPairsToString() << std::endl;
}

int main(){
	mainTest2();
}

