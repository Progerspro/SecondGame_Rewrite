#pragma once
#include "Game.h"
#include "LoadMedia.h"
class GameOBJ : protected Game
{
protected:
	LoadMedia LoadTextures;
public:
	GameOBJ();
	~GameOBJ();
	void Global_PushTexture(std::string);
	SDL_Texture* Get_Texture(int);
	void HandleEvent();
};

