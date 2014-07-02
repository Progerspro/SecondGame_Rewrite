#pragma once
#include "GameOBJ.h"
class Map : public GameOBJ
{
private:
	enum{Grass};
	SDL_Rect Sprite[1];
public:
	Map();
	~Map();
	void PushMap(std::string);
	void DrawMap(int=0,int=0,int=0);
	void Init_Sprites();
	SDL_Texture* Get_Map(int = 0);
};

