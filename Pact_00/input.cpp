#include "input.h"

//Returns currently pressed keys and currently pressed modifier keys in two vectors.
//index 0: non-modifier keys currently pressed.
//index 1: modifier keys currently pressed.
void updateInput(vector<SDL_Keycode>* keysPressed)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		// Adds keys to vectors when keys are pressed :) 
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_LSHIFT:
				// Checks if element is already in vector.
				if (std::find(keysPressed[1].begin(), keysPressed[1].end(), SDLK_LSHIFT) == keysPressed[1].end())
				{
					keysPressed[1].push_back(event.key.keysym.sym);

					// Print out modifiers.
					std::cout << "input::updateInput -> Printing out modifier vector after add:" << std::endl;
					for (auto i = keysPressed[1].begin(); i != keysPressed[1].end(); ++i)
						std::cout << *i << ' ';
					std::cout << std::endl;
				}
				break;
			default:
				// non-modifier is pressed. Checks if element is already in vector.
				if (std::find(keysPressed[0].begin(), keysPressed[0].end(), event.key.keysym.sym) == keysPressed[0].end())
				{
					keysPressed[0].push_back(event.key.keysym.sym);

					// Print out key vector.
					std::cout << "input::updateInput -> Printing out key vector after add:" << std::endl;
					for (auto i = keysPressed[0].begin(); i != keysPressed[0].end(); ++i)
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
				keysPressed[1].erase(std::remove(keysPressed[1].begin(), keysPressed[1].end(), SDLK_LSHIFT), keysPressed[1].end());

				// Print out modifiers vector.
				std::cout << "input::updateInput -> Printing out modifier vector after remove:" << std::endl;
				for (auto i = keysPressed[1].begin(); i != keysPressed[1].end(); ++i)
					std::cout << *i << ' ';
				std::cout << std::endl;
				
				break;
			default:
				// non-modifier key is released.
				keysPressed[0].erase(std::remove(keysPressed[0].begin(), keysPressed[0].end(), event.key.keysym.sym), keysPressed[0].end());

				// Print out key vector.
				std::cout << "input::updateInput -> Printing out key vector after remove:" << std::endl;
				for (auto i = keysPressed[0].begin(); i != keysPressed[0].end(); ++i)
					std::cout << *i << ' ';
				std::cout << std::endl;

				break;
			}
		}
	}
}

void processInput(vector<SDL_Keycode>* input, vector<Action> actions)
{
	// Checks action triggers. 
	for (int j = 0; j < input[0].size(); j++)
	{
		std::cout << "input::processInput -> iteration of input[0] runthrough: " << j << std::endl;
		vector<SDL_Keycode> keyChord = std::vector<SDL_Keycode>{ input[0][j] };
		keyChord.insert(keyChord.end(), input[1].begin(), input[1].end());

		// Print out keyChord.
		std::cout << "input::processInput -> Printing out keyChord vector:" << std::endl;
		for (auto i = keyChord.begin(); i != keyChord.end(); ++i)
			std::cout << *i << ' ';
		std::cout << std::endl;

		for (int i = 0; i < actions.size(); i++)
		{
			if (actions[i].isTriggered(keyChord)) // >:(
				actions[i].effect(); // >:O
		}

	}

}