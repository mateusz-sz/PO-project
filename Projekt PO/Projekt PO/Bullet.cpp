#include "Bullet.h"



Bullet::Bullet(float radius, int xPos, int yPos, int dir, int creationTime)
{
	currvelocity.x = 0; currvelocity.y = 0;
	if (dir == 0)currvelocity.y = -1 * maxspeed;
	if (dir == 1)currvelocity.y = 1 * maxspeed;
	if (dir == 2)currvelocity.x = -1 * maxspeed;
	if (dir == 3)currvelocity.x = 1 * maxspeed;
	shape.setPosition(xPos, yPos);
	this->shape.setRadius(radius);
	this->shape.setFillColor(Color::Red);	
	this->shape.setRadius(radius);
	
	maxspeed = 0.9f;
	this->creationTime = creationTime;
	lifeTime = 400; //bullet lasting
}


Bullet::~Bullet()
{
}

void Bullet::Update()
{
	shape.move(currvelocity);
}

void Bullet::DrawBullet(RenderWindow & win)
{
	win.draw(shape);
}
