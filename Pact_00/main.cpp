#include <iostream> // input output, has all sorts of shit - Emil, also has strings.
#include "window.h"
#include "input.h"
#include "action.h"

#undef main

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 900;
const char* WINDOW_TITLE = "Pact_00";


int main()
{
	SDL_Window* window;
	initWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, window);

	//Makes screen blue when press w :).
	Action blueBalls([]() {glClearColor(0.0, 0.0, 0.5, 0.0); });
	blueBalls.addTrigger(std::vector<SDL_Keycode>{SDLK_w});
	blueBalls.addTrigger(std::vector<SDL_Keycode>{SDLK_LSHIFT, SDLK_SPACE});

	//Makes screen red when press a :).
	Action redBalls([]() {glClearColor(0.5, 0.0, 0.0, 0.0); });
	redBalls.addTrigger(std::vector<SDL_Keycode>{SDLK_a});

	//Makes screen green when press d :).
	Action greenBalls([]() {glClearColor(0.0, 0.5, 0.0, 0.0); });
	greenBalls.addTrigger(std::vector<SDL_Keycode>{SDLK_d});

	vector<Action> actions { blueBalls, redBalls, greenBalls }; // det her kan man goere i ny C++!
																// jeg har slaaet det op saa dont be sur

	bool running = true;
	while (running) 
	{
		//handleInput(running);
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				SDL_Keycode keyPressed = event.key.keysym.sym;
				for (int i = 0; i < actions.size(); i++)
				{
					if (actions[i].isTriggered(std::vector<SDL_Keycode>{keyPressed})) // >:(
						actions[i].effect(); // >:O
				}


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






















