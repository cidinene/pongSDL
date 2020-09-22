#pragma once
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Game.hpp"


#define WIDTH 800
#define HEIGHT 600

#define DELTA_PLAYER 15

using namespace std;

int restart()
{
    cout<< "Restarting..."<<endl;
}

int main()
{
     Game * pong = new Game();
     pong -> loop();
     delete pong;
}
int test()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window *win = SDL_CreateWindow("Pong",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       WIDTH, HEIGHT, 0);

    
    // creates a surface to load an image into the main memory
    // SDL_Surface *surface;

    // // please provide a path for your image
    // surface = IMG_Load("/Users/irenecid/Desktop/docencia/videojuegos/2020-21/ClaseT 2- Pong - Elementos Básicos/codigo/pong1/src/img/Pelota.png");

    // // loads image to our graphics hardware memory.
    // SDL_Texture *tex = SDL_CreateTextureFromSurface(rend, surface);

    // // clears main-memory
    // SDL_FreeSurface(surface);


    

   /*  bool close = 0;
    // annimation loop
    
    

        // bottom boundary
        
        player1->update(rend);
        player2->update(rend);
        
        ball -> update(rend);
       
        
         
        // clears the screen
        SDL_RenderClear(rend);
        //SDL_RenderCopy(rend, tex, NULL, &rectPlayer1);

        // triggers the double buffers
        // for multiple rendering
        // SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
        // SDL_RenderFillRect(rend, &rectPlayer1);
        // SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);

        // SDL_SetRenderDrawColor(rend, 0, 126, 0, 255);
        // SDL_RenderFillRect(rend, &rectPlayer2);
        // SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        player1->draw(rend);
        player2->draw(rend);
        ball -> draw(rend);

        ball->colision(player1);
        ball->colision(player2);
        if (ball->checkPoint()>1)
         {
             restart();
             continue;

         }
         else
         if (ball -> checkPoint()<1)
         {
             restart();
             continue;
         }
       
       
        SDL_RenderPresent(rend);

        // calculates to 60 fps
        SDL_Delay(1000/ 60);
    }

    // // destroy texture
    // SDL_DestroyTexture(tex);

    // destroy renderer
    SDL_DestroyRenderer(rend);

    // destroy window
    SDL_DestroyWindow(win);
    SDL_Quit(); */
    return 0;
}