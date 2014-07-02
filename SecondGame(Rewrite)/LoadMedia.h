#pragma once

#include <string>
#include <vector>

namespace Global_Data_LoadMedia
{
	extern SDL_Renderer* Global_Render;
}

class LoadMedia
{
private:
	//DATA
	std::string Path;
	bool success = true;
	std::vector<SDL_Texture*> Texture_Container;

	void Free();
	void GetRenderer();
	//Functions Surface
	void ImageInit();
	bool LoadSurface();
	bool CreateTexture();
	bool Check_IfInitImage = false;
	//Functions Font
	bool Make_Surface_Text(std::string, SDL_Colour);
	bool CreateFontTexture();
	bool Check_IfInitFont = false;
	int FontWidth, FontHeight;
	//SDL
	SDL_Surface* MainSurface = nullptr;
	SDL_Texture* Temp_Texture_Get = nullptr;
	SDL_Renderer* LocalRender = nullptr;
	SDL_Surface* FontSurface = nullptr;
	TTF_Font* Font = nullptr;
public:
	
	LoadMedia();
	~LoadMedia();
	//Image
	void PushTexture(std::string Surface_Path);
	bool LoadFont(std::string, int);
	//Font
	void FontInit();
	int GetFontWidth();
	int GetFontHeight();
	bool PushFont(std::string,SDL_Color);
	//SDL
	SDL_Texture* Get_Texture(int Texture_Index);
};