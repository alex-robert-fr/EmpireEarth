#include "core/game.h"
#include "core/ecs.h"
#include "modules/camera.h"
#include "modules/world.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

Game *init_game() {
  InitWindow(1270, 720, "Empire Earth - The New Age");

  EntityManager *manager = create_entity_manager();
  if (!manager) {
    CloseWindow();
    return (NULL);
  }

  Camera3D *camera =
      create_camera((Vector3){10.0f, 10.0f, 10.0f}, (Vector3){0.0f, 0.0f, 0.0f},
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
  game->counter = "0";

  return (game);
}

void update_game(Game *game) {
  (void)game;
  if (IsKeyPressed(KEY_P)) {
  }
}

void render_game(Game *game) {
  BeginDrawing();
  ClearBackground(RAYWHITE);
  DrawFPS(5, 0);
  DrawText(game->counter, 5, 20, 20, RED);
  BeginMode3D(*game->camera);
  render_map(game->map);
  EndMode3D();
  EndDrawing();
}

void cleanup_game(Game *game) {
  free_map(game->map);
  free_camera(game->camera);
  free_entity_manager(game->manager);
  free(game);
  game = NULL;
  CloseWindow();
}
