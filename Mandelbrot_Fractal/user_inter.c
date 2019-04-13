#include <SDL.h>
#include <stdio.h>
#include "def.h"
#include "user_inter.h"




void user_inter(SDL_Event event, VIEW*view, SDL_Renderer**renderer, SDL_Window**window) {
	while (SDL_WaitEvent(&event)) { //
		do {
			if (event.type == SDL_QUIT)
			{
				destroy_all(renderer, window);
				return 0;
			}
			else if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {

				case SDLK_UP: { //move up
					view->y_move = view->y_move + (MOVE_CHANGEMENT / view->zoom);
					draw_mandelbort(view, renderer); //update
				}
				break;

				case SDLK_DOWN: { //move down
					view->y_move = view->y_move - (MOVE_CHANGEMENT / view->zoom);
					draw_mandelbort(view, renderer);
				}
				break;

				case SDLK_LEFT: { //move left
					view->x_move = view->x_move + (MOVE_CHANGEMENT / view->zoom);
					draw_mandelbort(view, renderer);

				}
				break;

				case SDLK_RIGHT: { //move right
					view->x_move = view->x_move - (MOVE_CHANGEMENT / view->zoom);
					draw_mandelbort(view, renderer);
				}
				break;

				case SDLK_TAB: { //ZOOM IN
					view->zoom = view->zoom + (MOVE_CHANGEMENT * view->zoom);
					view->fractalMaxI = view->fractalMaxI + ZOOM_CHANGEMENT;

					draw_mandelbort(view, renderer);
				}
				break;

				case SDLK_LSHIFT: {//ZOOM BACK
					if ((view->zoom - (MOVE_CHANGEMENT * view->zoom)) > 0.3)
						//not to allow user to zoom back more than at the begin
					{
						view->zoom = view->zoom - (MOVE_CHANGEMENT * view->zoom);
						view->fractalMaxI = view->fractalMaxI - ZOOM_CHANGEMENT;
						draw_mandelbort(view, renderer);
					}
				}
				break;

				case SDLK_ESCAPE: {//exit

					destroy_all(renderer, window);
					return 0;
				}
				break;
				default:
				break;
				}
			}
		} while (SDL_PollEvent(&event));
	}
}
