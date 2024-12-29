#pragma once

#include <raylib.h>

#include "core/ecs.h"
#include "modules/world.h"

typedef struct Game {
  EntityManager *manager;
  Camera *camera;
  Map *map;
} Game;

Game *init_game();
void cleanup_game(Game *game);
void update_game(Game *game);
int render_game(Game *game);
