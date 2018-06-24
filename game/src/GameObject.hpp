//
//  GameObject.hpp
//  game
//
//  Created by Dawid on 21/04/2018.
//  Copyright © 2018 game. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <bits/stdc++.h>
#include "Game.hpp"

class GameObject
{
public:
    GameObject(const char* texuresheet , int x, int y);
    ~GameObject();
    
    void Update();
    void Render();
    
private:
    int xPos;
    int yPos;
    
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
    
    
};

#endif /* GameObject_hpp */
