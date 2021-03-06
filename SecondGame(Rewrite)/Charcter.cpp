#include "stdafx.h"
#include "Charcter.h"


Charcter::Charcter()
{
	Init_Sprites();
}


Charcter::~Charcter()
{
}

void Charcter::PushCharcter(std::string Path_To_Charcter)
{
	GameOBJ::Global_PushTexture(Path_To_Charcter);
}

SDL_Texture* Charcter::Get_Charcter(int index)
{
	return GameOBJ::Get_Texture(index);
}


void Charcter::Init_Sprites()
{
	for (int a = 0; a < LINE; a++)
	{
		for (int b = 0; b < COLUMN; b++)
		{
			Sprite[a][b].y = a * 32 + 2;
			Sprite[a][b].x = b * 16;
			Sprite[a][b].h = Charcter_Height;
			Sprite[a][b].w = Charcter_Width;

		}
	}
}

void Charcter::RenderCharcter(int x, int y,int modeX,int modeY, int rotate)
{
	SDL_Rect Dest_Rect;
	Dest_Rect.h = 29;
	Dest_Rect.w = 16;
	Dest_Rect.x = XPos;
	Dest_Rect.y = YPos;
	modeX = Status;
	modeY = Frame / 2;
	SDL_RenderCopy(Global_Data_LoadMedia::Global_Render, Get_Charcter(MainCharcter), &Sprite[modeX][modeY], &Dest_Rect);
}

void Charcter::HandleEvent(SDL_Event event)
{
	//Fix this by help  http://lazyfoo.net/tutorials/SDL/26_motion/index.php
	if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:
			XVelocity -= Charcter_Speed;
			Status = 2;
			
			std::cout << "XVelocity = " << XVelocity << std::endl;
			break;
		case SDLK_RIGHT:
			XVelocity += Charcter_Speed;
			Status = 0;
			
			std::cout << "XVelocity = " << XVelocity << std::endl;
			break;
		case SDLK_DOWN:
			YVelocity += Charcter_Speed;
			Status = 3;
		
			std::cout << "YVelocity = " << YVelocity << std::endl;
			break;
		case SDLK_UP:
			YVelocity -= Charcter_Speed;
			Status = 1;
			
			std::cout << "YVelocity = " << YVelocity << std::endl;
			break;
		}
	}
	else if (event.type == SDL_KEYUP && event.key.repeat == 0)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:
		
			XVelocity += Charcter_Speed;
			std::cout << "XVelocity = " << XVelocity << std::endl;
			//Fix MOVE BUG
			KeyBoardState = SDL_GetKeyboardState(NULL);
			if (KeyBoardState[SDL_SCANCODE_UP] == 1)
				Status = 1;
			if (KeyBoardState[SDL_SCANCODE_RIGHT] == 1)
				Status = 0;
			if (KeyBoardState[SDL_SCANCODE_DOWN] == 1)
				Status = 3;
			//END
			break;
		case SDLK_RIGHT:
			XVelocity -= Charcter_Speed;
		
			std::cout << "XVelocity = " << XVelocity << std::endl;

			//Fix MOVE BUG
			KeyBoardState = SDL_GetKeyboardState(NULL);
			if (KeyBoardState[SDL_SCANCODE_UP] == 1)
				Status = 1;
			if (KeyBoardState[SDL_SCANCODE_LEFT] == 1)
				Status = 2;
			if (KeyBoardState[SDL_SCANCODE_DOWN] == 1)
				Status = 3;
			//END
			break;
		case SDLK_DOWN:
		
			YVelocity -= Charcter_Speed;
			
			std::cout << "YVelocity = " << YVelocity << std::endl;
			//Fix MOVE BUG
			KeyBoardState = SDL_GetKeyboardState(NULL);
			if (KeyBoardState[SDL_SCANCODE_UP] == 1)
				Status = 1;
			if (KeyBoardState[SDL_SCANCODE_RIGHT] == 1)
				Status = 0;
			if (KeyBoardState[SDL_SCANCODE_LEFT] == 1)
				Status = 2;
			//END
			break;
		case SDLK_UP:
		
			YVelocity += Charcter_Speed;
			
			std::cout << "YVelocity = " << YVelocity << std::endl;
			//Fix MOVE BUG
			KeyBoardState = SDL_GetKeyboardState(NULL);
			if (KeyBoardState[SDL_SCANCODE_LEFT] == 1)
				Status = 2;
			if (KeyBoardState[SDL_SCANCODE_RIGHT] == 1)
				Status = 0;
			if (KeyBoardState[SDL_SCANCODE_DOWN] == 1)
				Status = 3;
			//END
			break;
		}
	}
}

void Charcter::Move(SDL_Rect* Wall,int ArraySize)
{

	if (Frame / 2 == 3)
	{
		Frame = 0;
	}
	
	//MOVE Left or Right
	XPos += XVelocity;
	//Check if in end of form
	if (XPos < 0 || (XPos + 18) > SCREEN_WIDTH )
		XPos -= XVelocity;
	for (int a = 0; a < ArraySize; a++)
	{
		if (CollisionDetection(Wall[a]))
			XPos -= XVelocity;
	}
	std::cout << "XPOS = " << XPos << std::endl;

	//MOVE Up or Down
	YPos += YVelocity;
	//Check
	if (YPos < 0 || (YPos + 28) > SCREEN_HEIGHT)
		YPos -= YVelocity;
	for (int a = 0; a < ArraySize; a++)
	{
		if (CollisionDetection(Wall[a]))
			YPos -= YVelocity;
	}
	std::cout << "YPOS = " << YPos << std::endl;
	//Render the charcter
	if (XVelocity == 2 || XVelocity == -2 || YVelocity == 2 || YVelocity == -2)
	Frame++;
}

bool Charcter::CollisionDetection(SDL_Rect Wall)
{
	if (XPos + 16 <= Wall.x)
		return false;
	if (XPos >= (Wall.x + Wall.w))
		return false;
	if (YPos + 29 <= Wall.y)
		return false;
	if (YPos + 29 >= (Wall.y + Wall.h))
		return false;

	return true;
}
