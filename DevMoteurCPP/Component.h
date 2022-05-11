#pragma once
#include "Behaviour.h"
#include <string>
namespace ESGI
{
	__declspec(dllexport) class Component : public Behaviour
	{
	public:

		__declspec(dllexport) Component() {}
		virtual void Start() = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void Awake() = 0;
		virtual std::string ToString() = 0;
	};

}