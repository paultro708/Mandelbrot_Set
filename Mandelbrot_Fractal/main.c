#include <SDL.h>
#include <stdio.h>
#include "main.h"
#include "def.h"
#include "fractal.h"



int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Could not initialize SDL! \n");
		SDL_Quit();
		return 1;
	}
	//instruction
	printf("Use keys on the keyboard: \n-arrows to move the image\n");
	printf("-Tab to cental zoom in \n-Left Shift to central zoom back\n");
	printf("Press Esc to exit the program\n");
	printf("Enjoy the view of Mandelbrot Set!\n");

	SDL_Window* window;
	VIEW view;
	SDL_Renderer* renderer;
	initSDL(&window, &view, &renderer); //initialize all
	draw_mandelbort(&view, &renderer);

	SDL_Event event;
	SDL_PollEvent(&event);

	user_inter(event,&view, &renderer, &window);
	destroy_all(&renderer, &window);

	return 0;
}