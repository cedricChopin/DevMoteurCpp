#pragma once

#include <vector>

#include "Component.h"
#include "Vector2.h"
#include "Behaviour.h"
#include "Transform.h"


class GameObject : Behaviour
{
private:
	//Scene *scene;
public:
	std::vector<Component*> *components;

	GameObject() {
		Transform *transform = new Transform();
		components->push_back(transform);
	}
	~GameObject() {
		//scene->SetInactive(this);
	}


};

