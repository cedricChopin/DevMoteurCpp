#pragma once
namespace ESGI
{
	__declspec(dllexport) class Behaviour
	{
		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void Awake() = 0;
	};

}