#include <iostream> // input output, has all sorts of shit - Emil, also has strings.
#include "window.h"
#include "input.h"
#include "action.h"
#include <algorithm>

#undef main

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 900;
const char* WINDOW_TITLE = "Pact_00";


int main()
{
	SDL_Window* window;
	initWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, window);

	//Makes screen blue when press w :).
	Action blueBalls([]() 
	{
		glClearColor(0.0, 0.0, 0.5, 0.0); 
		std::cout << "BLUE MAN" << std::endl;
	});
	blueBalls.addTriggerChord(std::vector<SDL_Keycode>{SDLK_w});

	//Makes screen red when press a :).
	Action redBalls([]() 
	{
		glClearColor(0.5, 0.0, 0.0, 0.0);
		std::cout << "RED MAN" << std::endl;
	});
	redBalls.addTriggerChord(std::vector<SDL_Keycode>{SDLK_a});

	//Makes screen green when press d :).
	Action greenBalls([]() 
	{
		glClearColor(0.0, 0.5, 0.0, 0.0); 
		std::cout << "GREEN MAN" << std::endl;
	});
	greenBalls.addTriggerChord(std::vector<SDL_Keycode>{SDLK_d});

	//Makes screen yellow when press shift+s :).
	Action yellowBalls([]() {glClearColor(0.5, 0.5, 0.0, 0.0); });
	yellowBalls.addTriggerChord(std::vector<SDL_Keycode>{SDLK_s, SDLK_LSHIFT});


	vector<Action> actions { blueBalls, redBalls, greenBalls, yellowBalls }; // det her kan man goere i ny C++!
	
	vector<vector<SDL_Keycode>> input;						                 //index 0: non-modifier keys currently pressed.
																			 //index 1: modifier keys currently pressed.

	// Game loop
	bool running = true;
	while (running) 
	{
		//MAASKE KAN MAN BARE BRUGE DEM DER LIGGER I INPUT.CPP??????
		input = updateInput();
		
		// Checks action triggers. 
		for (int j = 0; j < input[0].size(); j++)
		{
			std::cout << "j = " << j  << std::endl;
			vector<SDL_Keycode> keyChord = std::vector<SDL_Keycode>{ input[0][j] };
			keyChord.insert(keyChord.end(), input[1].begin(), input[1].end());

			// Print out keyChord.
			std::cout << "Printing out keyChord vector:" << std::endl;
			for (auto i = keyChord.begin(); i != keyChord.end(); ++i)
				std::cout << *i << ' ';
			std::cout << std::endl;

			for (int i = 0; i < actions.size(); i++)
			{
				if (actions[i].isTriggered(keyChord)) // >:(
					actions[i].effect(); // >:O
			}

		}

		glClear(GL_COLOR_BUFFER_BIT);

		//double currentTime = SDL_GetTicks() / 1000.0;
		//double sinTime = sin(currentTime);

		//glClearColor(0.0, 0.0, sinTime, 0.0);
		//glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(window);
	}

	cleanupWindow;
	return 0;
}






















