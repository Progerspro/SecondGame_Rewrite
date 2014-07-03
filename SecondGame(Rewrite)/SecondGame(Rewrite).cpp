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
	SDL_Color TextColour = { 255, 0, 0, 0 };
	Game game;
	Charcter charcter;
	Map map;
	Text text;
	Timer timer;
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
			
			SDL_RenderClear(Global_Data_LoadMedia::Global_Render);
				map.MakeGrass();
				map.Draw(14, 56, Map::Chair);
				map.Draw(90, 56, Map::Chair);
				map.Draw(333, 555, Map::Chair);
				if (Fps == true)
				{
					timer.ShowFps();
				}
				text.ShowText(game.SCREEN_WIDTH / 3, game.SCREEN_HEIGHT / 2,0);
			
				charcter.Move();
			charcter.RenderCharcter();
			SDL_RenderPresent(Global_Data_LoadMedia::Global_Render);
		}
	}
	

	return game.Game_Quit();
}

