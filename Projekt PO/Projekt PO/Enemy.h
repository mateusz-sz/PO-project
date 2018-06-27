
#include<iostream>
#include<sfml\graphics.hpp>
#include<sfml\window.hpp>
#include<sfml\system.hpp>
#include<math.h>
#include<vector>
#include<cstdlib>

#include "Entity.h"
#include "Animation.h"
#include "Collider.h"
#include "Player.h"

using namespace sf;

class Enemy : public Entity
{
public:
	Enemy(Texture* texture, Vector2u imageCount, float switchTime, int xPos, int yPos);
	~Enemy();

	void Update(float deltaTime, Player player);
	void DrawEnemy(RenderWindow &win);

	Vector2f GetEnemyPosition();
	Collider GetCollider() { return Collider(body); }

private:
	float Speed, Damage, Health;

	unsigned int row;
private:
	Animation animation;
	RectangleShape body;
};

