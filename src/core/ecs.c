#include "core/ecs.h"

#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#include "components/components.h"
#include "components/selection.h"
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

void update_entity_bounding_box(EntityManager *manager, Entity entity) {
  EntitySelection *selection = ecs_get_component(manager, entity, COMPONENT_SELECTED);
  EntityTransform *transform = ecs_get_component(manager, entity, COMPONENT_TRANSFORM);
  if (!selection || !transform) return;
  selection->box = (BoundingBox){
      (Vector3){transform->position.x - transform->size.x / 2, transform->position.y - transform->size.y / 2,
                transform->position.z - transform->size.z / 2},
      (Vector3){transform->position.x + transform->size.x / 2, transform->position.y + transform->size.y / 2,
                transform->position.z + transform->size.z / 2}};
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
      EntitySelection *selection = ecs_get_component(manager, e, COMPONENT_SELECTED);
      EntityTransform *transform = ecs_get_component(manager, e, COMPONENT_TRANSFORM);
      transform->position = (Vector3){x, 1.0f, 0.0f};
      if (transform) {
        if (selection->is_selected) {
          DrawCube(transform->position, transform->size.x, transform->size.y, transform->size.x, RED);
        } else {
          DrawCube(transform->position, transform->size.x, transform->size.y, transform->size.x, GRAY);
        }
        x++;
      }
    }
  }
}
