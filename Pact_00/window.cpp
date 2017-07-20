#include "window.h"

bool Window::init()
{
	// Initialize SDL's video subsystem. Whatever that is.
	if (SDL_INIT_VIDEO < 0)
	{
		std::cout << "Failed to init SDL\n";
		return false;
	}

	// Create window centered at the screen with function argument resolution and title.
	glWindow = SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_OPENGL);

	if (!glWindow)
	{
		std::cout << "Could not create window" << std::endl;
		return false;
	}

	// Create openGL context and attach it to mainWindow
	SDL_GLContext glContext = SDL_GL_CreateContext(glWindow);

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

void Window::destroy()
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(glWindow);
	SDL_Quit();
}

Window::Window(int width, int height, const char* title)
{
	this->height = height;
	this->width = width;
	this->title = title;

	this->init();
}

Window::~Window()
{
	this->destroy();
}

void Window::clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::refresh()
{
	SDL_GL_SwapWindow(glWindow);
}
