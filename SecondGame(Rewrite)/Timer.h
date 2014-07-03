#pragma once
#include <sstream>
#include "LoadMedia.h"
//We have second render text system here, because LoadMedia.h system can't do many vector saves
//Warning:THIS RENDER JUST FOR FPS AND Timer! For standard text use LoadMedia render system.
class Timer
{
private:
	//Data
	std::stringstream streamFPS;
	SDL_Texture* Temp_Texture;
	TTF_Font* Font;
	SDL_Surface* Text_Surface;
	SDL_Texture* Text_Texture;
	Uint32 CurrentTime;
	int FrameRate;
	int Swidth, Sheight;
	SDL_Rect Dest;
	SDL_Color Color;
	//Functions:
	void Init_Font();
	void Load_Font(std::string="",int=10);
	SDL_Texture* Create_Text(std::string, SDL_Color);
	bool a = false;
	
public:
	Timer();
	~Timer();
	void Init(std::string Path, int Size);
	int GetGameTimeWork();
	void ShowFps();

};

