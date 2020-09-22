#include "GameLayer.hpp"
#include <iostream>
using namespace std;

#define PLAYER_WIDTH 20
#define PLAYER_HEIGHT 150

#define BALL_WIDTH 10
#define BALL_HEIGHT 10

#define SCORE_WIDTH 100
#define SCORE_HEIGHT 32

#define WIDTH 800
#define HEIGHT 600

GameLayer::GameLayer(SDL_Renderer * rend) : Layer(rend) {
	//llama al constructor del padre : Layer(renderer)
	init();
    this ->quit = false;
}

void GameLayer::init() {
	SDL_Color colorP1 ,colorP2, colorB, colorS;
     colorP1.r = 100;
     colorP1.g = 0;
     colorP1.b = 0;
     colorP1.a = 255;
     
     this-> player1 = new Player(0,0,PLAYER_WIDTH,PLAYER_HEIGHT, colorP1 );
     colorP2.r = 0;
     colorP2.g = 100;
     colorP2.b = 0;
     colorP2.a = 255;
     this -> player2 = new Player(WIDTH-PLAYER_WIDTH,HEIGHT-PLAYER_HEIGHT,PLAYER_WIDTH,PLAYER_HEIGHT, colorP2 );
     
    
    initBall();
	
    
    colorS.r = 0;
    colorS.g = 0;
    colorS.b = 0;
    colorS.a = 255;
    this->score = new Score(colorS, WIDTH/2 -SCORE_WIDTH/2, HEIGHT/2, SCORE_WIDTH, SCORE_HEIGHT);

}

void GameLayer::initBall()
{
    SDL_Color colorB;
    colorB.r = 100;
    colorB.g = 100;
    colorB.b = 100;
    colorB.a = 255;
    this -> ball = new Ball(WIDTH/2, HEIGHT/2, BALL_WIDTH, BALL_HEIGHT, colorB);
}

void GameLayer::processControls() 
{

	this->keysToControls();
    ball->colision(player1);
    ball->colision(player2);
	
}

void GameLayer::keysToControls() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
			switch (event.type) {
               case SDL_WINDOWEVENT:
                     switch (event.window.event) {
                         case SDL_WINDOWEVENT_CLOSE:   // exit game
                        this->quit =true;
                        break;
              
                     }

            case SDL_KEYDOWN:
				  // keyboard API for key pressed
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_W:
                    player2 -> moveUp();
                    break;
                case SDL_SCANCODE_UP:
                    player1 -> moveUp();
                    break;
                case SDL_SCANCODE_Q:
                    this->quit =true;
                    break;
                case SDL_SCANCODE_LEFT:
                    //rectPlayer1->x -= 1;
                    break;
                case SDL_SCANCODE_S:
                     player2 -> moveDown();
                    break;
                case SDL_SCANCODE_DOWN:
                    player1 -> moveDown();
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    //rectPlayer1->x += 1;
                    break;
                }
            }
        
		
	}
}

void GameLayer::update() {
	player1->update(this->rend);
    player2->update(this->rend);
    ball -> update(this->rend);
    
    //
    if(ball->x<0)
     {
         player2->setPoints(player2->getPoints()+1);
         initBall();
     }
     else if (ball->x>WIDTH)
     {
          player1->setPoints(player1->getPoints()+1);
           initBall();
     }
}

void GameLayer::draw() {
	
	player1->draw(rend);
    player2->draw(rend);
	ball->draw(rend);	
    this-> paintScore();
	
}

bool GameLayer::isQuit() {
	
	return this->quit;
}

void GameLayer::paintScore()
{
     this->score->paint(this->rend, player1->getPoints(), player2-> getPoints());
}