#include "pch.h"
#include "Transform.h"
#include <math.h>
namespace ESGI
{
	void Transform::move(double x, double y) {
		position.x += x;
		position.y += y;
	}

	void Transform::move(Vector2 vec) {
		position.x += vec.x;
		position.y += vec.y;
	}

	void Transform::rotate(double angle) {
		rotation.x = rotation.x * cos(angle) - rotation.y * sin(angle);
		rotation.y = rotation.x * sin(angle) + rotation.y * cos(angle);
	}

	void Transform::rescale(double size) {
		scale.x = size;
		scale.y = size;
	}
	void Transform::Start() {

	}
	void Transform::Awake() {

	}
	std::string Transform::ToString()
	{
		std::stringstream ss;
		ss << "Pos x : " << position.x << "; Pos y : " << position.y << "; ";
		ss << "Rot x : " << rotation.x << "; Rot y : " << rotation.y << "; ";
		ss << "Scale x : " << scale.x << "; Scale y : " << scale.y << "\n";
		std::string s = ss.str();
		return s;
	}
	void Transform::Update(float deltaTime) {
		if (LeftButtonPressed)
			move(-1 * deltaTime, 0);
		if (RightButtonPressed)
			move(1 * deltaTime, 0);
		if (UpButtonPressed)
			move(0, 1 * deltaTime);
		if (DownButtonPressed)
			move(0, -1 * deltaTime);
	}
	void Transform::UpdateInput(bool left, bool right, bool up, bool down)
	{
		LeftButtonPressed = left;
		RightButtonPressed = right;
		UpButtonPressed = up;
		DownButtonPressed = down;
	}
}
