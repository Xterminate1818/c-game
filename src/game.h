#pragma once
#include "gfx.h"

SDL_Event gEvent;

// Flags
int QUIT;
int PAUSE;

// Graphics

// Game functions

void pollInput();

void doGameInit();

void doGameLogic();

void doGameDraw();

void doGameLoop(); 
