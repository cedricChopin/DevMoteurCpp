#include "pch.h"
#include "Scene.h"
#include "GameObject.h"
#include "Transform.h"

namespace ESGI
{
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
	void Scene::PushTransform(Transform* transform)
	{
		ActiveTransform.push_back(transform);
	}
	void Scene::Update()
	{
		UpdateTransform();
	}
	void Scene::UpdateTransform()
	{
		std::for_each(ActiveTransform.begin(), ActiveTransform.end(),
			[](Transform* object)
			{
				object->move(0.1, 0.1);
				std::cout << object->ToString();
			}
		);
	}
	std::vector<GameObject*> Scene::GetActiveObjects() {
		return ActiveObjects;
	}
	std::vector<Transform*> Scene::GetAllTransforms()
	{
		return ActiveTransform;
	}

	void Scene::loadScene(std::string nameFile) {
		JSONValue json = JSON::load(nameFile);

		JSONValue value = json.m_object[json.m_object.begin()->first];

		for (int i = 0; i < value.size(); i++) {
			Transform* tr = new Transform();
			std::string name;

			tr->position.x = value[i]["Transform"]["Position"]["x"].asDouble();
			tr->position.y = value[i]["Transform"]["Position"]["y"].asDouble();
			tr->rotation.x = value[i]["Transform"]["Rotation"]["x"].asDouble();
			tr->rotation.y = value[i]["Transform"]["Rotation"]["y"].asDouble();
			tr->scale.x = value[i]["Transform"]["Scale"]["x"].asDouble();
			tr->scale.y = value[i]["Transform"]["Scale"]["y"].asDouble();
			
			name = value[i]["Name"].asString();
			//Parse pour transf & name
			GameObject* obj = new GameObject(this, tr, name);
		}

	}
}