//
//  TextureManager.hpp
//  game
//
//  Created by Dawid on 21/04/2018.
//  Copyright © 2018 game. All rights reserved.
//

#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <bits/stdc++.h>
#include "Game.hpp"

class TextureManager
{
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dst);
    
};

#endif /* TextureManager_hpp */
