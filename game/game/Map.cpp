//
//  Map.cpp
//  game
//
//  Created by Dawid on 22/04/2018.
//  Copyright © 2018 game. All rights reserved.
//

#include "Map.hpp"
#include "TextureManager.hpp"

int level1[25][25] = {
    
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,1,1,2,1,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,1,1,2,2,1,1,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,1,1,2,2,2,2,1,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,1,1,2,2,2,2,1,1,0,0,0,0,0,0,0},
     {0,0,0,0,0,1,1,2,2,2,2,1,1,0,0,0,0,0,0,0},
     {0,0,0,0,0,1,1,2,2,2,1,1,1,0,0,0,0,0,0,0},
     {0,0,0,0,0,1,1,2,1,1,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,0},
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,0,1,0},
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,2,2,1,0},
     {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0},
     {0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,1,2,2,0,0},
     {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,0},
    
};

Map::Map()  // loading map components
{
    dirt = TextureManager::LoadTexture("/Users/dejw/Desktop/Moja Gra/game/images/dirt.jpg");
    grass = TextureManager::LoadTexture("/Users/dejw/Desktop/Moja Gra/game/images/grass.jpg");
    water = TextureManager::LoadTexture("/Users/dejw/Desktop/Moja Gra/game/images/water.jpg");
    
    LoadMap(level1);
    
    src.x = src.y = 0;
    src.w = src.h = dest.w = dest.h = 32;
    
    dest.x = dest.y = 0;
    
}

void Map::LoadMap(int loadedMap[25][25])
{
    for(int i=0 ; i<25; i++)
    {
        for(int j=0; j<25; j++)
        {
            map[i][j] = loadedMap[i][j];
        }
    }
}

void Map::DrawMap()
{
    int typeOfBackground = 0;
    
    for(int i=0 ; i<25; i++)
    {
        for(int j=0; j<25; j++)
        {
            typeOfBackground = map[i][j];
            dest.x = j * 32;
            dest.y = i * 32;
            
            if(typeOfBackground == 0)TextureManager::Draw(water, src, dest);
            if(typeOfBackground == 1)TextureManager::Draw(grass, src, dest);
            if(typeOfBackground == 2)TextureManager::Draw(dirt, src, dest);
            
        }
    }
}
