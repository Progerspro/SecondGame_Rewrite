#include "stdafx.h"
#include "LoadMedia.h"


LoadMedia::LoadMedia()
{
	
}


LoadMedia::~LoadMedia()
{
	Free();
}

namespace Global_Data_LoadMedia
{
	 SDL_Renderer* Global_Render;
}


void LoadMedia::PushTexture(std::string Path_To_Surface)
{
	Path = Path_To_Surface;
	if (CheckIfInit == false)
	{
		ImageInit();
		CheckIfInit = true;
	}
	if (!LoadSurface())
	{
		std::cerr << "Failed to push texture at LoadSurface" << std::endl;
	}
	else 
	{
		if (!CreateTexture())
		{
			std::cerr << "Failed to push texture at CreateTexture" << std::endl;
		}
	}
}

void LoadMedia::ImageInit()
{
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		std::cerr << "SDL_image could not initialize! SDL_image Error: \n" << IMG_GetError() << std::endl;
	}
	else
	{
		std::cout << "PNG Init Success!" << std::endl;
	}
}



void LoadMedia::Free()
{
	SDL_DestroyTexture(Temp_Texture_Get);
	SDL_FreeSurface(MainSurface);
	Texture_Container.clear();
	Temp_Texture_Get = nullptr;
	MainSurface = nullptr;
}

void LoadMedia::GetRenderer()
{
	LocalRender = Global_Data_LoadMedia::Global_Render;
	if (LocalRender == NULL)
	{
		std::cerr << "ERROR! Could not import MainRender to LocalRender" << std::endl;
	}
}

bool LoadMedia::LoadSurface()
{
	
	MainSurface = IMG_Load(Path.c_str());
	if (MainSurface == NULL)
	{
		std::cerr << "Could not load surface! " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		 SDL_SetColorKey(MainSurface, SDL_TRUE, SDL_MapRGB(MainSurface->format, 255, 0, 255));
	}
	return success;
}

bool LoadMedia::CreateTexture()
{
	GetRenderer();
	Texture_Container.push_back(SDL_CreateTextureFromSurface(LocalRender, MainSurface));

	if (Texture_Container.back() == NULL)
	{
		std::cerr << "Could not create texture from surface! " << SDL_GetError << std::endl;
		success = false;
	}
	return success;
}

SDL_Texture* LoadMedia::Get_Texture(int Texture_Index)
{
	Temp_Texture_Get = Texture_Container[Texture_Index];
	if (Temp_Texture_Get == NULL)
	{
		std::cerr << "Could not Get_Texture with Index " << Texture_Index << std::endl;
		return NULL;
	}
	else
	{
		return Temp_Texture_Get;
	}
}