#include "stdafx.h"
#include "LoadMedia.h"


LoadMedia::LoadMedia()
{
	
}


LoadMedia::~LoadMedia()
{
	Free();
	Texture_Container.clear();
}

namespace Global_Data_LoadMedia
{
	 SDL_Renderer* Global_Render;
}


void LoadMedia::PushTexture(std::string Path_To_Surface)
{
	Path = Path_To_Surface;
	ImageInit();
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

void LoadMedia::PushTextureToContainer()
{
	Texture_Container.push_back(MainTexture);
}

void LoadMedia::Free()
{
	SDL_DestroyTexture(MainTexture);
	SDL_DestroyTexture(Temp_Texture);
	SDL_FreeSurface(MainSurface);

	MainTexture = nullptr;
	Temp_Texture = nullptr;
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
		// SDL_SetColorKey(MainSurface, SDL_TRUE, SDL_MapRGB(MainSurface->format, 0, 0, 0));
	}
	return success;
}

bool LoadMedia::CreateTexture()
{
	GetRenderer();
	MainTexture = SDL_CreateTextureFromSurface(LocalRender, MainSurface);
	if (MainTexture == NULL)
	{
		std::cerr << "Could not create texture from surface! " << SDL_GetError << std::endl;
		success = false;
	}
	else
	{
		PushTextureToContainer();
		Free();
	}
	return success;
}

SDL_Texture* LoadMedia::Get_Texture(int Texture_Index)
{
	Free();
	Temp_Texture = Texture_Container[Texture_Index];
	if (Temp_Texture == NULL)
	{
		std::cerr << "Could not Get_Texture with Index " << Texture_Index << std::endl;
		return NULL;
	}
	else
	{
		return Temp_Texture;
	}
}