#include "camera.h"
#include <raylib.h>

int main() {
  InitWindow(1270, 720, "Empire Earth - The New Age");

  Camera3D *camera = init_camera();

  Vector3 map_position = {0.0f, 0.0f, 0.0f};

  Vector3 unit = {0.0f, 1.0f, 0.0f};
  Vector3 unit_size = {1.0f, 3.0f, 1.0};

  Ray ray = {0};
  RayCollision collision = {0};
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(*camera);
    DrawPlane(map_position, (Vector2){10.0f, 10.0f}, BROWN);
    DrawGrid(10, 1.0f);
    if (collision.hit) {
      DrawCube(unit, unit_size.x, unit_size.y, unit_size.z, RED);
      DrawCubeWires(unit, unit_size.x, unit_size.y, unit_size.z, MAROON);
      DrawCubeWires(unit, unit_size.x + 0.2f, unit_size.y + 0.2f,
                    unit_size.z + 0.2f, GREEN);
    } else {
      DrawCube(unit, unit_size.x, unit_size.y, unit_size.z, GRAY);
      DrawCubeWires(unit, unit_size.x, unit_size.y, unit_size.z, DARKGRAY);
    }
    DrawRay(ray, BROWN);

    EndMode3D();
    EndDrawing();
  }
  free_camera(camera);
  CloseWindow();
  return 0;
}
