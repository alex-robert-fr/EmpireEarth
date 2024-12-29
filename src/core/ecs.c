#include "core/ecs.h"

#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#include "components/components.h"
#include "components/transform.h"

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

int ecs_add_component(EntityManager *manager, Entity entity, ComponentID component_id, void *component) {
  if (manager->active[entity]) {
    manager->components[component_id][entity] = component;
    return (0);
  } else {
    fprintf(stderr, "Error : Entity %d not find.\n", entity);
    return (-1);
  }
}

void *ecs_get_component(EntityManager *manager, Entity entity, ComponentID component_id) {
  return (manager->components[component_id][entity]);
}

void render_entities(EntityManager *manager) {
  float x = 0.0f;
  for (Entity e = 0; e < MAX_ENTITIES; e++) {
    if (manager->active[e]) {
      EntityTransform *transform = ecs_get_component(manager, e, COMPONENT_TRANSFORM);
      if (transform) {
        DrawCube((Vector3){x, 1.0f, 0.0f}, 0.7f, 0.7f, 0.7f, RED);
        x++;
      }
    }
  }
}
