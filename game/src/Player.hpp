//
//  Player.hpp
//  game
//
//  Created by Dawid on 22/04/2018.
//  Copyright © 2018 game. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Player
{
public:
    Player(const char* playerTex);
    ~Player();

    int GetPlayerHealth();
    int GetPlayerArmor();

    void Update(bool up, bool down, bool left, bool right);
    void Render();

private:
    int health, armor, speed;

    int xPos;
    int yPos;

    SDL_Texture* playerTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
};

#endif /* Player_hpp */
