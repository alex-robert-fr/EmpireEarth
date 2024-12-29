#pragma once

#include <raylib.h>

Camera3D *create_camera(Vector3 position, Vector3 target, Vector3 up, float fovy, int projection);
void free_camera(Camera3D *camera);
