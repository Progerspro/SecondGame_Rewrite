#pragma once

#include <string>
#include <vector>
class LoadMedia
{
private:
	//DATA
	std::string Path;
	bool success = true;
	std::vector<SDL_Texture*> Texture_Container;

	//Functions
	void Free();
	void ImageInit();
	void PushTextureToContainer();
	bool LoadSurface();
	bool CreateTexture();
	//SDL
	SDL_Surface* MainSurface = nullptr;
	SDL_Texture* MainTexture = nullptr;
	SDL_Texture* Temp_Texture = nullptr;
	SDL_Renderer* LocalRender = nullptr;
public:
	
	LoadMedia();
	~LoadMedia();

	void PushTexture(std::string Surface_Path);
	void GetRenderer(SDL_Renderer* MainRender);
	
	//SDL
	SDL_Texture* Get_Texture(int Texture_Index);
};