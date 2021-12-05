#include "game.h"

SDL_Event gEvent;

int g_quit = 0;
int g_pause = 0;

static void pollInput() {
    while(SDL_PollEvent(&gEvent) != 0) {
        if (gEvent.type == SDL_QUIT) g_quit = 1;
        pEvent(&gEvent);
    }
}

static void doGameInit() {
    SDL_Init(SDL_INIT_VIDEO);
    App.win = SDL_CreateWindow(
        "App",
        0, 0, WIN_WIDTH, WIN_HEIGHT,
        WIN_FLAGS
    );
    App.screen = SDL_GetWindowSurface(App.win);
    pInit();
}

static void doGameDraw() {
    gWipe();
    pDraw();
    gUpdate();
}

static void doGameLogic() {
    pLogic();
}

void doGameLoop() {
    doGameInit();
    while(g_quit == 0) {
        pollInput();
        doGameLogic();
        doGameDraw();
    }
    // Gracefully exit
    SDL_DestroyWindow(App.win);
    App.win = NULL;
    SDL_FreeSurface(App.screen);
    App.screen = NULL;
    SDL_Quit();
}


