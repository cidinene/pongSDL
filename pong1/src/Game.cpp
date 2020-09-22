#include "Game.hpp"
#include "GameLayer.hpp"

Game::Game() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Error SDL_Init" << SDL_GetError() << endl;
	}

	this ->window = SDL_CreateWindow("Pong",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       WIDTH, HEIGHT, 0);

	//this ->window= SDL_CreateWindow("PONG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_FULLSCREEN ); 
									   
	// triggers the program that controls
    // your graphics hardware and sets flags
     Uint32 render_flags = SDL_RENDERER_ACCELERATED;


    srand(SDL_GetTicks());
    // creates a renderer to render our images
    this->renderer = SDL_CreateRenderer(this ->window, -1, render_flags);

     
	if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) {
		cout << "Error Window y Renderer" << SDL_GetError() << endl;
	}
	
	gameLayer = new GameLayer(renderer);

	loopActive = true; // bucle activo
	
}


void Game::scale(){
	scaledToMax = !scaledToMax;

	if (scaledToMax) {
		SDL_DisplayMode PCdisplay;
		SDL_GetCurrentDisplayMode(0, &PCdisplay);
		float scaleX = (float)PCdisplay.w / (float)WIDTH;
		float scaleY = (float)PCdisplay.h / (float)HEIGHT;
		// Necesitamos la menor de las 2 escalas para no deformar el juego
		float scaleLower = scaleX; 
		if (scaleY < scaleX) {
			scaleLower = scaleY;
		}
		// Cambiar dimensiones ventana
		SDL_SetWindowSize(window, WIDTH * scaleLower, HEIGHT * scaleLower);
		// Cambiar escala del render
		SDL_RenderSetScale(renderer, scaleLower, scaleLower);
	}
	else { // Escala Original
		// Cambiar dimensiones ventana
		SDL_SetWindowSize(window, WIDTH, HEIGHT);
		// Cambiar escala del render
		SDL_RenderSetScale(renderer, 1, 1);
	}

}

void Game::loop() {
	int initTick; // ms de inicio loop
	int endTick; // ms de fin de loop
	int differenceTick; // fin - inicio
	int loops = 0;
	while (!gameLayer->isQuit()) {
		initTick = SDL_GetTicks();

		// Controles
		gameLayer->processControls();
		// Actualizar elementos
		gameLayer->update();
		// Dibujar
		SDL_RenderClear(this->renderer);
		gameLayer->draw();
		SDL_RenderPresent(this ->renderer);
		endTick = SDL_GetTicks();
		differenceTick = endTick - initTick;

		if (differenceTick < (1000 / 30)) {
			SDL_Delay((1000 / 30) - differenceTick);
		}

	}
	if (gameLayer->isQuit())
	{
	SDL_DestroyRenderer(this -> renderer);

    // destroy window
    SDL_DestroyWindow(this->window);
    SDL_Quit(); 
	}
}

