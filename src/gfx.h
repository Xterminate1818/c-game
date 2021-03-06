#pragma once
#include <math.h>
#include <stdio.h>
#include "../include/SDL.h"

// Constants
const int WIN_WIDTH;
const int WIN_HEIGHT;
const int WIN_FLAGS;

struct {
    SDL_Window* win;
    SDL_Surface* screen;
} App; 

typedef struct {
    float x; float y;
} vec2;

float magnitude(vec2 v);
float imagnitude(vec2 v);
vec2 normalized(vec2 v);

void gWipe();

int gBlitSurface(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Rect* dstrect);

void gUpdate();

SDL_Surface* gLoad(char* path);

