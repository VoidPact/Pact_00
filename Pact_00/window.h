#pragma once

#include <iostream>
#include <SDL2\SDL.h>
#include "glad\glad.h"

class Window
{
public:
	// Constructors.
	Window(int width, int height, const char* title);

	// Destructors.
	~Window();

	// Functions. 
	void clear();

private:
	// Fields.
	int height;
	int width;
	const char* title;
	SDL_Window* glWindow;
	SDL_GLContext glContext;

	// Functions.
	bool init();
	void destroy();

};



