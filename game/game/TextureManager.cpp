//
//  TextureManager.cpp
//  game
//
//  Created by Dawid on 21/04/2018.
//  Copyright © 2018 game. All rights reserved.
//

#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
    SDL_Surface* tmpSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    
    return tex;
}

void TextureManager::Draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dst)
{
    SDL_RenderCopy(Game::renderer, text, &src, &dst);
}
