// SecondGame(Rewrite).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include "Charcter.h"

using namespace std;
int main(int argc, char* argv[])
{
	Game game;
	Charcter charcter;
	bool quit = false;
	int x = 0;
	if (!game.Game_Init())
	{
		cerr << "Could not init Game!" << endl;
	}
	else
	{
		charcter.PushCharcter("SpriteSheetMain.png");
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
			SDL_SetRenderDrawColor(game.MainRender, 255, 255, 255, 255);
			SDL_RenderClear(game.MainRender);
			charcter.DrawCharcter();
			SDL_RenderPresent(game.MainRender);
		}
	}
	return 0;
}

