#include "game.h"
#include "camera.h"
#include "map.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

Game *init_game() {
  InitWindow(1270, 720, "Empire Earth - The New Age");

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

  game->camera = camera;
  game->map = map;

  SetTargetFPS(60);

  return (game);
}

void update_game(Game *game) { (void)game; }

void render_game(Game *game) {
  BeginDrawing();
  ClearBackground(RAYWHITE);
  BeginMode3D(*game->camera);
  render_map(game->map);
  EndMode3D();
  EndDrawing();
}

void cleanup_game(Game *game) {
  free_map(game->map);
  free_camera(game->camera);
  free(game);
  game = NULL;
  CloseWindow();
}
