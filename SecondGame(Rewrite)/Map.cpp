#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	Init_Sprites();
	Init_Destination();
}


Map::~Map()
{
}

void Map::PushMap(std::string Path_To_Map)
{
	GameOBJ::LoadTextures.PushTexture(Path_To_Map);
}

void Map::MakeGrass()
{
	SDL_Texture* TempTexture = Get_Texture(0);
	for (int height = 0; height < 16; height++)
	{
		for (int width = 0; width < 18; width++)
		{
			if (width >= 1)
			{
				Destination[0].x = (width * 80) - 27 - (27 * width);
			}
			else
			{
				Destination[0].x = (width * 80) - 27;
			}
			if (height >= 1)
			{
				Destination[0].y = (height * 46) - 8 - (8 * height);
			}
			else
			{
				Destination[0].y = height * 46 - 8;
			}
			SDL_RenderCopy(Global_Data_LoadMedia::Global_Render, TempTexture, &Sprite[0], &Destination[0]);
		}
	}
}

void Map::Draw(int x, int y,int index)
{
	SDL_Texture* TempTexture = Get_Texture(0);
	Destination[index].x = x;
	Destination[index].y = y;
	SDL_RenderCopy(Global_Data_LoadMedia::Global_Render, TempTexture , &Sprite[index], &Destination[index]);
}

SDL_Texture* Map::Get_Map(int index)
{
	return GameOBJ::Get_Texture(index);
}

void Map::Init_Destination()
{
	//Grass
	Destination[0].h = 46;
	Destination[0].w = 80;
	
	//Chair
	Destination[1].h = 26;
	Destination[1].w = 47;

}

void Map::Init_Sprites()
{
	//Grass
	Sprite[0].h = 46;
	Sprite[0].w = 80;
	Sprite[0].y = 6;
	Sprite[0].x = 160;
	//Chair
	Sprite[1].h = 26;
	Sprite[1].w = 47;
	Sprite[1].y = 243;
	Sprite[1].x = 72;
}
