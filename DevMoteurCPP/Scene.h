#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include "json.h"

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
		bool LeftButtonPressed = false;
		bool RightButtonPressed = false;
		bool UpButtonPressed = false;
		bool DownButtonPressed = false;
		int ObjectSelected = 1;
	public:
		__declspec(dllexport) Scene();
		__declspec(dllexport) void SetInactive(GameObject*);

		__declspec(dllexport) void SetActive(GameObject*);

		__declspec(dllexport) void CleanInactive();
		__declspec(dllexport) void PushTransform(Transform* transform);

		__declspec(dllexport) void Update(float deltaTime);
		__declspec(dllexport) void UpdateTransform(float deltaTime);
		__declspec(dllexport) void UpdateInput(bool left, bool right, bool up, bool down, int select);



		__declspec(dllexport) std::vector<GameObject*> GetActiveObjects();

		__declspec(dllexport) std::vector<Transform*> GetAllTransforms();
		__declspec(dllexport) int GetSelectedObject();

		__declspec(dllexport) void loadScene(std::string nameFile);

	};
}
