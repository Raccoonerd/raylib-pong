#pragma once
#include "ball.h"
#include "bat.h"
#include "logic.h"
#include "update.h"
#include "render.h"

class Game{
private:
  Ball m_ball;
  Bat m_batR, m_batL;
  Logic m_logic;
  Update m_update;
  Render m_render;

public:
  Game();
  ~Game();

  void run();
};
