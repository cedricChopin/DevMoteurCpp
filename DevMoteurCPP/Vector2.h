#pragma once
#include "pch.h"

class Vector2
{
public:
	double x;
	double y;

	Vector2(double _x, double _y): x(_x), y(_y){}
	Vector2() {
		x = 0;
		y = 0;
	}
	static Vector2 zero();
	static Vector2 one();
};

