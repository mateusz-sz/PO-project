//
//  Player.cpp
//  game
//
//  Created by Dawid on 22/04/2018.
//  Copyright © 2018 game. All rights reserved.
//

#include "Player.hpp"
#include "TextureManager.hpp"

Player::Player(const char* playerTex) //constructs player
{
    health = 100;
    armor = 100;
    speed = 2;
    
    xPos = 200;
    yPos = 200;
    
    
    playerTexture = TextureManager::LoadTexture(playerTex);
}


int Player::GetPlayerHealth()
{ return health; }

int Player::GetPlayerArmor()
{ return armor; }


void Player::Update(bool u, bool d, bool l, bool r)
{
    xPos += r * speed;
    xPos -= l * speed;
    yPos += d * speed;
    yPos -= u * speed;
    
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w ;
    destRect.h = srcRect.h ;
}

void Player::Render()
{
    SDL_RenderCopy(Game::renderer, playerTexture, &srcRect, &destRect);
}
