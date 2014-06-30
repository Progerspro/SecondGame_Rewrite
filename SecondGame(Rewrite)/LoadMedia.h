#pragma once

#include <string>
#include <vector>
class LoadMedia
{
private:
	std::string Path;
	bool success = true;
	std::vector<SDL_Texture*> Texture_Container;
	//SDL
	SDL_Surface* MainSurface = nullptr;
	SDL_Texture* MainTexture = nullptr;
	SDL_Texture* Temp_Texture = nullptr;
	SDL_Renderer* LocalRender = nullptr;
public:
	
	LoadMedia();
	~LoadMedia();

	void SurfacePath(std::string Surface_Path);
	void ImageInit();
	void PushTextureToContainer();
	void Free();
	void GetRenderer(SDL_Renderer* MainRender);
	bool LoadSurface();
	bool CreateTexture();
	//SDL
	SDL_Texture* Get_Texture(int Texture_Index);
};