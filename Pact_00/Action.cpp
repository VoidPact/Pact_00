#include "action.h"


Action::Action(void(*effect)())
{
	this->effect = effect;
}

void Action::addTriggerChord(vector<SDL_Keycode> keyChord)
{
	this->triggerChords.push_back(keyChord);
}

bool Action::isTriggered(vector<SDL_Keycode> keyChord)
{
	for (int i = 0; i < triggerChords.size(); i++)
	{
		// Optimized search by sorting out chords of wrong size to the input.
		if (triggerChords[i].size() == keyChord.size()) 
		{
			// Sorts the two fuckers.
			sort(&triggerChords[i].front(), &triggerChords[i].back()); //I have no idea why but '&' before makes it work.
			sort(&keyChord.front(), &keyChord.back());

			// Returns true if the two bastards are equal.
			if (triggerChords[i] == keyChord)
			{
				return true;
			}
		}

	}

	return false;
}

