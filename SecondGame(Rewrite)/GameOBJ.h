#pragma once
#include "Game.h"
#include "LoadMedia.h"
class GameOBJ :
	private Game
{
protected:
	LoadMedia LoadTextures;
public:
	GameOBJ();
	~GameOBJ();
	void InitTextures();
	void HandleEvent();
};

