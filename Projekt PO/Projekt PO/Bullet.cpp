#include "Bullet.h"



Bullet::Bullet()
{
	float radius = 5.f;
	this->shape.setRadius(radius);
	this->shape.setFillColor(Color::Red);	
	this->shape.setRadius(radius);
}


Bullet::~Bullet()
{
}
