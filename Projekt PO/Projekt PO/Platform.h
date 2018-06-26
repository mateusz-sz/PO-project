#pragma once
#include<iostream>
#include<sfml\graphics.hpp>
#include<sfml\window.hpp>
#include<sfml\system.hpp>
#include<math.h>
#include<vector>
#include<cstdlib>

#include "Collider.h"
using namespace sf;

class Platform
{
public:
	Platform(Texture* texture, Vector2f size, Vector2f position);
	~Platform();

	void Draw(RenderWindow& window);
	Collider GetCollider() { return Collider(body); }

private:
	RectangleShape body;
};

