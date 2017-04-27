#include <iostream>
#include "SDL/SDL.h"

void pressESCtoQuit();

int main(int argc, char* argv[])
{
    try {
        if ( SDL_Init(SDL_INIT_VIDEO) != 0 )
            throw SDL_GetError();
    }
    catch ( const char* s ) {
        std::cerr << "SDL_Init() failed!/n" << s << std::endl;
        return -1;
    }

    const int SCREEN_WIDTH = 640;    // 0 means use current width.
    const int SCREEN_HEIGHT = 640;    // 0 means use current height.
    const int SCREEN_BPP = 32;        // 0 means use current bpp.
    const Uint32 SCREEN_FLAGS = SDL_SWSURFACE;    // SDL_SWSURFACE == 0,surface in system memory.

    SDL_Surface* pScreen = 0;
    pScreen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SCREEN_FLAGS);    // Creat a SDL window, and get the window's surface.
    try {
        if ( pScreen == 0 )
            throw SDL_GetError();
    }
    catch ( const char* s ) {
        std::cerr << "SDL_SetVideoMode() failed!/n" << s << std::endl;
        SDL_Quit();
        return -1;
    }

    SDL_Surface* pShownBMP = 0;
    pShownBMP = SDL_LoadBMP("2.bmp"); // Load a BMP file, and convert it as a surface.
    try {
        if ( pShownBMP == 0 )
            throw SDL_GetError();
    }
    catch ( const char* s ) {
        std::cerr << "SDL_LoadBMP() failed!/n" << s << std::endl;
        SDL_Quit();
        return -1;
    }

    SDL_Rect* pSrcRect = 0;    // If pSrcRect is NULL, the entire source surface is copied. 
 
    SDL_Rect* pDstRect = 0;    // If pDstRect is NULL, then the destination position (upper left corner) is (0, 0).
    try {
        if ( SDL_BlitSurface(pShownBMP, pSrcRect, pScreen, pDstRect) != 0 )    // Put the BMP's surface on the SDL window's surface.
            throw SDL_GetError();
    }
    catch ( const char* s ) {
        std::cerr << "SDL_BlitSurface() failed!/n" << s << std::endl;
        SDL_Quit();
        return -1;
    }

    try {
        if ( SDL_Flip(pScreen) != 0 )    // Show the SDL window's surface.
            throw SDL_GetError();
    }
    catch ( const char* s ) {
        std::cerr << "SDL_Flip() failed!/n" << s << std::endl;
        SDL_Quit();
        return -1;
    }

    pressESCtoQuit();
    SDL_Quit();

    SDL_FreeSurface( pShownBMP ); 
    SDL_Quit();
    return 0;
}

void pressESCtoQuit()
{
    bool gameOver = false;
    while( gameOver == false ){
        SDL_Event gameEvent;
        while ( SDL_PollEvent(&gameEvent) != 0 ){
            if ( gameEvent.type == SDL_QUIT ){
                gameOver = true;
            }
            if ( gameEvent.type == SDL_KEYUP ){
                if ( gameEvent.key.keysym.sym == SDLK_ESCAPE ){
                    gameOver = true;
                }
            }
        }
    }
    return;
}