#include "stdafx.h"
#include "Scene.h"


Scene::Scene() {
}

int Scene::addObject() {
	
	objects.push_back(new Object(objectsQuantity));
	objectsQuantity++;
	return objectsQuantity-1;
}


Object * Scene::getObject(int id) {
	return objects.at(id);
}

void Scene::setCollidingPairs() {
	collidingPairs.clear();
	for (int i = 0; i < objectsQuantity; i++) {
		for (int j = i+1; j < objectsQuantity; j++) {
			if (objects.at(i)->isColliding(*objects.at(j))) {
				collidingPairs.push_back(std::make_pair(objects.at(i), objects.at(j)));
			}
		}
	}
}

std::vector<std::pair<Object*, Object*>> Scene::getCollidingPairs() {
	return collidingPairs;
}

std::string Scene::collidingPairsToString() {
	std::ostringstream  ss;
	for (std::pair<Object*, Object*> collidingPair : collidingPairs) {
		ss << "("<< collidingPair.first->getId() << ";" << collidingPair.second->getId() << ")";
	}
	return ss.str();
}



Scene::~Scene() {
	for (Object *object : objects) {
		delete object;
	}
	objects.clear();
}
