#include "Player.hpp"

#include <iostream>
using namespace std;
#define DEFAULT_WIDTH 20
#define DEFAULT_HEIGHT 150
#define DEFAULT_DELTA 30
#define DEFAULT_COLOR_RGBA {255, 255, 255, 255};

Player::Player(int x, int y, int width, int height, SDL_Color color) : Actor(x, y, width, height)
{
    this->color = color;
    this->delta = DEFAULT_DELTA;
    this->up = 0;
    this->down = 0;
    this->points =0;
};
Player::Player(int x, int y) : Actor(x, y, DEFAULT_WIDTH, DEFAULT_HEIGHT)
{
    this->color = DEFAULT_COLOR_RGBA;
};
void Player::draw(SDL_Renderer *rend)
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
}

void Player::update(SDL_Renderer *rend)
{
    int w, h;
    SDL_GetRendererOutputSize(rend, &w, &h);
    //COMPROBAMOS QUE CON EL MOVIMIENTO NO NOS SALIMOS DEL AREA DE DIBUJO POR ARRIBA
    if (this->up && ((this->y ) > 0))
    {
        this->y = this->y - DEFAULT_DELTA;
        this->up = 0;
    }
    //COMPROBAMOS QUE CON EL MOVIMIENTO NO NOS SALIMOS DEL AREA DE DIBUJO POR ABAJO
    if (this->down && ((this->y + this->height) < h))
    {
        this->y = this->y + DEFAULT_DELTA;
        this->down = 0;
    }
}

void Player::moveUp()
{
    this->up = 1;
    
}
void Player::moveDown()
{
    this->down = 1;
}

void Player::setPoints(int points)
{
    this->points = points;
}
int Player::getPoints()
{
    return this->points;
}
Player::~Player()
{
}