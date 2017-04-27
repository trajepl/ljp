//compile sdl pro -I/usr/include/SDL -lSDL -lpthread

int SDL_Init(Uint32 flags);
/*Uint32 unsiged int 32;
	falgs */

int SDL_WasInit(Uint32 flags);

//two way to wait evet of sdl
int SDL_WaitEvent(SDL_Event *event);
int SDL_PollEvent(SDL_Event *event);

SDL_Surface *SDL_SetVideoMode(int width, int height, 
	int bitsperpixel, Uint32 flags);
