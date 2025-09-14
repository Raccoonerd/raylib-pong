#pragma once
#include "ball.h"
#include "bat.h"
#include "logic.h"

class Update{
private:
  Ball& m_rBall;
  Bat& m_rBatR;
  Bat& m_rBatL;
  Logic& m_rLogic;

public:
  Update(Ball& r_ball, Bat& r_batR, Bat& r_batL, Logic& r_logic);

  void update();
  void reset();
};
