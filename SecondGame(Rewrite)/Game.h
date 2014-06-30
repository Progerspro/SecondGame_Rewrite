#pragma once



class Game
{
private:


	bool success = true;
	SDL_Window* MainWindow = nullptr;
public:
	Game();
	~Game();

	//Data
	const int SCREEN_WIDTH = 600, SCREEN_HEIGHT = 800;
	SDL_Renderer* MainRender = nullptr;
	SDL_Event event;
	//Functions
	bool Game_Init();
	int Game_Quit();
};

