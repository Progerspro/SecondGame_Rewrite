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
					//Fix the key repeat, one key just working!
					charcter.HandleEvent(game.event);
				}
			}
		
			SDL_RenderClear(Global_Data_LoadMedia::Global_Render);
				map.DrawMap();
			
			
			charcter.Move();//FIX
			charcter.RenderCharcter();
			SDL_RenderPresent(Global_Data_LoadMedia::Global_Render);
		}
	}
	return game.Game_Quit();	
}

