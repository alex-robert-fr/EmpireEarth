#pragma once

#include "components/components.h"
#define MAX_ENTITIES 1000
#define MAX_COMPONENTS 32

typedef int Entity;

typedef struct {
  int active[MAX_ENTITIES];
  void *components[MAX_COMPONENTS][MAX_ENTITIES];
  int entities_number;
} EntityManager;

EntityManager *create_entity_manager();
void free_entity_manager(EntityManager *manager);

Entity ecs_create_entity(EntityManager *manager);
int ecs_add_component(EntityManager *manager, Entity entity,
                      ComponentID component_id, void *component);
void *ecs_get_component(EntityManager *manager, Entity entity,
                        ComponentID component_id);
void render_entities(EntityManager *manager);
