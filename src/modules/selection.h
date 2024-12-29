#pragma once

#include <raylib.h>

#include "core/ecs.h"

Ray create_ray_from_mouse(Vector2 mouse_position, Camera3D camera);
int detect_entity_collision(Ray ray, EntityManager *manager);
