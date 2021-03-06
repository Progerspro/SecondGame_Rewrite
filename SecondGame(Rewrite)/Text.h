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
	void ShowText(int,int,int);
	SDL_Texture* GetText(int TextIndex);
	int font_Width(int);
	int font_Height(int);
	void LoadText(std::string Text, SDL_Color Text_Colour);
};

