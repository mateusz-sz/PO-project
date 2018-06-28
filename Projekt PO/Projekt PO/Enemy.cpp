#include "Enemy.h"

Enemy::Enemy(Texture* texture, Vector2u imageCount, float switchTime, int xPos, int yPos)
	:animation(texture, imageCount, switchTime)
{
	Health = 100;
	Speed = 100.f;
	row = 0; 
	body.setSize(Vector2f(50.f, 75.f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(rand() % xPos, rand() % yPos);
	body.setTexture(texture); 
}

Enemy::~Enemy(){}


void Enemy::Update(float deltaTime, Player player)
{
	Vector2f PlayerPosition = player.GetPlayerPosition();
	unsigned int randomNumber = rand() % 10;

	int height = abs((int)PlayerPosition.y - (int)GetEnemyPosition().y);
	int width = abs((int)PlayerPosition.x - (int)GetEnemyPosition().x);
	int distance = (int)sqrt(height * height + width * width);

	Vector2f movement(0.f, 0.f);

	if (distance > 300) //enemy is just moving around randomly
	{
		if (randomNumber == 3){
			movement.y -= Speed * deltaTime;
		}
		if (randomNumber == 0){
			movement.y += Speed * deltaTime;
		}
		if (randomNumber == 1){
			movement.x -= Speed * deltaTime;
		}
		if (randomNumber == 2){
			movement.x += Speed * deltaTime;
		}
	}
	else //enemy starts to chase a player
	{
		if (GetEnemyPosition().x  < PlayerPosition.x) {
			movement.x += Speed * deltaTime; 
		}
		if (GetEnemyPosition().x > PlayerPosition.x) {
			movement.x -= Speed * deltaTime; 
		}
		if (GetEnemyPosition().y > PlayerPosition.y) {
			movement.y -= Speed * deltaTime; 
		}
		if (GetEnemyPosition().y < PlayerPosition.y) {
			movement.y += Speed * deltaTime;
		}
	}
	int Xdist = (int)PlayerPosition.x - (int)GetEnemyPosition().x;
	int Ydist = (int)PlayerPosition.y - (int)GetEnemyPosition().y;
	if (abs(Xdist) > abs(Ydist)) //left or right
	{
		if (Xdist > 0) row = 2; //right
		else row = 1; //left
	}
	else //up or down
	{
		if (Ydist < 0) row = 3;// up
		else row = 0; //down
	}
	//if (movement.x == 0 and movement.y == 0) row = 0;

	animation.Update(row, deltaTime);
	body.setTextureRect(animation.textureRect);
	body.move(movement);
}

void Enemy::DrawEnemy(RenderWindow &win) {
	win.draw(body);
}

Vector2f Enemy::GetEnemyPosition() {
	return body.getPosition();
}