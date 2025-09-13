#include "../include/game.h"

Game::Game()
  :m_ball({800/2, 600/2}, 10),
  m_batR({800-50, 600/2}, {.x=20, .y=80}, KEY_O, KEY_K),
  m_batL({50, 600/2}, {.x=20, .y=80}, KEY_W, KEY_S),
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
  m_ball.reset();
  while (!WindowShouldClose()) {
    m_update.update();
    m_render.render();
  }
  
}
