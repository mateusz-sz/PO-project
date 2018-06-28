#pragma once
#include<iostream>
#include<sfml\graphics.hpp>
#include<sfml\window.hpp>
#include<sfml\system.hpp>
#include<math.h>
#include<vector>
#include<cstdlib>

#include "Animation.h"
#include "Collider.h"
#include "Bullet.h"

using namespace sf;
class Player
{
public:
	Player (Texture* texture, Vector2u imageCount, float switchTime, float height, float width);
	~Player();
	void Update(float deltaTime);
	void DrawPlayer(RenderWindow &win);

	Vector2f GetPlayerPosition();
	Collider GetCollider() { return Collider(body); }
	int GetPlayerDir() { return direction; }

private:
	int Health, Armor;
	float PlayerSpeed;
	int direction;

	RectangleShape body;
	Animation animation;
	Texture PlayerTexture;

	unsigned int row;
	
};

