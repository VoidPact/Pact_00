#pragma once

#include <iostream>
#include <SDL2\SDL.h>
#include <vector>
#include <algorithm>
#include "Action.h"

using namespace std;

void updateInput(vector<SDL_Keycode>* keysPressed);

void processInput(vector<SDL_Keycode>* input, vector<Action> actions);
