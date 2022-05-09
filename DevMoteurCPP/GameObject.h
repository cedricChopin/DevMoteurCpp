#pragma once
#include "Vector2.h"
#include "Behaviour.h"
#include "Transform.h"

class GameObject : Behaviour, Transform
{
private:
	//Scene *scene;
public:
	Transform transform;

	GameObject() {
		transform = Transform();
	}
	~GameObject() {
		//scene->SetInactive(this);
	}


};

