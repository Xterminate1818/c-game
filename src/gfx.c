#include "gfx.h"

const int WIN_WIDTH = 500;
const int WIN_HEIGHT = 500;
const int WIN_FLAGS = SDL_WINDOW_SHOWN;

void aWipe() {
    SDL_FillRect(
        App.screen, NULL, SDL_MapRGB(App.screen->format, 0x00, 0x00, 0x00)
    );
}

int aBlitSurface(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Rect* dstrect) {
    return SDL_BlitSurface(src, srcrect, App.screen, dstrect);
}

void aUpdate() {
    SDL_UpdateWindowSurface(App.win);
}

