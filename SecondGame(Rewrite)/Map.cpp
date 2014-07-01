#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	Init_Sprites();
}


Map::~Map()
{
}

void Map::PushMap(std::string Path_To_Map)
{
	GameOBJ::LoadTextures.PushTexture(Path_To_Map);
}

void Map::DrawMap(int x, int y)
{
	SDL_Rect dest = { x, y, SCREEN_WIDTH, SCREEN_HEIGHT };
	SDL_RenderCopy(Global_Data_LoadMedia::Global_Render, Get_Texture(Grass), &Sprite[Grass], &dest);
}

SDL_Texture* Map::Get_Map(int index)
{
	return GameOBJ::Get_Texture(index);
}

void Map::Init_Sprites()
{
	//Grass
	Sprite[0].h = 46;
	Sprite[0].w = 80;
	Sprite[0].y = 6;
	Sprite[0].x = 160;
}
