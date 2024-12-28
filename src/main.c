#include "game.h"
#include <raylib.h>

int main() {
  Game *game = init_game();
  if (!game) {
    return (-1);
  }

  while (!WindowShouldClose()) {
    update_game(game);
    render_game(game);
  }

  cleanup_game(game);
  return 0;
}
