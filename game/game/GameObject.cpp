//
//  GameObject.cpp
//  game
//
//  Created by Dawid on 21/04/2018.
//  Copyright © 2018 game. All rights reserved.
//

#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* textsheet, int x, int y) //creating new object
{
    objTexture = TextureManager::LoadTexture(textsheet);
    
    xPos = x;
    yPos = y;
}

void GameObject::Update() //position update for objects
{
    srand(time(NULL));
    int random = rand() % 1000000;
    
    switch (random % 4)  //just some random moves
    {
        case 0:
            xPos++;
            break;
        case 1:
            xPos--;
            break;
        case 2:
            yPos++;
            break;
        case 3:
            yPos--;
            break;
            
        default:
            break;
    }
    
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w ;
    destRect.h = srcRect.h ;
}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
