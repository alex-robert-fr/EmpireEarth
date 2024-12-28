#include "map.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

Map *create_map(Vector3 position, Vector2 size) {
  Map *map = calloc(1, sizeof(Map));
  if (!map) {
    fprintf(stderr, "Error: Allocation failed %s:%d\n", __FILE__, __LINE__);
    return (NULL);
  }

  map->position = position;
  map->size = size;
  return (map);
}

void free_map(Map *map) {
  free(map);
  map = NULL;
}

void render_map(Map *map) {
  DrawPlane(map->position, map->size, BROWN);
  DrawGrid(20, 0.5f);
}
