#include "stdafx.h"
#include "GameOBJ.h"


GameOBJ::GameOBJ()
{
}


GameOBJ::~GameOBJ()
{
}

void GameOBJ::Global_PushTexture(std::string Path_To_Texture)
{
	LoadTextures.PushTexture(Path_To_Texture);
}

SDL_Texture* GameOBJ::Get_Texture(int index)
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