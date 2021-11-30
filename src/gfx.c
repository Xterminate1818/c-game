#include "gfx.h"

const int WIN_WIDTH = 500;
const int WIN_HEIGHT = 500;
const int WIN_FLAGS = SDL_WINDOW_SHOWN;

float magnitude(vec2 v) {
    float ret = v.x + v.y;
    ret *= ret;
    return sqrt(ret);
}

float imagnitude(vec2 v) {
    float ret = magnitude(v);
    if (ret == 0) return ret;
    return 1.f / ret;
}

vec2 normalized(vec2 v) {
    float imag = imagnitude(v);
    v.x *= imag;
    v.y *= imag;
    return v;
}

void gWipe() {
    SDL_FillRect(
        App.screen, NULL, SDL_MapRGB(App.screen->format, 0x00, 0x00, 0x00)
    );
}

int gBlitSurface(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Rect* dstrect) {
    return SDL_BlitSurface(src, srcrect, App.screen, dstrect);
}

void gUpdate() {
    SDL_UpdateWindowSurface(App.win);
}

SDL_Surface* gLoad(char* path) {
    SDL_Surface* optimizedSurface = NULL;
    SDL_Surface* loadedSurface = SDL_LoadBMP(path);
    if(loadedSurface == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
	}
    optimizedSurface = SDL_ConvertSurface(loadedSurface, App.screen->format, 0);
    if(optimizedSurface == NULL) {
        printf("Unable to optimize image %s! SDL Error: %s\n", path, SDL_GetError());
    }
    SDL_FreeSurface( loadedSurface );
    return optimizedSurface;
}

