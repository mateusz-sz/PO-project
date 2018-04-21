//
//  Game.cpp
//  game
//
//  Created by Dawid on 21/04/2018.
//  Copyright © 2018 game. All rights reserved.
//

#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
using namespace std;

GameObject* player;
GameObject* enemy;
Map* WorldMap;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen) flags = SDL_WINDOW_FULLSCREEN;  //jezeli FS to ustawiam flage
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout<<"Subsystems Initialised!!!\n";
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window)
        {
            cout<<"Window created!\n";
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout<<"Renderer created!\n";
        }
        
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
    
    player = new GameObject("/Users/dejw/Desktop/Moja Gra/game/images/racket.jpg",50,50);
    enemy  = new GameObject("/Users/dejw/Desktop/Moja Gra/game/images/kacper.jpg",0,0);
    WorldMap = new Map();

}

void Game::HandleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
            
        default:
            break;
    }
}

void Game::Update()
{
    player->Update();
    enemy->Update();


    count++;
    cout<<count<<endl;
}

void Game::Render() // renders stuff on window
{
    SDL_RenderClear(renderer);
    //now we can add stuff to render
    
    WorldMap->DrawMap();
    player->Render();
    enemy->Render();
    SDL_RenderPresent(renderer);
}

void Game::Clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout<<"Game cleaned.\n";
}




