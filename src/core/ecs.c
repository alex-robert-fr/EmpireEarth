#include "core/ecs.h"
#include <stdio.h>
#include <stdlib.h>

EntityManager *create_entity_manager() {
  EntityManager *manager = calloc(1, sizeof(EntityManager));
  if (!manager) {
    fprintf(stderr, "Error: Allocation failed %s:%d\n", __FILE__, __LINE__);
    return (NULL);
  }

  return (manager);
}

void free_entity_manager(EntityManager *manager) {
  free(manager);
  manager = NULL;
}

Entity ecs_create_entity(EntityManager *manager) {
  for (Entity e = 0; e < MAX_ENTITIES; e++) {
    if (!manager->active[e]) {
      manager->active[e] = 1;
      manager->entities_number++;
      return (e);
    }
  }
  return (-1);
}
