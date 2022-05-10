#pragma once
#include "pch.h"

__declspec(dllexport) class Vector2
{
public:
	double x;
	double y;

	__declspec(dllexport) Vector2(double _x, double _y): x(_x), y(_y){}
	__declspec(dllexport) Vector2() {
		x = 0;
		y = 0;
	}
	__declspec(dllexport) static Vector2 zero();
	__declspec(dllexport) static Vector2 one();
};

