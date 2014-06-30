#pragma once
#include "Game.h"
#include "LoadMedia.h"
class GameOBJ : protected Game
{
protected:
	LoadMedia LoadTextures;
	enum {MainCharcter,MainMap};
public:
	GameOBJ();
	~GameOBJ();
	
	void HandleEvent();
};

