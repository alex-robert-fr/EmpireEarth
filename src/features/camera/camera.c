#include "camera.h"
#include <stdlib.h>

Camera3D *init_camera() {
  Camera3D *camera = calloc(1, sizeof(Camera3D));

  camera->position = (Vector3){10.0f, 10.0f, 10.0f};
  camera->target = (Vector3){0.0f, 0.0f, 0.0f};
  camera->up = (Vector3){0.0f, 1.0f, 0.0f};
  camera->fovy = 45.0f;
  camera->projection = CAMERA_PERSPECTIVE;

  return camera;
}

void free_camera(Camera3D *camera) { free(camera); }
