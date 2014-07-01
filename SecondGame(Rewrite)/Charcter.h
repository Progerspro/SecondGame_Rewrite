#pragma once
#include "GameOBJ.h"
const int LINE = 4,COLUMN = 8;
const int Charcter_Height = 29, Charcter_Width = 15;
class Charcter : public GameOBJ
{
private:
	enum{MainCharcter};
	SDL_Rect Sprite[LINE][COLUMN];
	SDL_Texture* Get_Charcter(int index);
	void Init_Sprites();

public:
	Charcter();
	~Charcter();

	void PushCharcter(std::string Path);
	
	void DrawCharcter(int=0,int=0,int=0,int=0,int=0);

	void HandleEvent(SDL_Event* event);
	void Move(int x,int y);

};

