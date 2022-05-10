#pragma once
#include "Behaviour.h"
namespace ESGI
{
	__declspec(dllexport) class Component : public Behaviour
	{
	public:

		__declspec(dllexport) Component() {}
		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void Awake() = 0;
	};

}