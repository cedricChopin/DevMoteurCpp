#pragma once

#include "InfraStructure.h"

namespace ESGI
{
	__declspec(dllexport) struct Input : public InfraStructure
	{
		bool QuitButtonPressed = false;

		__declspec(dllexport) bool Initialize() final;

		__declspec(dllexport) void DeInitialize() final;

		// ce n'est pas une fonction virtuelle !
		__declspec(dllexport) void Update();

		__declspec(dllexport) bool GetQuitButtonState();
	};
}