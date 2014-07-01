#include "stdafx.h"
#include "Charcter.h"


Charcter::Charcter()
{
	Init_Sprites();
}


Charcter::~Charcter()
{
}

void Charcter::PushCharcter(std::string Path_To_Charcter)
{
	GameOBJ::Global_PushTexture(Path_To_Charcter);
}

SDL_Texture* Charcter::Get_Charcter(int index)
{
	return GameOBJ::Get_Texture(index);
}


void Charcter::Init_Sprites()
{
	for (int a = 0; a < LINE; a++)
	{
		for (int b = 0; b < COLUMN; b++)
		{
			Sprite[a][b].y = a * 32 + 2;
			Sprite[a][b].x = b * 15;
			Sprite[a][b].h = Charcter_Height;
			Sprite[a][b].w = Charcter_Width;

		}
	}
}

void Charcter::DrawCharcter(int x, int y,int modeX,int modeY, int rotate)
{
	SDL_Rect Dest_Rect;
	Dest_Rect.h = 128;
	Dest_Rect.w = 128;
	Dest_Rect.x = x;
	Dest_Rect.y = y;
	SDL_RenderCopy(Global_Data_LoadMedia::Global_Render, Get_Charcter(MainCharcter), &Sprite[modeX][modeY], &Dest_Rect);
}