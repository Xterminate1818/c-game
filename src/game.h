#pragma once
#include "gfx.h"

SDL_Event gEvent;

// Flags
int g_quit;
int g_pause;

// Game functions

void pollInput();

void doGameInit();

void doGameLogic();

void doGameDraw();

void doGameLoop(); 
