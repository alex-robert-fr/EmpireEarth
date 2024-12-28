#pragma once

#include "core/ecs.h"
#include "modules/world.h"
#include <raylib.h>
struct Camera3D;
struct Map;
struct EntityManager;

typedef struct Game {
  EntityManager *manager;
  Camera3D *camera;
  Map *map;
  char *counter;
} Game;

Game *init_game();
void cleanup_game(Game *game);
void update_game(Game *game);
void render_game(Game *game);
