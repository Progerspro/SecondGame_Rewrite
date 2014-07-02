#pragma once
#include "GameOBJ.h"
const int LINE = 4,COLUMN = 8;
const int Charcter_Height = 29, Charcter_Width = 15;
class Charcter : public GameOBJ
{
private:
	static enum Speed{ Charcter_Speed = 2 };
	enum{MainCharcter};
	SDL_Rect Sprite[LINE][COLUMN];
	SDL_Texture* Get_Charcter(int index);
	void Init_Sprites();
	int XVelocity = 0, YVelocity = 0;
	int XPos = 0, YPos = 0;
	int Frame = 0,Status = 0;
	const Uint8 *KeyBoardState;

public:
	Charcter();
	~Charcter();

	void PushCharcter(std::string Path);
	
	void RenderCharcter(int=0,int=0,int=0,int=0,int=0);

	void HandleEvent(SDL_Event);
	void Move();

};

