#include "pch.h"
#include "Input.h"

// pour quitter la boucle : a ne pas utiliser dans une vraie application
#include <conio.h>

#include <iostream>

namespace ESGI {

	bool Input::Initialize()
	{
#if defined(_DEBUG)
		m_DebugName = "Input";
#endif
		std::cout << "[Input] initialized\n";
		return true;
	}

	void Input::DeInitialize()
	{
		std::cout << "[Input] deinitialized\n";
	}

	// ce n'est pas une fonction virtuelle !
	void Input::Update()
	{
		QuitButtonPressed = GetQuitButtonState();
		std::cout << "[Input] update\n";
	}

	bool Input::GetQuitButtonState()
	{
		LeftButtonPressed = false;
		UpButtonPressed = false;
		RightButtonPressed = false;
		DownButtonPressed = false;
		if (_kbhit())
		{
			int ch = _getch();
			if (ch == 49) {				//1
				ObjectSelected = 1;
			}
			if (ch == 50) {				//1
				ObjectSelected = 2;
			}
			if (ch == 51) {				//1
				ObjectSelected = 3;
			}
			if (ch == 113) {			//q
				std::cout << "[Input] Left\n";
				LeftButtonPressed = true;
			}
			if (ch == 122) {			//z
				std::cout << "[Input] Up\n";
				UpButtonPressed = true;
			}
			if (ch == 100) {			//d
				std::cout << "[Input] Right\n";
				RightButtonPressed = true;
			}
			if (ch == 115) {			 //s
				std::cout << "[Input] Down\n";
				DownButtonPressed = true;
			}
			if (ch == 27)			// ESC 
				return true;
		}
		return false;
	}
}