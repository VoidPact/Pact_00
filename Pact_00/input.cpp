#include "input.h"

void handleInput(bool &loopCondition)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{

		if (event.type == SDL_QUIT)
		{
			loopCondition = false;
		}

		if (event.type == SDL_KEYDOWN)
		{
			std::cout << event.key.keysym.sym << std::endl;

			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				loopCondition = false;
				break;

			default:
				break;
			}
		}

	}
}