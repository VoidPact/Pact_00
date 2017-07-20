#include <iostream> // input output, has all sorts of shit - Emil, also has strings.

#include "Action.h" // Classes.
#include "Window.h"
#include "shader\Shader.h"

#include "input.h" // Memes.
#include "render.h"



#undef main // For some reason this needs to be done for SDL to work.

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 900;
const char* WINDOW_TITLE = "Pact_00";

int main()
{
	Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	
	// TESTING
	//Makes screen blue when press w :).
	Action blueBalls([]() 
	{
		glClearColor(0.0, 0.0, 0.5, 0.0); 
		std::cout << "BLUE MAN" << std::endl;
	});
	blueBalls.addTriggerChord(std::vector<SDL_Keycode>{SDLK_w});

	//Makes screen red when press a :).
	Action redBalls([]() 
	{
		glClearColor(0.5, 0.0, 0.0, 0.0);
		std::cout << "RED MAN" << std::endl;
	});
	redBalls.addTriggerChord(std::vector<SDL_Keycode>{SDLK_a});

	//Makes screen green when press d :).
	Action greenBalls([]() 
	{
		glClearColor(0.0, 0.5, 0.0, 0.0); 
		std::cout << "GREEN MAN" << std::endl;
	});
	greenBalls.addTriggerChord(std::vector<SDL_Keycode>{SDLK_d});

	//Makes screen yellow when press shift+s :).
	Action yellowBalls([]() {glClearColor(0.5, 0.5, 0.0, 0.0); });
	yellowBalls.addTriggerChord(std::vector<SDL_Keycode>{SDLK_s, SDLK_LSHIFT});

	// TESTING END

	vector<Action> actions { blueBalls, redBalls, greenBalls, yellowBalls }; // det her kan man goere i ny C++!

	//Array consisting of all pressed keys. 
    //index 0: non-modifier keys currently pressed.
    //index 1: modifier keys currently pressed.
	vector<SDL_Keycode> input[2];
				
	//Fokken shaders
	Shader shaderProgram("shader/default.vs", "shader/default.frag");

	initRenderData();

	// Game loop.
	bool running = true;
	while (running) 
	{
		updateInput(input);
		processInput(input, actions);
		
		shaderProgram.Use();
		square();

		window.clear();
	}

	return 0;
}
























