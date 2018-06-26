#include "Entity.h"


void Entity::setVelocity(sf::Vector2f velocity)
{
	MyVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
	MyVelocity.x = vx;
	MyVelocity.y = vy;
}

sf::Vector2f Entity::getVelocity() const
{
	return MyVelocity;
}
