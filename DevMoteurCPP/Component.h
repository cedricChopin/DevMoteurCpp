#pragma once
#include "Behaviour.h"

__declspec(dllexport) class Component : public Behaviour
{
public:

	__declspec(dllexport) Component() {}
	virtual void Start();
	virtual void Update();
	virtual void Awake();
};

