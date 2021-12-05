#include "player.h"

// Player data
char* pImgPath = "assets/Player.bmp";
vec2 pPosition = {32.f, 32.f};
SDL_Surface* pImg = NULL;
SDL_Rect pRect = {32, 32, 64, 64};

// Keyboard state
struct {
    int w, a, s, d;
} _kb = {0, 0, 0, 0};

void pInit() {
    pImg = gLoad(pImgPath);
}

void pEvent(SDL_Event* e) {
    SDL_Keycode sym = e->key.keysym.sym;
    // Keydown
    if (e->type == SDL_KEYDOWN) {
        switch (sym) {
            case SDLK_w:
                _kb.w = 1;
                break;
            case SDLK_s:
                _kb.s = 1;
                break;
            case SDLK_a:
                _kb.a = 1;
                break;
            case SDLK_d:
                _kb.d = 1;
                break;
        }
    } 
    // Keyup
    if (e->type == SDL_KEYUP) {
        switch (sym) {
            case SDLK_w:
                _kb.w = 0;
                break;
            case SDLK_s:
                _kb.s = 0;        
                break;
            case SDLK_a:
                _kb.a = 0;
                break;
            case SDLK_d:
                _kb.d = 0;
                break;
        } 
    }
}

void pLogic() {
    if (_kb.w) pRect.y -= 1;
    if (_kb.s) pRect.y += 1;
    if (_kb.a) pRect.x -= 1;
    if (_kb.d) pRect.x += 1;
}

void pDraw() {
    SDL_Rect temp = pRect; 
    gBlitSurface(pImg, NULL, &temp); 
}

