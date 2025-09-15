#include "../include/game.h"
#include <raylib.h>

Game::Game()
  :m_state(GameState::MENU),
  m_ball({800/2, 600/2}, 10),
  m_batL({50, (600/2) - 40}, {.x=20, .y=80}, KEY_W , KEY_S),
  m_batR({800-50, (600/2) - 40}, {.x=20, .y=80}, KEY_UP, KEY_DOWN),
  m_logic(m_ball, m_batR, m_batL),
  m_update(m_ball, m_batR, m_batL, m_logic),
  m_render(m_ball, m_batR, m_batL, m_logic) {}

void Game::run(){
  m_ball.reset();
  while (!WindowShouldClose()) {
    if (m_state == GameState::MENU) {
      m_menu.update();
      BeginDrawing();
      ClearBackground(BLACK);
      m_menu.render();
      EndDrawing();

      if (IsKeyPressed(KEY_ENTER)) {
        switch (m_menu.getSelectedIndex()) {
          case 0: m_state = GameState::SINGLEPLAYER; break;
          case 1: m_state = GameState::MULTIPLAYER; break;
          case 2: m_state = GameState::EXIT; break;
        }
      }
    } else if(m_state == GameState::MULTIPLAYER || m_state == GameState::SINGLEPLAYER){
      m_update.update();
      m_render.render();

      if (IsKeyPressed(KEY_Q)) {
        m_state = GameState::MENU;
      }
    } else if(m_state == GameState::EXIT){
      break;
    }
  }
  
}
