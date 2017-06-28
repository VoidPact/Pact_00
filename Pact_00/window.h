#pragma once

#include <iostream>
#include <SDL2\SDL.h>
#include <glad\glad.h>

bool initWindow(int width, int height, const char* title, SDL_Window* &window);
