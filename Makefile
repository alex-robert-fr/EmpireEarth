CC = clang
CFLAGS = -Wall -I/usr/local/include
LIBS = -L/usr/local/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all: empire_earth

empire_earth: main.c
	$(CC) main.c -o empire_earth $(CFLAGS) $(LIBS)

clean:
	rm -rf empire_earth
