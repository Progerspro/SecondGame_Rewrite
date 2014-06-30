#include "stdafx.h"
#include "Charcter.h"


Charcter::Charcter()
{
	Sprites();
}


Charcter::~Charcter()
{
}

void Charcter::PushCharcter(std::string Path)
{
	LoadTextures.PushTexture(Path);
}

SDL_Texture* Charcter::LoadCharcter()
{
	return LoadTextures.Get_Texture(MainCharcter);
}

void Charcter::Sprites()
{
	for (int a = 0; a < LINE; a++)
	{
		for (int b = 0; b < COLUMN; b++)
		{
				Sprite[a][b].h = Charcter_Height;
				Sprite[a][b].w = Charcter_Width;
				Sprite[a][b].y = a * 32 + 1;
				Sprite[a][b].x = b * 15;
		}
	}
}

void Charcter::DrawCharcter(int x, int y, int rotate)
{
	SDL_Rect Dest_Rect;
	Dest_Rect.h = Charcter_Height;
	Dest_Rect.w = Charcter_Width;
	Dest_Rect.x = x;
	Dest_Rect.y = y;
	SDL_RenderCopy(Game::MainRender, LoadCharcter(), &Sprite[1][1], &Dest_Rect);
}