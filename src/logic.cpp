#include "../include/logic.h"

Logic::Logic(Ball& r_ball, Bat& r_batR, Bat& r_batL)
  :m_rBall(r_ball), m_rBatR(r_batR), m_rBatL(r_batL), m_ScoreR(0), m_ScoreL(0){}

void Logic::playSound(){}

void Logic::update(){
  auto t_batLPos = Vector2{50, (600/2) - 40};
  auto t_batRPos = Vector2{800-50, (600/2) - 40};
  auto t_ballPos = m_rBall.getPosition();
  auto t_ballCenter = Vector2{
    t_ballPos.x + m_rBall.getRadius(),
    t_ballPos.y + m_rBall.getRadius()
  };
 
  if(CheckCollisionCircleRec(t_ballCenter, m_rBall.getRadius(), m_rBatR.getRectangle())){
    t_ballPos.x -= m_rBall.getRadius();
    m_rBall.setPosition(t_ballPos);
    m_rBall.invertX();
  }

  if(CheckCollisionCircleRec(t_ballCenter, m_rBall.getRadius(), m_rBatL.getRectangle())){
    t_ballPos.x += m_rBall.getRadius();
    m_rBall.setPosition(t_ballPos);
    m_rBall.invertX();
  }

  if (m_rBall.getPosition().x < 0) {
    m_ScoreR++;
    m_rBall.reset();
    m_rBatL.reset(t_batLPos);
    m_rBatR.reset(t_batRPos);
  }

  if (m_rBall.getPosition().x > static_cast<float>(GetScreenWidth())) {
    m_ScoreL++;
    m_rBall.reset();
    m_rBatL.reset(t_batLPos);
    m_rBatR.reset(t_batRPos);
  }
}

void Logic::reset(){
  m_ScoreR = 0;
  m_ScoreL = 0;
  m_rBall.reset();
}

auto Logic::getScoreRight() const -> int{
  return m_ScoreR;
}

auto Logic::getScoreLeft() const -> int{
  return m_ScoreL;
}
