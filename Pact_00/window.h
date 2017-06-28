#pragma once

#include <iostream>
#include <SDL2\SDL.h>
#include "glad\glad.h"

bool initWindow(int width, int height, const char* title, SDL_Window* &window);

void cleanupWindow(SDL_Window* &window, SDL_GLContext &context);