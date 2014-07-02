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
void Text::LoadText(std::string Text, SDL_Color Text_Colour)
{
	if (!font.PushFont(Text, Text_Colour))
		std::cerr << "From text class: could not show text" << TTF_GetError() << std::endl;
}
void Text::ShowText(int x,int y,int index)
{
	SDL_Rect dest = { x, y, font.GetFontWidth(index),font.GetFontHeight(index)};

	SDL_RenderCopy(Global_Data_LoadMedia::Global_Render, GetText(index), NULL, &dest);
}

SDL_Texture* Text::GetText(int TextIndex)
{
	SDL_Texture* Temp_Texture = font.Get_Texture(TextIndex);
	if (Temp_Texture == NULL)
		std::cerr << "Could not get text" << std::endl;
	return Temp_Texture;
}