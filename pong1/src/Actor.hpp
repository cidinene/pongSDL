
#pragma once
#include <SDL2/SDL.h>
class Actor
{

public:
    Actor(int x, int y, int width, int height);
    virtual void draw(SDL_Renderer * rend) =0;
    virtual void update(SDL_Renderer * rend) =0;
    bool colision(Actor * actor);
    int x;
    int y;
    int width;
    int height;
};