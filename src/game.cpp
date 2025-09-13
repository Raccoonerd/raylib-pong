#include "../include/game.h"

Game::Game()
  :m_ball({800/2, 600/2}, 10),
  m_batR({800-50, 600/2}, {.x=80, .y=20}, KEY_W, KEY_S),
  m_batL({50, 600/2}, {.x=80, .y=20}, KEY_UP, KEY_DOWN),
  m_logic(m_ball, m_batR, m_batL),
  m_update(m_ball, m_batR, m_batL, m_logic),
  m_render(m_ball, m_batR, m_batL, m_logic)
{
  InitWindow(800, 600, "Pong game");
}

Game::~Game(){
  CloseWindow();
}

void Game::run(){
  while (!WindowShouldClose()) {
    m_update.update();
    m_render.render();
  }
  
}
