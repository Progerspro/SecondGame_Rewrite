// SecondGame(Rewrite).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include "Charcter.h"
#include "Map.h"
using namespace std;
int main(int argc, char* argv[])
{
	Game game;
	Charcter charcter;
	Map map;
	bool quit = false;
	int x = game.SCREEN_WIDTH / 2,y = game.SCREEN_HEIGHT / 2;
	int Move = 0;
	int Status = 0;
	int Frame = 0;
	if (!game.Game_Init())
	{
		cerr << "Could not init Game!" << endl;
	}
	else
	{
		Global_Data_LoadMedia::Global_Render = game.MainRender;
		charcter.PushCharcter("SpriteSheetMain.png");
		map.PushMap("Tileset.png");
		SDL_SetRenderDrawColor(Global_Data_LoadMedia::Global_Render, 255, 255, 255, 255);
		while (!quit)
		{
			while (SDL_PollEvent(&game.event) != 0)
			{
				if (game.event.type == SDL_QUIT)
				{
					quit = true;
				}
				else
				{
					//TODO:Handle Key Presses!
					switch (game.event.key.keysym.sym)
					{
					case SDLK_LEFT:
						if (x <= 0)
						{
							break;
						}
						x -= 5;
						Status = 2;
						Frame++;
						cout << "x = " << x << endl;
						break;
					case SDLK_RIGHT:
						if (x >= game.SCREEN_WIDTH - 18 )
						{
							break;
						}
						x += 5;
						Status = 0;
						Frame++;
						cout << "x = " << x << endl;
						break;
					case SDLK_DOWN:
						if (y + 10 >= game.SCREEN_HEIGHT)
						{
							break;
						}
						y += 5;
						Status = 3;
						Frame++;
						cout << "y = " << y << endl;
						break;
					case SDLK_UP:
						if (y <= 0) 
						{
							break;
						}
						y -= 5;
						Status = 1;
						Frame++;
						cout << "y = " << y << endl;
						break;
					}
				}
			}
		
			SDL_RenderClear(Global_Data_LoadMedia::Global_Render);
				map.DrawMap(x);
			
			if (Frame / 2 == 3)
			{
				Frame = 0;
			}
		
			charcter.DrawCharcter(x, y, Status, Frame / 2);
			SDL_RenderPresent(Global_Data_LoadMedia::Global_Render);
		}
	}
	return game.Game_Quit();	
}

