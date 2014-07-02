#pragma once
#include "LoadMedia.h"
class Text
{
private:
	LoadMedia font;
public:
	Text();
	~Text();
	void LoadFont(std::string,int);
	void ShowText(std::string, SDL_Color,int,int);
	SDL_Texture* GetText();
};

