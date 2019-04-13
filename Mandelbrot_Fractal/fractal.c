#include "def.h"
#include <stdio.h>
#include <SDL.h>


// Destroy SDL structures
void destroy_all(SDL_Renderer**renderer, SDL_Window**window)
{

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	renderer = NULL;
	window = NULL;
	SDL_Quit();
}

//Create window, renderer and initialize view
void initSDL(SDL_Window**window, VIEW*view, SDL_Renderer**renderer)
{
	*window = SDL_CreateWindow( //initialize window
		TITLE, //Mandelbrot Set
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WIDTH,
		HEIGHT,
		SDL_WINDOW_SHOWN);
	if (*window == NULL)  //error
	{
		printf("Could not create window to resolution %dx%d\n", WIDTH, HEIGHT);
		SDL_Quit();
		exit(1);
	}

	//Initalize view
	view->x_move = 0; 
	view->y_move = 0;
	view->zoom = 0.3;  //it's too big for 600x600 for 1.0
	view->fractalMaxI = MAX_ITER;

	//Initialize renderer
	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_SOFTWARE);
	if (*renderer == NULL) //error
	{
		printf("Could not create renderer! \n");
		SDL_Quit();
		exit(1);
	}
}

//determing of colour 
void colour(float hue, Uint8* red, Uint8* green, Uint8* blue) {

	hue *= 0.1;   //it's easier to change colour than operating on number of iterations

	if (hue < 2) {
		*blue = 0;
		if (hue < 1) { //the most distant points from Mandelbrot Set
			*red = 255;
			*green = hue * 255;
		}
		else {
			*green = 255;
			*red = (2 - hue) * 255;
		}
	}
	else if (hue < 4) {
		*red = 0;
		if (hue < 3) {
			*green = 255;
			*blue = (hue - 2) * 255;
		}
		else {
			*blue = 255;
			*green = (4 - hue) * 255;
		}
	}
	else {
		*green = 0;
		if (hue < 5) {
			*blue = 255;
			*red = (hue - 4) * 255;
		}
		else {	//the highest number of iterations
			*red = 255;
			*blue = (6 - hue) * 255; 
		}
	}
}


void draw_mandelbort(VIEW* view, SDL_Renderer**renderer)
{
	float X = WIDTH;		    //of picture
	float Y = HEIGHT;			//of picture


	cmplx c;					//for formula Z(n+1)=Z(n)^2 + C  from wikipedia
	float x = 0;			    //coordinate of point (Re)
	float y = 0;			    //coordinate of point (Im)
	Uint8 red, green, blue;		//colours (flags)


	//for every point
	for (x = 0; x < X; x++) {
		c.r = ((x - X / 2) / (0.5 * X*view->zoom)) - view->x_move;
		for (y = 0; y < Y; y++) {
			c.i = ((y - Y / 2) / (0.5* Y* view->zoom)) - view->y_move;

			int i = levelSet(c);   //numbers of iterations

			if (i >= MAX_ITER)   // is in the set
			{
				SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 0); //black
				SDL_RenderDrawPoint(*renderer, x, y);
			}
			else {

				colour(i, &red, &green, &blue); //depending on numbers of iterations
				SDL_SetRenderDrawColor(*renderer, red, green, blue, 0);
				SDL_RenderDrawPoint(*renderer, x, y);
				//SDL_SetRenderDrawColor(*renderer, 0, 0, i*255/MAX_ITER, 0); //blue
				//SDL_RenderDrawPoint(*renderer, x, y);
			}
		}
	}
	SDL_RenderPresent(*renderer);
	SDL_Delay(10);
}
