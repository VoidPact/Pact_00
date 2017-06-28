#include <iostream> // input output, has all sorts of shit - Emil, also has strings.
#include <SDL2\SDL.h>  
#include <glad\glad.h> 

#undef main

bool initWindow(int width, int height, const char* title)
{
	// Initialize SDL's video subsystem. Whatever that is.
	if (SDL_INIT_VIDEO < 0) 
	{
		std::cout << "Failed to init SDL\n";
		return false;
	}

	// Create window centered at the screen with function argument resolution and title.
	SDL_Window* mainWindow = SDL_CreateWindow(
			title,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width,
			height,
			SDL_WINDOW_OPENGL);

	if (!mainWindow)
	{
		std::cout << "Could not create window" << std::endl;
		return false;
	}

	// Create openGL context and attach it to mainWindow
	SDL_GLContext mainContext = SDL_GL_CreateContext(mainWindow);

	// Tell SDL that we use the OpenGL Core profile.
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// Tell SDL which version of OpenGL we want to use. 
	// We use 3.3 so it can run on older graphics cards. 
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	
	// Tell SDL to use double buffering. This prevents screen tearing.
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Synchs swap with monitor refresh rate
	SDL_GL_SetSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		std::cout << "Could not initialize GLAD" << std::endl;
		return false;
	}
	
	std::cout << "Initialized openGL window successfully!" << std::endl;
	return true;
}

const int WINDOW_WIDTH = 512;
const int WINDOW_HEIGHT = 512;
const char* WINDOW_TITLE = "Pact_00";

int main() {
	initWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	std::cout << "The MEme Machine" << std::endl;

	while (true) {
		
	}
	return 0;
}






















