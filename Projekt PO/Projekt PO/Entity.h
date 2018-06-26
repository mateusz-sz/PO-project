#pragma once
#include<iostream>
#include"sfml\graphics.hpp"
#include"sfml\window.hpp"
#include"sfml\system.hpp"
#include<math.h>
#include<vector>
#include<cstdlib>

using namespace sf;

class Entity
{
public:
	void setVelocity(Vector2f velocity);
	void setVelocity(float Vx, float Vy);
	Vector2f getVelocity() const;

private:
	Vector2f MyVelocity;
};

