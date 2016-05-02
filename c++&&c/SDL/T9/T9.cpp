/*
*	Compile Command:
*	g++ T9.cpp -I/usr/include/SDL -lSDL -lSDL_image -lSDL_gfx -lSDL_ttf -w -o T9
*/

#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_rotozoom.h"
#include "SDL_image.h"
#include "SDL_gfxPrimitives.h"

SDL_Surface *screen = NULL;
TTF_Font *font = NULL;
const SDL_Color RGB_Black = {0, 0, 0};
const SDL_Color RGB_Red = {255, 0, 0};
SDL_Rect rect;

const int CLIP_MOUSEOVER=0;
const int CLIP_MOUSEOUT=1;
const int CLIP_MOUSEDOWN=2;
const int CLIP_MOUSEUP=3;

void Init() {
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		printf("SDL_INIT can not Init!\n");
		return ;
	}
	if(TTF_Init() == -1){
		printf("SDL_TTF can not Init\n");
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

SDL_Rect Set_Image(int i) {
	SDL_Rect rect;

	rect.x = 60 * (i % 3);
	rect.y = screen->h / 2 + i / 3 * 40;
	return rect;
}

int isOnButton(int aX,int aY)
{
	int i, j;
	if(aY >= screen->h / 2){
		i = aX / 60;
		j = (aY - screen->h/2) / 40;
	//printf("i = %d  j = %d\n", i, j);
    	return i + j * 3;
    }
    else
    	return -1;
}

long millTime() {
	struct timeval now;
	gettimeofday(&now, NULL);
	return now.tv_sec;
}

int main() {

	long begin, end, t;
	t = 0;
	int flag = 1;
	Init();

	SDL_WM_SetIcon(Image_Load("T9_pic/T9.bmp"), NULL);

	SDL_Surface *image[13];
	char *pic[14];

	New_Screen(180, 320, 0, SDL_SWSURFACE);
	Show_Image(screen, 0);
	boxColor(screen, 0, 0, 180, 138, 0xffffffff);

	SDL_Rect over;
	over.x = 0;
	over.y = 138;
	SDL_Rect output;
	output.x = 0;
	output.y = 0;

	SDL_Surface *font_Surface = NULL;
	font  = TTF_OpenFont("sdl.ttf",15);

	pic[0] = "T9_pic/1.bmp";
	pic[1] = "T9_pic/2.bmp";
	pic[2] = "T9_pic/3.bmp";
	pic[3] = "T9_pic/4.bmp";
	pic[4] = "T9_pic/5.bmp";
	pic[5] = "T9_pic/6.bmp";
	pic[6] = "T9_pic/7.bmp";
	pic[7] = "T9_pic/8.bmp";
	pic[8] = "T9_pic/9.bmp";
	pic[9] = "T9_pic/0.bmp";
	pic[10] = "T9_pic/del.bmp";
	pic[11] = "T9_pic/enter.bmp";
	pic[12] = "T9_pic/tmp.bmp";
	pic[13] = "T9_pic/output_tmp.bmp";
	
	for(int i = 0; i < 14; i++) {
		image[i] = Image_Load(pic[i]);
	}
	
	for(int i = 0; i < 12; i++) {
		rect = Set_Image(i);    
		Show_Image(image[i], &rect);
	}
	SDL_Flip(screen);

	SDL_Rect rect_temp;
	rect_temp.x = 0;
	rect_temp.y = 140;
	
	//string in temp_area
	char tmp[100];
	char tmp2[100];
	int j = 0;
	memset(tmp, 0, sizeof(tmp) / sizeof(char));
	memset(tmp2, 0, sizeof(tmp2) / sizeof(char));

	SDL_Rect weight_next;
	weight_next.x = 0;

	while(flag) {
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			switch(event.type) {
				case SDL_KEYUP:{
					if(event.key.keysym.sym == SDLK_ESCAPE){
						flag = 0;
					}
				}break;

				case SDL_QUIT:{
					flag = 0;
					printf("\n\nquit!\n\n");
				} break;

				
				int image_area;

				case SDL_MOUSEBUTTONDOWN://鼠标按下
					begin = millTime();
					switch(event.button.button) {
                		case SDL_BUTTON_LEFT:
                			//得到当前鼠标的坐标
                    		int x = event.button.x;
                    		int y = event.button.y;                   
	                    	//判断鼠标是否落在登录按钮里
	                    	image_area = isOnButton(x, y);
	                    	//printf("%d %d image:%d\n", x, y, image_area);
		                    if (image_area<= 11 && image_area >= 0) {    
		                        rect = Set_Image(image_area);    
								Show_Image(image[12], &rect);
		                    	SDL_Flip(screen);
		                    }

                	} break;

         		case SDL_MOUSEBUTTONUP://鼠标键松开
         				end = millTime();
         		 		t = end - begin;
         		 		printf("Mouse_time :%ld\n", t);
         		 	switch(event.button.button) {
         		 		
                		case SDL_BUTTON_LEFT: {
		                    if (image_area<= 11 && image_area >= 0) {   

		                    	switch(image_area) {
									case 0:	
										tmp[j++] = '1';
										break;
									case 1:
										switch((t) % 4){
											case 0:
												tmp[j++] = '2';break;
											case 1:
												tmp[j++] = 'a';break;
											case 2:
												tmp[j++] = 'b';break;
											case 3:
												tmp[j++] = 'c';break;
										}
										break;
									case 2:
										switch((t) % 4){
											case 0:
												tmp[j++] = '3';break;
											case 1:
												tmp[j++] = 'd';break;
											case 2:
												tmp[j++] = 'e';break;
											case 3:
												tmp[j++] = 'f';break;
										}
										break;
									case 3:
										switch((t) % 4){
											case 0:
												tmp[j++] = '4';break;
											case 1:
												tmp[j++] = 'g';break;
											case 2:
												tmp[j++] = 'h';break;
											case 3:
												tmp[j++] = 'i';break;
										}
										break;
									case 4:
										switch((t) % 4){
											case 0:
												tmp[j++] = '5';break;
											case 1:
												tmp[j++] = 'j';break;
											case 2:
												tmp[j++] = 'k';break;
											case 3:
												tmp[j++] = 'l';break;
										}
										break;
									case 5:
										switch((t) % 4){
											case 0:
												tmp[j++] = '6';break;
											case 1:
												tmp[j++] = 'm';break;
											case 2:
												tmp[j++] = 'n';break;
											case 3:
												tmp[j++] = 'o';break;
										}
										break;
									case 6:
										switch((t) % 5){
											case 0:
												tmp[j++] = '7';break;
											case 1:
												tmp[j++] = 'p';break;
											case 2:
												tmp[j++] = 'q';break;
											case 3:
												tmp[j++] = 'r';break;
											case 4:
												tmp[j++] = 's';break;
										}
										break;
									case 7:
										switch((t) % 4){
											case 0:
												tmp[j++] = '8';break;
											case 1:
												tmp[j++] = 't';break;
											case 2:
												tmp[j++] = 'u';break;
											case 3:
												tmp[j++] = 'v';break;
										}
										break;
									case 8:
										switch((t) % 5){
											case 0:
												tmp[j++] = '9';break;
											case 1:
												tmp[j++] = 'w';break;
											case 2:
												tmp[j++] = 'x';break;
											case 3:
												tmp[j++] = 'y';break;
											case 4:
												tmp[j++] = 'z';break;
										}
										break;
									case 9:
										tmp[j++] = '0';
										break;
									case 10:
										j--;
										printf("---------------");
										Show_Image(image[13], &over);
										SDL_Flip(screen);
										break;
									case 11:
										if(j >= 1){
											strncpy(tmp2, tmp, j);
											font_Surface = TTF_RenderText_Blended(font, tmp2, RGB_Black);
											Show_Image(font_Surface, &output);

											output.x = output.x + font_Surface->w + 10;
											if((output.x + weight_next.x) > 179) {
												output.y += 15;
												output.x = 0;
											}

											Show_Image(image[13], &over);
											SDL_Flip(screen);
										}
										else break;

										break;
									} 

								if(image_area != 11) {
									if(j >= 1){
										strncpy(tmp2, tmp, j);
										font_Surface = TTF_RenderText_Blended(font, tmp2, RGB_Red);
										weight_next.x = font_Surface->w;
										Show_Image(font_Surface, &rect_temp);   
									}
									
									rect = Set_Image(image_area);    
									Show_Image(image[image_area], &rect);
									
									//rect_temp.x += 10;
									SDL_Flip(screen);
									//printf("---------------");
									
									memset(tmp2, 0, sizeof(tmp2) / sizeof(char));
								} else {
									rect = Set_Image(image_area);    
									Show_Image(image[image_area], &rect);
									Show_Image(font_Surface, &rect_temp);
									//rect_temp.x += 10;
									SDL_Flip(screen);
									memset(tmp2, 0, sizeof(tmp2) / sizeof(char));
									j = 0;
								}
								printf("j: %d\n", j);
		                    }
                		} break;
					}
			}
		}
	}
}
