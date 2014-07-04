// SecondGame(Rewrite).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include "Charcter.h"
#include "Map.h"
#include "Text.h"
#include "Timer.h"
using namespace std;


int main(int argc, char* argv[])
{
	//Middle function between Map and Charcter to handle the colision
	SDL_Rect MiddleFunction[100];
	SDL_Color TextColour = { 255, 0, 0, 0 };
	Game game;
	Charcter charcter;
	Map map;
	Text text;
	Timer timer;
	//For collision
	int ArraySize = 7;
	//for loop collision in drawobject DO NOT REMOVE IF YOU Don't want to make shit at Charcter.cpp just make MiddleFunction[ar + 1] or ar + 2 etc...
	int ar = 0;
	bool quit = false, Fps = false;
	if (!game.Game_Init())
	{
		cerr << "Could not init Game!" << endl;
	}
	else
	{
		Global_Data_LoadMedia::Global_Render = game.MainRender;
		charcter.PushCharcter("SpriteSheetMain.png");
		timer.Init("lazy.ttf", 20);
		text.LoadFont("lazy.ttf", 50);
		text.LoadText("Second Game!", TextColour);
		text.LoadText("Hello twitter!", TextColour);
		map.PushObject("Tileset.png");
		
	
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
						if (game.event.type == SDL_KEYDOWN && game.event.key.repeat == 0)
						{
							switch (game.event.key.keysym.sym)
							{
							case SDLK_F4:
								if (Fps == true)
								{
									Fps = false;
								}
								else
								{
									Fps = true;
								}
							}
						}
						charcter.HandleEvent(game.event);
					}
				}

				SDL_SetRenderDrawColor(Global_Data_LoadMedia::Global_Render, 255, 255, 255, 255);
				SDL_RenderClear(Global_Data_LoadMedia::Global_Render);

		
				map.MakeGrass();
				text.ShowText(game.SCREEN_WIDTH / 3, game.SCREEN_HEIGHT / 2, 0);
				text.ShowText(game.SCREEN_WIDTH - text.font_Width(1),0, 1);

					for (ar = 0; ar < ArraySize; ar++)
					{
						MiddleFunction[ar] = map.DrawObject(ar * 100, ar * 50, Map::Chair);
					}
				
				if (Fps == true)
				{
					timer.ShowFps();
				}
				
				MiddleFunction[ar] = map.DrawObject(game.SCREEN_WIDTH - 200, 50, Map::Chair);
				charcter.Move(MiddleFunction,ArraySize + 1);
			charcter.RenderCharcter();
			SDL_RenderPresent(Global_Data_LoadMedia::Global_Render);
		}
	}
	

	return game.Game_Quit();
}

