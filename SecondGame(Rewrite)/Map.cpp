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
	SDL_Rect dest;
	dest.h = 46;
	dest.w = 80;
	for (int height = 0; height < 16; height++)
	{
		for (int width = 0; width < 18; width++)
		{
			if (width >= 1)
			{
				dest.x = (width * 80) - 27 - (27 * width);
			}
			else
			{
				dest.x = (width * 80) - 27;
			}
			if (height >= 1)
			{
				dest.y = (height * 46) - 8 - (8 * height);
			}
			else
			{
				dest.y = height * 46 - 8;
			}
			SDL_RenderCopy(Global_Data_LoadMedia::Global_Render, Get_Texture(Grass), &Sprite[Grass], &dest);
		}
	}
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
