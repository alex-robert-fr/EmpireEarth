#pragma once

#include <raylib.h>
#include <stdbool.h>

typedef struct EntitySelection {
  bool is_selected;
  BoundingBox box;
} EntitySelection;
