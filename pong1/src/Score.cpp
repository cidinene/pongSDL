#include "Score.hpp"

#define SEPARATOR "-"

Score::Score(SDL_Color color,int x, int y,  int width, int height)
{

	TTF_Init();
	this ->font = TTF_OpenFont("res/Verdana.ttf", 24);
	this -> x = x; 
	this -> y = y;
	this -> width = width;
	this -> height = height;
	

};

void Score::paint(SDL_Renderer *renderer, int point1, int point2)
{
	const  char * text =  (to_string(point1) +SEPARATOR +to_string(point2)).c_str();

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(this->font,text , {255, 255, 255, 255}); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = this -> x; 
	Message_rect.y = this -> y; 
	Message_rect.w = this -> width; 
	Message_rect.h = this -> height; 


	SDL_RenderCopy(renderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

	//Don't forget to free your surface and texture
	SDL_FreeSurface(surfaceMessage);
	
};


