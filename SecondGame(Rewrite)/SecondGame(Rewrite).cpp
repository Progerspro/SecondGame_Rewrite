// SecondGame(Rewrite).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include "Charcter.h"
#include "Map.h"
#include "Text.h"
using namespace std;
int main(int argc, char* argv[])
{
	SDL_Color TextColour = { 255, 0, 0, 0 };
	Game game;
	Charcter charcter;
	Map map;
	Text text;
	bool quit = false;
	if (!game.Game_Init())
	{
		cerr << "Could not init Game!" << endl;
	}
	else
	{
		Global_Data_LoadMedia::Global_Render = game.MainRender;
		charcter.PushCharcter("SpriteSheetMain.png");
		text.LoadFont("lazy.ttf", 50);
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
					charcter.HandleEvent(game.event);
				}
			}
		
			SDL_RenderClear(Global_Data_LoadMedia::Global_Render);
			
				map.DrawMap();
				text.ShowText("Second Game!", TextColour, game.SCREEN_WIDTH / 3, game.SCREEN_HEIGHT / 2);
			
				charcter.Move();
			charcter.RenderCharcter();
			SDL_RenderPresent(Global_Data_LoadMedia::Global_Render);
		}
	}
	return game.Game_Quit();	
}

