#include "pch.h"
#include "Scene.h"
#include "GameObject.h"


Scene::Scene() {

}



void Scene::SetInactive(GameObject* object) {
	auto position = std::find(ActiveObjects.begin(), ActiveObjects.end(), object);
	if (position != ActiveObjects.end()) {
		ActiveObjects.erase(position);
		InactiveObjects.push_back(object);
	}
}

void Scene::SetActive(GameObject* object) {

	ActiveObjects.push_back(object);
}


void Scene::CleanInactive() {
	
	std::for_each(InactiveObjects.begin(), InactiveObjects.end(),
		[](GameObject* object)
		{
			object->~GameObject();
		}
	);
	InactiveObjects.clear();
}
/*
std::vector<GameObject*> Scene::GetActiveObjects() {
	return ActiveObjects;
}*/