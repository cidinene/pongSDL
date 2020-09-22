#pragma once

#include  "Actor.hpp"

class Ball:public Actor
{
    SDL_Rect rectPlayer;
    SDL_Color color;
    int direction_x;
    int direction_y;
    int deltaX;
    int deltaY;
public:
	Ball( int x, int y, int width, int height, SDL_Color  color); 
    Ball( int x, int y); 
	void draw(SDL_Renderer * rend);
    void update(SDL_Renderer * rend);
    bool colision(Actor * actor);
    int checkPoint();
    ~Ball();
    
};