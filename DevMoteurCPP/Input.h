#pragma once

#include "InfraStructure.h"
#include "Scene.h"

namespace ESGI
{
	__declspec(dllexport) struct Input : public InfraStructure
	{
		bool QuitButtonPressed = false;
		bool LeftButtonPressed = false;
		bool RightButtonPressed = false;
		bool UpButtonPressed = false;
		bool DownButtonPressed = false;
		int ObjectSelected = 1;
		Scene* scene;

		__declspec(dllexport) bool Initialize() final;

		__declspec(dllexport) void DeInitialize() final;

		// ce n'est pas une fonction virtuelle !
		__declspec(dllexport) void Update();

		__declspec(dllexport) bool GetQuitButtonState();
	};
}