#include "stdafx.h"
#include "GameOBJ.h"


GameOBJ::GameOBJ()
{
}


GameOBJ::~GameOBJ()
{
}

void GameOBJ::InitTextures()
{
	LoadTextures.GetRenderer(Game::MainRender);
}