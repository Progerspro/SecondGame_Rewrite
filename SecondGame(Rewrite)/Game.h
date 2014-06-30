#pragma once

struct GameData
{
	const int SCREEN_WIDTH = 600, SCREEN_HEIGHT = 800;
	SDL_Renderer* MainRender = nullptr;
};

class Game
{
private:
	bool success = true;
	SDL_Window* MainWindow = nullptr;
public:
	Game();
	~Game();
	GameData GData;
	bool Game_Init();
	int Game_Quit();
};

