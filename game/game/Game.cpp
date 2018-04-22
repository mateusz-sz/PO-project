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
#include "Player.hpp"
using namespace std;

Player* player;
GameObject* racket;
Map* WorldMap;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

bool leftt = 0;
bool rightt = 0;
bool up = 0;
bool down = 0; //player movement dir

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)  //initializing game screen
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
    
    racket = new GameObject("/Users/dejw/Desktop/Moja Gra/game/images/racket.jpg",500,500);
    player = new Player("/Users/dejw/Desktop/Moja Gra/game/images/kacper.jpg");
    WorldMap = new Map();

}

void Game::HandleEvents()
{
   
    SDL_PollEvent(&event);
    
    switch (event.type) //menu events
    {
        case SDL_QUIT:
            isRunning = false;
            break;
            
        default:
            break;
    }
    
    
    if(event.type == SDL_KEYDOWN) // if key is pressed
    {
        switch (event.key.keysym.sym) // player movement
        {
            case SDLK_w:
                up = true;
                break;
            
            case SDLK_s:
                down = true;
                break;
            
            case SDLK_a:
                leftt = true;
                break;
            
            case SDLK_d:
                rightt = true;
                break;
                
            default:
                break;
        }
    }
    
    if(event.type == SDL_KEYUP) //key is released
    {
        switch (event.key.keysym.sym) // we stop player movement if user releases the key
        {
            case SDLK_w:
                up = false;
                break;

            case SDLK_s:
                down = false;
                break;

            case SDLK_a:
                leftt = false;
                break;

            case SDLK_d:
                rightt = false;
                break;

            default:
                break;
        }
    }
}

void Game::Update() // updating all objects in game
{
    racket->Update();
    player->Update(up,down,leftt,rightt);


    count++;
    cout<<count<<endl;
}

void Game::Render() // renders stuff on window
{
    SDL_RenderClear(renderer);
    //now we can add stuff to render
    
    WorldMap->DrawMap();
    player->Render();
    racket->Render();
    SDL_RenderPresent(renderer);
}

void Game::Clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout<<"Game cleaned.\n";
}




