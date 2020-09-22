
#pragma once

#include <iostream>
#include <string>
using namespace std;
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
class Score
{
	int x;
    int y;
    int width;
    int height;
	SDL_Color color;
	TTF_Font *font;
public:
	Score(SDL_Color color,int x, int y,  int width, int height);
	void paint(SDL_Renderer *renderer, int point1, int point2);
};