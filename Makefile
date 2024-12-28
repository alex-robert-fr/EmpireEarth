NAME			=	EmpireEarth
CC				= clang
CFLAGS 		= -Wall -Werror -Wextra
RAYLIB		=	-I/usr/local/include -L/usr/local/lib -lraylib
LIBS 			= -lGL -lm -lpthread -ldl -lrt -lX11
SRC				=	./src/main.c	\
						./src/features/camera/camera.c	\
						./src/features/map/map.c	\
						./src/features/game/game.c
INCLUDES	=	-Isrc/includes/	\
						-Isrc/features/camera/	\
						-Isrc/features/map/	\
						-Isrc/features/game/
OBJ_SRC		=	$(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ_SRC)
	$(CC) $(CFLAGS) -o $(NAME) $^ $(INCLUDES) $(RAYLIB) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -g -c -o $@ $<

debug:
	valgrind --leak-check=full ./$(NAME)

compiledb:
	bear -- make re

clean:
	rm -rf $(OBJ_SRC)

fclean: clean
	rm -rf $(NAME)

re: fclean all
