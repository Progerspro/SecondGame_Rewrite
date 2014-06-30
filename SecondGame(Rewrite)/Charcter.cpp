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

SDL_Texture* Charcter::LoadCharcter(int index)
{
	SDL_Texture* Temp_Texture = GameOBJ::LoadTextures.Get_Texture(index);
	if (Temp_Texture == NULL)
	{
		std::cerr << "No temp_texture at character found " << std::endl;
	}
	else
	{
		return Temp_Texture;
	}
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
	int check;
	SDL_Rect Dest_Rect;
	Dest_Rect.h = 128;
	Dest_Rect.w = 128;
	Dest_Rect.x = x;
	Dest_Rect.y = y;
	check = SDL_RenderCopy(Global_Data_LoadMedia::Global_Render, LoadCharcter(MainCharcter), NULL, &Dest_Rect);
	std::cout << "Check = " << check << SDL_GetError() << std::endl;
	
}