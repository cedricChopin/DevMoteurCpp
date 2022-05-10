#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
namespace ESGI
{
	class GameObject;
	class Transform;
	__declspec(dllexport) class Scene
	{
	private:
		std::vector<GameObject*> ActiveObjects;
		std::vector<GameObject*> InactiveObjects;
		std::vector<Transform*> ActiveTransform;
	public:
		__declspec(dllexport) Scene();
		__declspec(dllexport) void SetInactive(GameObject*);

		__declspec(dllexport) void SetActive(GameObject*);

		__declspec(dllexport) void CleanInactive();
		__declspec(dllexport) void PushTransform(Transform* transform);

		__declspec(dllexport) void Update();
		__declspec(dllexport) void UpdateTransform();



		__declspec(dllexport) std::vector<GameObject*> GetActiveObjects();

		__declspec(dllexport) std::vector<Transform*> GetAllTransforms();



	};
}
