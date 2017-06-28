#include <iostream> // input output, has all sorts of shit - Emil, also has strings.
#include "window.h"
#include "input.h"

#undef main

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 900;
const char* WINDOW_TITLE = "Pact_00";

int main() 
{
	SDL_Window* window;
	initWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, window);

	bool running = true;
	while (running) 
	{
		handleInput(running);

		double currentTime = SDL_GetTicks() / 1000.0;
		double sinTime = sin(currentTime);

		glClearColor(0.0, 0.0, sinTime, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(window);
	}

	cleanupWindow;
	return 0;
}






















