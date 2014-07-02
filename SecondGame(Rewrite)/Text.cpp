#include "stdafx.h"
#include "Text.h"


Text::Text()
{
}


Text::~Text()
{
}

void Text::LoadFont(std::string Path,int Font_Size)
{
	font.FontInit();
	if (!font.LoadFont(Path, Font_Size))
		std::cerr << "From text class: could not load font" << TTF_GetError() << std::endl;
}

void Text::ShowText(std::string Text, SDL_Color Text_Colour,int x,int y)
{
	SDL_Rect dest = { x, y, font.GetFontWidth(),font.GetFontHeight()};
	if (!font.PushFont(Text, Text_Colour))
		std::cerr << "From text class: could not show text" << TTF_GetError() << std::endl;
	SDL_RenderCopy(Global_Data_LoadMedia::Global_Render, GetText(), NULL, &dest);
}

SDL_Texture* Text::GetText()
{
	static int index;
	SDL_Texture* Temp_Texture = font.Get_Texture(index);
	if (Temp_Texture == NULL)
		std::cerr << "Could not get text" << std::endl;
	index++;
	return Temp_Texture;
}
