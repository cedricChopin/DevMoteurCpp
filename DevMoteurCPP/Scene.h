#pragma once
#include <vector>
#include <algorithm>

class GameObject;
__declspec(dllexport) class Scene
{
private:
	std::vector<GameObject*> ActiveObjects;
	std::vector<GameObject*> InactiveObjects;

public:
	__declspec(dllexport) Scene();
	__declspec(dllexport) void SetInactive(GameObject*);

	__declspec(dllexport) void SetActive(GameObject*);

	__declspec(dllexport) void CleanInactive();

	//std::vector<GameObject*> GetActiveObjects();



};

