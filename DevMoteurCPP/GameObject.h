#pragma once

#include <vector>
#include <string>

#include "Component.h"
#include "Vector2.h"
#include "Behaviour.h"
#include "Transform.h"
#include "Scene.h"
namespace ESGI
{
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
			Transform* transform = new Transform();
			components->push_back(transform);
			scene->PushTransform(transform);
		}
		GameObject(Scene* myScene) {
			scene = myScene;

			components = new std::vector<Component*>();
			Transform* transform = new Transform();
			components->push_back(transform);
			scene->SetActive(this);
			scene->PushTransform(transform);
		}
		~GameObject() {
			delete[] components;
			scene = nullptr;
			delete(this);
		}

		std::string toString() {
			return "GameObject Transform";
		}

		static GameObject* Allocate() {
			//ok, si nombre croissant d'objets allou�s et peu/pas de d�alloc
			return &m_pool[m_currentIndex++];
		}
		static void CreatePool(int count) {
			m_pool = new GameObject[count];
		}
		static void DestroyPool() {
			delete[] m_pool;
		}


	};

}