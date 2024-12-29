#include "modules/camera.h"

#include <stdio.h>
#include <stdlib.h>

Camera3D *create_camera(Vector3 position, Vector3 target, Vector3 up, float fovy, int projection) {
  Camera3D *camera = calloc(1, sizeof(Camera3D));
  if (!camera) {
    fprintf(stderr, "Error: Allocation failed %s:%d\n", __FILE__, __LINE__);
    return (NULL);
  }
  camera->position = position;
  camera->target = target;
  camera->up = up;
  camera->fovy = fovy;
  camera->projection = projection;
  return (camera);
}

void free_camera(Camera3D *camera) {
  free(camera);
  camera = NULL;
}
