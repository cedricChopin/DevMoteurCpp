#pragma once
#include <vector>
#include <algorithm>
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



		__declspec(dllexport) std::vector<GameObject*> GetActiveObjects();



	};
}
