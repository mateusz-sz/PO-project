#pragma once
#include<iostream>
#include<sfml\graphics.hpp>
#include<sfml\window.hpp>
#include<sfml\system.hpp>
#include<math.h>
#include<vector>
#include<cstdlib>

#include "Entity.h"
#include "Collider.h"
#include "Player.h"
using namespace sf;

class Bullet : public Entity
{
public:
	Bullet(float radius, int xPos, int yPos, int dir, int creationTime);
	~Bullet();
	
	//CircleShape shape;
	Vector2f currvelocity;
	void Update();
	void DrawBullet(RenderWindow &win);

	Vector2f GetEnemyPosition() { return shape.getPosition(); };
	Collider GetCollider() { return Collider(shape); }

public:
	int creationTime , lifeTime;
private:
	float maxspeed;
	bool destroy;

	

};

