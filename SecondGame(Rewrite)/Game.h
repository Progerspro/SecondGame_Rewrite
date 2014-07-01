#pragma once
#include "LoadMedia.h"
class Game
{
private:


	bool success = true;
	SDL_Window* MainWindow = nullptr;
public:
	Game();
	~Game();

	//Data
	const int SCREEN_WIDTH = 900, SCREEN_HEIGHT = 600;
	SDL_Renderer* MainRender = nullptr;
	SDL_Event event;
	//Functions
	bool Game_Init();
	int Game_Quit();
};

