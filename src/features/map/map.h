#pragma once

#include <raylib.h>

typedef struct Map {
  Vector3 position;
  Vector2 size;
} Map;

Map *create_map(Vector3 position, Vector2 size);
void free_map(Map *map);
void render_map(Map *map);
