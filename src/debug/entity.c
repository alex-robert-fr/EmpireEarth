#include "debug/entity.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

int display_entity_number(int entities_number) {
  char *counter = calloc(1, 7); // Jusqu'à 999 999 entités
  if (!counter) {
    fprintf(stderr, "Error: Allocation failed %s:%d\n", __FILE__, __LINE__);
    return (-1);
  }
  snprintf(counter, 7, "%d", entities_number);
  DrawText(counter, 5, 20, 20, RED);
  free(counter);
  counter = NULL;
  return (0);
}
