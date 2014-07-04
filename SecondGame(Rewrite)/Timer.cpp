#include "stdafx.h"
#include "Timer.h"


Timer::Timer() : streamFPS("")
{
	Dest.x = 0;
	Dest.y = 0;
	Color = { 255, 0, 0, 0 };
}


Timer::~Timer()
{
	SDL_DestroyTexture(Text_Texture);
	SDL_FreeSurface(Text_Surface);
	Text_Texture = nullptr;
	Text_Surface = nullptr;
}


void Timer::Init_Font()
{
	if (TTF_Init() == -1)
		std::cerr << "Error from Timer.cpp: Could not init ttf " <<TTF_GetError() <<  std::endl;
}

void Timer::Load_Font(std::string Path, int Size)
{
	Font = TTF_OpenFont(Path.c_str(), Size);
	if (Font == NULL)
		std::cerr << "Error from Timer.cpp: Could not load font " << TTF_GetError() << std::endl;
}

SDL_Texture* Timer::Create_Text(std::string Text, SDL_Color Colour)
{

	if (a == true)
	{
		SDL_DestroyTexture(Temp_Texture);
	}
	a = true;
	Text_Surface = TTF_RenderText_Solid(Font, Text.c_str(), Colour);
		if (Text_Surface == NULL)
		{
		std::cerr << "Error from Timer.cpp: Could not make text surface " << TTF_GetError() << std::endl;
		}
		else
		{
			Text_Texture = SDL_CreateTextureFromSurface(Global_Data_LoadMedia::Global_Render, Text_Surface);
			Swidth = Text_Surface->w;
			Sheight = Text_Surface->h;
			if (Text_Texture == NULL)
				std::cerr << "Error from Timer.cpp: Could not make texture from surface " << TTF_GetError() << std::endl;
		}
		SDL_FreeSurface(Text_Surface);
		return Text_Texture;
}

void Timer::Init(std::string Path, int Size)
{
	Init_Font();
	Load_Font(Path, Size);
}

void Timer::ShowFps()
{
	static int Frames;
	//TODO: Make some fixes for the minimized window frame rate
	FrameRate = Frames / (SDL_GetTicks() / 1000);
	streamFPS.str("");
	streamFPS << "Your current FPS is: " << FrameRate;
	Temp_Texture = Create_Text(streamFPS.str(),Color);
	Dest.h = Sheight;
	Dest.w = Swidth;
	SDL_RenderCopy(Global_Data_LoadMedia::Global_Render, Temp_Texture, NULL, &Dest);
		Frames++;
		
}

int Timer::GetGameTimeWork()
{
	return SDL_GetTicks();
}


