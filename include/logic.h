#pragma once
#include "ball.h"
#include "bat.h"

class Logic{
private:
  Ball& m_rBall;
  Bat& m_rBatR, m_rBatL;
  int m_ScoreR, m_ScoreL;

  void playSound();
public:
  Logic(Ball& ball, Bat& batR, Bat& batL);

  void update();
  void reset();

  [[nodiscard]] auto getScoreRight() const -> int;
  [[nodiscard]] auto getScoreLeft() const -> int;
};
