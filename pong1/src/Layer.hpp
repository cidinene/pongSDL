
#pragma once
#include <SDL2/SDL.h>
class Layer
{
public:
	Layer(SDL_Renderer* rend);
	virtual void init() =0;
	virtual void processControls() =0;
	virtual void update()=0;
	virtual void draw() =0 ;
    virtual bool isQuit() =0;
	SDL_Renderer* rend;
};