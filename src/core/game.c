#include "core/game.h"

#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#include "components/components.h"
#include "components/transform.h"
#include "core/ecs.h"
#include "debug/entity.h"
#include "modules/camera.h"
#include "modules/world.h"

Game *init_game() {
  InitWindow(1270, 720, "Empire Earth - The New Age");

  EntityManager *manager = create_entity_manager();
  if (!manager) {
    CloseWindow();
    return (NULL);
  }

  Camera3D *camera = create_camera((Vector3){10.0f, 10.0f, 10.0f}, (Vector3){0.0f, 0.0f, 0.0f},
                                   (Vector3){0.0f, 1.0f, 0.0f}, 45.0f, CAMERA_PERSPECTIVE);
  if (!camera) {
    CloseWindow();
    return (NULL);
  }

  Map *map = create_map((Vector3){0.0f, 0.0f, 0.0f}, (Vector2){10.0f, 10.0f});
  if (!map) {
    free_camera(camera);
    CloseWindow();
    return (NULL);
  }

  Game *game = calloc(1, sizeof(Game));
  if (!game) {
    fprintf(stderr, "Error: Allocation failed %s:%d\n", __FILE__, __LINE__);
    return (NULL);
  }

  game->manager = manager;
  game->camera = camera;
  game->map = map;
  game->manager->entities_number = 0;

  return (game);
}

void update_game(Game *game) {
  if (IsKeyPressed(KEY_P)) {
    Entity entity = ecs_create_entity(game->manager);
    EntityTransform transform = {.position = (Vector3){0.0f, 0.0f, 0.0f}, .size = (Vector3){0.7f, 0.7f, 0.7f}};
    ecs_add_component(game->manager, entity, COMPONENT_TRANSFORM, &transform);
  }
}

int render_game(Game *game) {
  BeginDrawing();
  ClearBackground(RAYWHITE);
  UpdateCameraPro(game->camera,
                  (Vector3){IsKeyDown(KEY_UP) * 0.01f - IsKeyDown(KEY_DOWN) * 0.01f,
                            IsKeyDown(KEY_RIGHT) * 0.01f - IsKeyDown(KEY_LEFT) * 0.01f, 0.0f},
                  (Vector3){0.0f, 0.0f, 0.0f}, 0);
  DrawFPS(5, 0);
  if (display_entity_number(game->manager->entities_number) == -1) {
    cleanup_game(game);
    return (-1);
  }
  BeginMode3D(*game->camera);
  render_map(game->map);
  render_entities(game->manager);
  EndMode3D();
  EndDrawing();
  return (0);
}

void cleanup_game(Game *game) {
  free_map(game->map);
  free_camera(game->camera);
  free_entity_manager(game->manager);
  free(game);
  game = NULL;
  CloseWindow();
}
