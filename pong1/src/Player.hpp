#pragma once


#include  "Actor.hpp"

class Player:public Actor
{
    SDL_Rect rectPlayer;
    SDL_Color color;
    int delta ;
    int points;
    bool up;
    bool down;

public:
	Player( int x, int y, int width, int height, SDL_Color  color); 
    Player( int x, int y); 
	void draw(SDL_Renderer * rend);
    void update(SDL_Renderer * rend);
    void moveUp();
    void moveDown();
    int getPoints();
    void setPoints(int points);
    ~Player();
    
};