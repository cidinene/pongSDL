#include "Ball.hpp"
#include <iostream>
using namespace std;

#define DEFAULT_WIDTH 10
#define DEFAULT_HEIGHT 10
#define DEFAULT_DELTA 7
#define DEFAULT_COLOR_RGBA {255, 255, 255, 255};

Ball::Ball(int x, int y, int width, int height, SDL_Color color) : Actor(x, y, width, height)
{
    this->color = color;
    this->deltaX = DEFAULT_DELTA;
    this->deltaY = DEFAULT_DELTA;

    // Añadimos aleatoriedad para que no siempre salga en la misma dirección la bola
    this->direction_x = ((rand() % 2) == 0) ? -1 : 1;
    this->direction_y = ((rand() % 2) == 0) ? -1 : 1;
};

Ball::Ball(int x, int y) : Actor(x, y, DEFAULT_WIDTH, DEFAULT_HEIGHT)
{
    this->color = DEFAULT_COLOR_RGBA;
};

void Ball::draw(SDL_Renderer *rend)
{
    // guardamos el color inicial
    unsigned char previous_r, previous_g, previous_b, previous_a;
    SDL_GetRenderDrawColor(rend, &previous_r, &previous_g, &previous_b, &previous_a);
    //establecemos el color de nuestro jugador
    SDL_SetRenderDrawColor(rend, this->color.r, this->color.g, this->color.b, this->color.a);

    // establecemos el rectangulo con nuestros parámetros
    rectPlayer.x = this->x;
    rectPlayer.y = this->y;
    rectPlayer.w = this->width;
    rectPlayer.h = this->height;
    // pintamos el rectángulo
    SDL_RenderFillRect(rend, &rectPlayer);

    //restablecemos el color anterior
    SDL_SetRenderDrawColor(rend, previous_r, previous_g, previous_b, previous_a);
};

void Ball::update(SDL_Renderer *rend)
{
    this->x = this->x + this->deltaX * this->direction_x;
    this->y = this->y + this->deltaY * this->direction_y;

    int w, h;
    SDL_GetRendererOutputSize(rend, &w, &h);

    // si la bola sale por arriba o por abajo cambiamos la dirección y la velocidad
    if ((this->y + this->height) > h || this->y <= 0)
    {
        this->direction_y = this->direction_y * -1;
        this->deltaX = ((rand() % 3) + DEFAULT_DELTA);
        this->deltaY = ((rand() % 3) + DEFAULT_DELTA);
    }
};

bool Ball::colision(Actor *actor)
{

    bool isColision = Actor::colision(actor);
    if (isColision)
    {
        //deshacemos el cambio
        this->x = this->x - this->deltaX * this->direction_x;
        this->y = this->y - this->deltaY * this->direction_y;
        // calculamos aleatoriamente la nueva drección
        this->direction_x = this->direction_x * -1;
        this->deltaX = ((rand() % 3) + DEFAULT_DELTA);
        this->deltaY = ((rand() % 3) + DEFAULT_DELTA);
    }
};

int Ball::checkPoint()
{
    if ((this->x + this->width))
    {
        return 1;
    }
    else if (this->x < 0)
    {
        return -1;
    }
    else
        return 0;
}
Ball::~Ball(){};