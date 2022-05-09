#pragma once
#include "Vector2.h"
#include "Component.h"

class Transform : public Component
{
public:
	Vector2 position;
	Vector2 rotation;
	Vector2 scale;

	Transform(Vector2 pos, Vector2 rot, Vector2 s): position(pos), rotation(rot),scale(s){}
	Transform(Vector2 pos): position(pos), rotation(Vector2::zero()), scale(Vector2::one()){}
	Transform(Vector2 pos, Vector2 rot): position(pos), rotation(rot), scale(Vector2::one()){}
	
	Transform(){
		position = Vector2::zero();
		rotation = Vector2::zero();
		scale = Vector2::one();
	}

	void move(int x, int y);
	void move(Vector2 vec);
	void rotate(double angle);
	void rescale(double size);
};

