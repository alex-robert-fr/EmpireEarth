CC = clang
CFLAGS = -Wall
LIBS = -lraylib

all: empire_earth

empire_earth: main.c
	$(CC) $(CFLAGS) main.c -o empire_earth $(LIBS)

clean:
	rm -rf empire_earth
