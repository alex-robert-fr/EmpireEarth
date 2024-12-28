#pragma once

struct Camera3D;
struct Map;

typedef struct Game {
  struct Camera3D *camera;
  struct Map *map;
} Game;

Game *init_game();
void cleanup_game(Game *game);
void update_game(Game *game);
void render_game(Game *game);
