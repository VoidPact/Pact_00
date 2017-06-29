#pragma once
#include <vector>
#include <SDL2\SDL.h>

using namespace std;

class Action 
{
private:
	// Fields. 	
	vector<vector<SDL_Keycode>> triggers; // These are the key combinations that triggers the action.
	

public:
	// Constructors.
	Action(void(*effect)());

	// Functions. 
	void addTrigger(vector<SDL_Keycode> keyCombination);
	bool isTriggered(vector<SDL_Keycode> keyCombination);
	void(*effect)();

};




