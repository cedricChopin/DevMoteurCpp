#pragma once

#include <vector>

#include "Component.h"
#include "Vector2.h"
#include "Behaviour.h"
#include "Transform.h"
#include "Scene.h"

__declspec(dllexport) class GameObject
{
private:
	Scene* scene;
public:
	static GameObject* m_pool;
	static int m_currentIndex;

	std::vector<Component*> *components;

	GameObject() {
		scene = new Scene();
		components = new std::vector<Component*>();
		Transform *transform = new Transform();
		components->push_back(transform);
	}
	GameObject(Scene* myScene) {
		scene = myScene;
		
		components = new std::vector<Component*>();
		Transform* transform = new Transform();
		components->push_back(transform);
		scene->SetActive(this);
	}
	~GameObject() {
		delete[] components;
		scene = nullptr;
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


};

