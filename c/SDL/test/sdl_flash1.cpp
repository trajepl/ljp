//#define __linux__
#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_rotozoom.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_gfxPrimitives.h"

SDL_Surface* pScreen = 0;
SDL_Surface* pBack = 0;
SDL_Surface* pFront = 0;

void pressESCtoQuitPlus();
void loopRender();

int main(int argc, char* argv[])
{

#ifdef __linux__
    putenv("SDL_VIDEODRIVER=dga");
#endif

    try {
        if ( SDL_Init(SDL_INIT_VIDEO) != 0 )
            throw SDL_GetError();
    }
    catch ( const char* s ) {
        std::cerr << "SDL_Init() failed!/n" << s << std::endl;
        return -1;
    }

    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int SCREEN_BPP = 32;    
    const Uint32 SCREEN_FLAGS = SDL_FULLSCREEN | SDL_DOUBLEBUF | SDL_HWSURFACE;

    pScreen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SCREEN_FLAGS);    
    try {
        if ( pScreen == 0 )
            throw SDL_GetError();
    }
    catch ( const char* s ) {
        std::cerr << "SDL_SetVideoMode() failed!/n" << s << std::endl;
        SDL_Quit();
        return -1;
    }

    pBack = SDL_LoadBMP("2.bmp"); 
    try {
        if ( pBack == 0 )
            throw SDL_GetError();
    }
    catch ( const char* s ) {
        std::cerr << "SDL_LoadBMP() failed!/n" << s << std::endl;
        SDL_Quit();
        return -1;
    }

    pFront = SDL_LoadBMP("3.bmp"); 
    try {
        if ( pFront == 0 )
            throw SDL_GetError();
    }
    catch ( const char* s ) {
        std::cerr << "SDL_LoadBMP() failed!/n" << s << std::endl;
        SDL_Quit();
        return -1;
    }

    try {
        pressESCtoQuitPlus();
    }
    catch ( const char* s ) {
        std::cerr << "pressESCtoQuitPlus() failed!/n" << s << std::endl;
        SDL_Quit();
        return -1;
    }

    SDL_Quit();

    return 0;
}

void pressESCtoQuitPlus()
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
        loopRender();
    }
    return;
}

void loopRender()
{
    SDL_Rect* pSrcRect = 0;    
    SDL_Rect* pDstRect = 0;
    if ( SDL_BlitSurface(pBack, pSrcRect, pScreen, pDstRect) != 0 )
        throw SDL_GetError();
    if ( SDL_BlitSurface(pFront, pSrcRect, pScreen, pDstRect) != 0 )
        throw SDL_GetError();
    if ( SDL_Flip(pScreen) != 0 )
        throw SDL_GetError();
    return;
}