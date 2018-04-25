/* Dejwo to ziomal ®© */

#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include "Game.hpp"

using namespace std;

Game *game = nullptr;

int main()
{
    ios_base::sync_with_stdio(0);
    
    const int FPS = 60;
    const int FrameDelay = 1000/FPS;
    
    int FrameStart;
    int FrameTime;
    
    game = new Game();
    game->init("Gra", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);
    
    while(game->running())
    {
        FrameStart = SDL_GetTicks(); //frame start
        
        game->HandleEvents();
        game->Update();
        game->Render();
        
        FrameTime = SDL_GetTicks() - FrameStart; // frame end, so we know how much time did our frame take and if we need to delay next frame
        
        if(FrameDelay > FrameTime)
        {
            SDL_Delay(FrameDelay - FrameTime); //we delay next frame so everything moves smoooooth 
        }
    }
    game->Clean();
    return 0;
}
