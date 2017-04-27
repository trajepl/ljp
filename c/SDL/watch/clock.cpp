//g++ sdl_table.cpp -I/usr/include/SDL -lSDL -lpthread -lSDL_image -lSDL_gfx

#include <stdio.h>
#include <time.h>
#include "SDL.h"
#include "SDL_rotozoom.h"
#include "SDL_image.h"
#include "SDL_gfxPrimitives.h"

SDL_Surface *screen = NULL;
SDL_Rect rect;

void Init() {
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		printf("SDL_INIT can not Init!\n");
		return ;
	}
	return ;
}

void New_Screen(int width, int heigh, int bpp, Uint32 flags) {
	screen = SDL_SetVideoMode(width, heigh, bpp, flags);
	if(screen == NULL) {
		printf("SDL_SetVideoMode default!\n" );
		return ;
	}
	return ;
}

SDL_Surface *Image_Load(char *filename) {
	SDL_Surface *image = NULL;
	//image = IMG_Load(filename);
	image = SDL_LoadBMP(filename);
	if(image == NULL) {
		printf("The image load default, maybe can't find the file!\n");
		exit(0);
	}
	return image;
}

void Free_Image(SDL_Surface *image) {
	SDL_FreeSurface(image);
}

int Show_Image(SDL_Surface *image, SDL_Rect *rect) {
	SDL_BlitSurface(image, NULL, screen, rect);
	SDL_Flip(image);
	return 0;
}

SDL_Rect Set_Image(SDL_Surface *image, double zoom) {
	SDL_Rect rect;

	rect.x = (screen->w - image->w) / 2;
	rect.y = (screen->h - image->h) / 2;
	//rect.x = screen->w / 2;
	//rect.y = screen->h / 2;
	return rect;
}

SDL_Surface *Point_Sec(SDL_Surface *image, double *angle) {
	SDL_Surface *change = NULL;
	SDL_Rect rect;
	
	if(*angle <= -360) {
		*angle += 360;
	}

	*angle = *angle - 6.0;
	change = rotozoomSurfaceXY(image, *angle, 1, 1, 1);
	rect = Set_Image(change, 1);
	Show_Image(change, &rect);
	Free_Image(change);

	return change;
}

SDL_Surface *Point_Min(SDL_Surface *image, double *angle, double sec) {
	SDL_Surface *change = NULL;
	SDL_Rect rect;
	
	if((int)sec % 360 == 0) {
		if(*angle <= -360) {
			*angle += 360;
		}
		*angle = *angle - 6;
	}

	change = rotozoomSurfaceXY(image, *angle, 1, 1, 1);
	rect = Set_Image(change, 1);
	Show_Image(change, &rect);
	Free_Image(change);
	return change;
}

SDL_Surface *Point_Hour(SDL_Surface *image, double *angle, double min, double sec) {
	SDL_Surface *change = NULL;
	SDL_Rect rect;
	int flag = 1;
	int swap = (int)min;
	if((int)min % 60 == 0 && (int)sec % 360 == 0) {
		if(*angle <= -360) {
			*angle += 360;
		}
		// if(swap == min) {
		// 	flag = 1;
		// }
		//if(flag) {
		*angle = *angle - 5;
			//flag = 0;
		//}
		
	}

	change = rotozoomSurfaceXY(image, *angle, 1, 1, 1);
	rect = Set_Image(change, 1);
	Show_Image(change, &rect);
	Free_Image(change);
	return change;
}

void Get_System_Time(double *hour, double *min, double *sec) {
	struct tm *now;
	time_t Time = time(NULL);
	now = localtime(&Time);
	*hour = (double)now->tm_hour;
	*min = (double)now->tm_min;
	*sec = (double)now->tm_sec;
	//*hour = 19;
	//*min = 9;
	//*sec = 50;
	printf("The system time now: %d: %d: %d", 
		(int)*hour, (int)*min, (int)*sec);

	*sec = -(*sec/60 * 360);
	*min = -(*min/60 * 360);
	if(*hour > 12){
	 	*hour = *hour - 12;
	}
	*hour = -(int)*hour * 30 + (int)*min / 12 / 5 * 5; 
}

int main(int args, char **argc) {
	int flag = 1;
	Init();

	rect.x = 80;
	rect.y = 0;

	double sec = 0, min = 0, hour = 0, zoom_xy = 1;
	SDL_Surface *change = NULL, *image = NULL, *image_2 = NULL,
		*image_3 = NULL, *background = NULL;
	New_Screen(640, 480, 0, SDL_SWSURFACE);
	boxColor(screen, 0, 0, 640, 480, 0xffffffff);
	Show_Image(screen, 0);

	char pic[] = "table/sec.bmp";
	char pic_2[] = "table/min.bmp";
	char pic_3[] = "table/hour.bmp";
	char bcg[] = "table/a.bmp";

	background = Image_Load(bcg);
	image = Image_Load(pic);
	image_2 = Image_Load(pic_2);
	image_3 = Image_Load(pic_3);
	

	rect = Set_Image(background, 1);       
	Show_Image(background, &rect);

	Get_System_Time(&hour, &min, &sec);

	while(flag) {
		Point_Sec(image, &sec);
		Point_Min(image_2, &min, sec);
		Point_Hour(image_3, &hour, min, sec);
		SDL_Flip(screen);

		SDL_Delay(1000);
		Show_Image(background, &rect);

		SDL_Event event;
		while(SDL_PollEvent(&event)){
			switch(event.type) {
				case SDL_KEYUP:
					if(event.key.keysym.sym == SDLK_ESCAPE){
						flag = 0;
					}break;
				case SDL_QUIT:{
					flag = 0;
					printf("\n\nquit!\n\n");
				}break;
			}
		}
	

	}


}
