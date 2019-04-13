#pragma once

void initSDL(SDL_Window**window, VIEW*view, SDL_Renderer**renderer);
void colour(float hue, Uint8* const red, Uint8* const green, Uint8* const blue);
void draw_mandelbort(VIEW* view, SDL_Renderer**renderer);
void destroy_all(SDL_Renderer**renderer, SDL_Window**window);
