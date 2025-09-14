#include "../include/game.h"

auto main () -> int{

  InitWindow(800, 600, "Pong game");
  SetTargetFPS(60);

  Game game;

  game.run();

  CloseWindow();

  return 0;
}
