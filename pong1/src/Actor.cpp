
#include "Actor.hpp"

Actor::Actor(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width= width;
    this->height = height;
    
};
 bool Actor::colision(Actor * actor)
 {
     bool overlap = false;
	if ((actor->x - actor->width) <= (x + width )
		&& (actor->x + actor->width ) >= (x - width )
		&& (actor->y + actor->height ) >= (y - height )
		&& (actor->y - actor->height )<= (y + height )) {

		overlap = true;
	}
	return overlap;

 }