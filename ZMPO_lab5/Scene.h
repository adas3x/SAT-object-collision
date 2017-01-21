#pragma once
#include "Object.h"
#include <vector>
#include <sstream>
class Scene {
public:
	Scene();
	int addObject();
	Object* getObject(int id);
	std::vector<std::pair<Object*, Object* >> getCollidingPairs();
	std::string collidingPairsToString();
	void setCollidingPairs();
	~Scene();
private:
	
	int objectsQuantity = 0;
	std::vector<Object*> objects;
	std::vector<std::pair<Object*,Object* >> collidingPairs;
};

