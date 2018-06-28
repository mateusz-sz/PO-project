#pragma once
#include<iostream>
#include<sfml\graphics.hpp>
#include<sfml\window.hpp>
#include<sfml\system.hpp>
#include<math.h>
#include<vector>
#include<cstdlib>

using namespace sf;


class Collider
{
public:
	Collider(RectangleShape& body);
	Collider(CircleShape& shape);
	~Collider();

	void Move(float dx, float dy) { body.move(dx, dy); }
	bool CheckCollision(Collider other, float push);
	Vector2f GetPosition() { return body.getPosition(); }
	Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

	bool CheckBulletCollision(Collider other, float push);
	Vector2f GetBulletPosition() { return shape.getPosition(); }
	FloatRect GetRectBounds() { return body.getGlobalBounds(); }
	FloatRect GetCircleBounds() { return shape.getGlobalBounds(); }
private:
	RectangleShape& body;
	CircleShape& shape;
};

