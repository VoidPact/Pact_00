#include "input.h"


std::vector<SDL_Keycode> modifiers; //This holds all currently pressed modifier keys.
std::vector<SDL_Keycode> keys; // This holds all currently pressed non-modifier keys.

//Returns currently pressed keys and currently pressed modifier keys in two vectors.
//index 0: non-modifier keys currently pressed.
//index 1: modifier keys currently pressed.
vector<vector<SDL_Keycode>> updateInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{

		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_LSHIFT:
				// Checks if element is already in vector.
				if (std::find(modifiers.begin(), modifiers.end(), SDLK_LSHIFT) == modifiers.end())
				{
					modifiers.push_back(event.key.keysym.sym);

					// Print out modifiers.
					std::cout << "Printing out modifier vector after add:" << std::endl;
					for (auto i = modifiers.begin(); i != modifiers.end(); ++i)
						std::cout << *i << ' ';
					std::cout << std::endl;
				}
				break;
			default:
				// non-modifier is pressed. Checks if element is already in vector.
				if (std::find(keys.begin(), keys.end(), event.key.keysym.sym) == keys.end())
				{
					keys.push_back(event.key.keysym.sym);

					// Print out key vector.
					std::cout << "Printing out key vector after add:" << std::endl;
					for (auto i = keys.begin(); i != keys.end(); ++i)
						std::cout << *i << ' ';
					std::cout << std::endl;
				}
				break;
			}
		}

		// Removes modifiers from list
		if (event.type == SDL_KEYUP)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_LSHIFT:
				// Remove moves elements in specified range that also satisfies value, out of that range
				// also return the elements new index
				// erase then deletes elements from this index 
				// idk how it works #stackoverflow 
				modifiers.erase(std::remove(modifiers.begin(), modifiers.end(), SDLK_LSHIFT), modifiers.end());

				// Print out modifiers vector.
				std::cout << "Printing out modifier vector after remove:" << std::endl;
				for (auto i = modifiers.begin(); i != modifiers.end(); ++i)
					std::cout << *i << ' ';
				std::cout << std::endl;

				break;
			default:
				// non-modifier key is released.
				keys.erase(std::remove(keys.begin(), keys.end(), event.key.keysym.sym), keys.end());

				// Print out key vector.
				std::cout << "Printing out key vector after remove:" << std::endl;
				for (auto i = keys.begin(); i != keys.end(); ++i)
					std::cout << *i << ' ';
				std::cout << std::endl;

				break;
			}
		}
	}

	return vector<vector<SDL_Keycode>>{keys, modifiers};
}
