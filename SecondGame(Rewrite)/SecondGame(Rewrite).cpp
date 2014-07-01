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
	int x = 0;
	if (!game.Game_Init())
	{
		cerr << "Could not init Game!" << endl;
	}
	else
	{
		Global_Data_LoadMedia::Global_Render = game.MainRender;
		charcter.PushCharcter("SpriteSheetMain.png");
		charcter.PushCharcter("Charcter.png");
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
					switch (game.event.key.keysym.sym)
					{
					case SDLK_LEFT:
						x -= 5;
						cout << "x = " << x << endl;
						break;
					case SDLK_RIGHT:
						x += 5;
						cout << "x = " << x << endl;
						break;
					}
				}
			}
			SDL_RenderClear(Global_Data_LoadMedia::Global_Render);
			map.DrawMap();
			charcter.DrawCharcter(x);
			SDL_RenderPresent(Global_Data_LoadMedia::Global_Render);
		}
	}
	return game.Game_Quit();	
}

