#pragma once
#include<iostream>
#include<sfml\graphics.hpp>
#include<sfml\window.hpp>
#include<sfml\system.hpp>
#include<math.h>
#include<vector>
#include<cstdlib>

using namespace sf;

class Bullet
{
public:
	Bullet();
	~Bullet();
	
	CircleShape shape;
	Vector2f currvelocity;
	float maxspeed;

};

