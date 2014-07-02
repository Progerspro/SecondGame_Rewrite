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
	if (Check_IfInitImage == false)
	{
		ImageInit();
		Check_IfInitImage = true;
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
	Surface_Container.clear();
	Temp_Texture_Get = nullptr;
	MainSurface = nullptr;
	Font = nullptr;
	IMG_Quit();
	TTF_Quit();
}

//Dont delete Checks if everything is good
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


bool LoadMedia::LoadFont(std::string Path_To_Font,int Font_Size)
{
	Font = TTF_OpenFont(Path_To_Font.c_str(), Font_Size);
	if (Font == NULL)
	{
		std::cerr << "Could not open font " << TTF_GetError() << std::endl;
		success = false;
	}
	return success;
}

bool LoadMedia::Make_Surface_Text(std::string Text,SDL_Color Text_Colour)
{
	Surface_Container.push_back(TTF_RenderText_Solid(Font, Text.c_str(), Text_Colour));
	if (Surface_Container.back() == NULL)
	{
		std::cerr << "Could not load font surface " << TTF_GetError() << std::endl;
		success = false;
	}
	return success;
}

bool LoadMedia::CreateFontTexture()
{
	
	Texture_Container.push_back(SDL_CreateTextureFromSurface(LocalRender, Surface_Container.back()));
	if (Texture_Container.back() == NULL)
	{
		std::cerr << "Could not create texture from surface! " << SDL_GetError << std::endl;
		success = false;
	}
	return success;
}

bool LoadMedia::PushFont( std::string Text,SDL_Color FontColour)
{
	
		if (!Make_Surface_Text(Text, FontColour))
		{
			std::cerr << "Could not make surface from the font!" << std::endl;
			success = false;
		}
		else
		{
			if (!CreateFontTexture())
			{
				std::cerr << "Could not create texture from font surface!" << std::endl;
			}
		}
		return success;
}

void LoadMedia::FontInit()
{
	GetRenderer();
	if (TTF_Init() == -1)
		std::cerr << "Could not init ttf font! " << TTF_GetError() << std::endl;
}

int LoadMedia::GetFontWidth(int index)
{
	SDL_Surface* Temp_Surface = Surface_Container[index];
	if (Temp_Surface == NULL)
		std::cerr << "Could not take the width from the surface" << std::endl;
	return Temp_Surface->w;
}

int LoadMedia::GetFontHeight(int index)
{
	SDL_Surface* Temp_Surface = Surface_Container[index];
	if (Temp_Surface == NULL)
	std::cerr << "Could not take the width from the surface" << std::endl;
	return Temp_Surface->h;
}



