#pragma once
#include "Vector2.h"
#include "Component.h"
namespace ESGI
{
	__declspec(dllexport) class Transform : public Component
	{
	public:
		Vector2 position;
		Vector2 rotation;
		Vector2 scale;

		__declspec(dllexport) Transform(Vector2 pos, Vector2 rot, Vector2 s) : position(pos), rotation(rot), scale(s) {}
		__declspec(dllexport) Transform(Vector2 pos) : position(pos), rotation(Vector2::zero()), scale(Vector2::one()) {}
		__declspec(dllexport) Transform(Vector2 pos, Vector2 rot) : position(pos), rotation(rot), scale(Vector2::one()) {}

		__declspec(dllexport) Transform() {
			position = Vector2::zero();
			rotation = Vector2::zero();
			scale = Vector2::one();
		}

		__declspec(dllexport) void move(int x, int y);
		__declspec(dllexport) void move(Vector2 vec);
		__declspec(dllexport) void rotate(double angle);
		__declspec(dllexport) void rescale(double size);
		__declspec(dllexport) void Start();
		__declspec(dllexport) void Update();
		__declspec(dllexport) void Awake();
	};
}
