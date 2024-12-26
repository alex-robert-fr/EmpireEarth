#include <raylib.h>

int main() {
  InitWindow(800, 600, "Empire Earth - The New Age");
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello world!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
