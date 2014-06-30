#include "stdafx.h"
#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

bool Game::Game_Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Could not init video! " << SDL_GetError << std::endl;
		success = false;
	}
	else
	{
		MainWindow = SDL_CreateWindow("SecondGame(Rewrite)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (MainWindow == NULL)
		{
			std::cerr << "Could not create MainWindow! " << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			MainRender = SDL_CreateRenderer(MainWindow, -1, SDL_RENDERER_ACCELERATED);
			if (MainRender == NULL)
			{
				std::cerr << "Could not create MainRender! " << SDL_GetError() << std::endl;
				success = false;
			}
		}
	}
	return success;
}

int Game::Game_Quit()
{
	SDL_DestroyWindow(MainWindow);
	SDL_DestroyRenderer(MainRender);
	MainWindow = nullptr;
	MainRender = nullptr;
	SDL_Quit();
	exit(0);
	return 0;
}