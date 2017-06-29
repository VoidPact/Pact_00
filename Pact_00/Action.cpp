#include "action.h"


Action::Action(void(*effect)())
{
	this->effect = effect;
}

void Action::addTrigger(vector<SDL_Keycode> keyCombination)
{
	this->triggers.push_back(keyCombination);
}

// OMG DOESNT WORK FOR DIFFERENT SEQUENCES OMG JENS YOU USED 10 MINUTES ON THIS AND IT DOENST EVEN WOKR PRPERP
bool Action::isTriggered(vector<SDL_Keycode> keyCombination)
{
	for (int i = 0; i < triggers.size(); i++)
	{
		bool same = true;

		for (int j = 0; j < triggers[i].size(); j++)
		{
			if (!(keyCombination[j] == triggers[i][j])) 
				same = false;

		}

		if (same) return true;
	}

	return false;
}

