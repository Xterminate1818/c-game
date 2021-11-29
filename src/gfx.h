#pragma once
#include "../include/SDL.h"

// Constants
const int WIN_WIDTH;
const int WIN_HEIGHT;
const int WIN_FLAGS;

struct {
    SDL_Window* win;
    SDL_Surface* screen;
} App; 


void aWipe();

int aBlitSurface(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Rect* dstrect);

void aUpdate();


