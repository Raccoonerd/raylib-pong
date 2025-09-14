#include "../include/game.h"

auto main () -> int{

  InitWindow(800, 600, "Pong game");

  Game game;

  game.run();

  return 0;
}
