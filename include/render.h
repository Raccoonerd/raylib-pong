#pragma once
#include "bat.h"
#include "ball.h"
#include "logic.h"

class Render{
private:
  Ball& m_rBall;
  Bat& m_rBatR, m_rBatL;
  Logic& m_rLogic;

  static void drawCenterLine();
  void drawScore() const;
public:
  Render(Ball& r_ball, Bat& r_batR, Bat& r_batL, Logic& r_logic);

  void render() const;
};
