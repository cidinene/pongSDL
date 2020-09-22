
#pragma once
#include <SDL2/SDL.h>
#include "Layer.hpp"
#include "Ball.hpp"
#include "Player.hpp"
#include "Score.hpp"

class GameLayer : public Layer
{
private:
	void initBall();
	void paintScore();

public:
	GameLayer(SDL_Renderer *rend);
	void init() override;
	void processControls() override;
	void update() override;
	void draw() override;
	void keysToControls();
	bool isQuit();

	int newEnemyTime = 0;
	bool quit = 0;
	Player *player1;
	Player *player2;
	Ball *ball;
	Score *score;
};