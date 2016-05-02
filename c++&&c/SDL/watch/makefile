CPPFLAGS = $(shell sdl-config --cflags)
LDLIBS  =  $(shell sdl-config --libs) -lSDL -lSDL_image -lSDL_gfx -w  

all: i clock

run:
	./clock 

clean:
	rm -fr *.o clock