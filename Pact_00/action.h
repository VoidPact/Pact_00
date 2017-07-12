#pragma once
#include <vector>
#include <SDL2\SDL.h>
#include <algorithm>

using namespace std;

class Action 
{
private:
	// Fields. 	
	vector<vector<SDL_Keycode>> triggerChords; // These are the key combinations that triggers the action.
	

public:
	// Constructors.
	Action(void(*effect)());

	// Functions. 
	void addTriggerChord(vector<SDL_Keycode> keyChords);
	bool isTriggered(vector<SDL_Keycode> keyChords);
	void(*effect)();

};




