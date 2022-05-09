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
	static GameObject* m_pool;
	static int m_currentIndex;

public:
	std::vector<Component*> *components;

	GameObject() {
		Transform *transform = new Transform();
		components->push_back(transform);
	}
	~GameObject() {
		delete[] components;
		delete(this);
	}

	static GameObject* Allocate() {
		return &m_pool[m_currentIndex++];
	}
	static void CreatePool(int count) {
		m_pool = new GameObject[count];
	}
	static void DestroyPool() {
		delete[] m_pool;
	}

	void Destroy() {
		//scene->SetInactive(this);
	}
};

