#pragma once
#include <vector>
#include <algorithm>

class GameObject;
class Scene
{
private:
	std::vector<GameObject*> ActiveObjects;
	std::vector<GameObject*> InactiveObjects;

public:
	Scene();
	void SetInactive(GameObject*);

	void SetActive(GameObject*);

	void CleanInactive();

};

