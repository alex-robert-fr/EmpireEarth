#include "modules/selection.h"

#include <raylib.h>

#include "components/components.h"
#include "components/selection.h"
#include "core/ecs.h"

Ray create_ray_from_mouse(Vector2 mouse_position, Camera3D camera) {
  return (GetScreenToWorldRay(mouse_position, camera));
}

int detect_entity_collision(Ray ray, EntityManager *manager) {
  for (Entity e = 0; e < MAX_ENTITIES; e++) {
    update_entity_bounding_box(manager, e);
    EntitySelection *selection = ecs_get_component(manager, e, COMPONENT_SELECTED);
    if (selection) {
      RayCollision collision = GetRayCollisionBox(ray, selection->box);
      if (collision.hit) {
        selection->is_selected = true;
        return (e);
      }
    }
  }
  deselected_all_entity(manager);
  return (-1);
}

void deselected_all_entity(EntityManager *manager) {
  for (Entity e = 0; e < MAX_ENTITIES; e++) {
    EntitySelection *selection = ecs_get_component(manager, e, COMPONENT_SELECTED);
    if (selection) {
      selection->is_selected = false;
    }
  }
}
