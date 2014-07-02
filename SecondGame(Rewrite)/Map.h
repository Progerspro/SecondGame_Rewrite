#pragma once
#include "GameOBJ.h"
class Map : public GameOBJ
{
private:
	
	SDL_Rect Sprite[3];
	SDL_Rect Destination[3];
public:
	Map();
	~Map();
	static enum{ Grass, Chair };
	void PushMap(std::string);
	void Draw(int=0,int=0,int=1);
	void Init_Sprites();
	void MakeGrass();
	void Init_Destination();
	SDL_Texture* Get_Map(int = 0);
};

