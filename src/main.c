#include "core/game.h"
#include <raylib.h>

int main() {
  Game *game = init_game();
  if (!game) {
    return (-1);
  }

  while (!WindowShouldClose()) {
    update_game(game);
    if (render_game(game) == -1) {
      return (-1);
    }
  }

  cleanup_game(game);
  return 0;
}
