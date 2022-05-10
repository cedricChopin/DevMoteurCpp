#include "pch.h"
#include "Transform.h"
#include <math.h>

void Transform::move(int x, int y) {
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
