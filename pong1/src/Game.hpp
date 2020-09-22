#pragma once

// Todas las librerias de SDL y otras utilidades
#include <iostream>
#include <string>
using namespace std;
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// Valores generales
#define WIDTH 800
#define HEIGHT 600

#include "Layer.hpp"
class Layer;

class Game
{
public:
	Game();
	void loop();
	void scale();
	bool scaledToMax = false;
	SDL_Window* window; // ventana
	SDL_Renderer* renderer; // renderizador
	bool loopActive; // Juego activo
	Layer* gameLayer;
};
