#include "../include/logic.h"

Logic::Logic(Ball& ball, Bat& batR, Bat& batL)
  :m_rBall(ball), m_rBatR(batR), m_rBatL(batL), m_ScoreR(0), m_ScoreL(0){}

void Logic::playSound(){}

void Logic::update(){
  auto t_ballPos = m_rBall.getPosition();
  auto t_ballCenter = Vector2{m_rBall.getRadius() + t_ballPos.x, m_rBall.getRadius() + t_ballPos.y};
  
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
  }

  if (m_rBall.getPosition().x > static_cast<float>(GetScreenWidth())) {
    m_ScoreL++;
    m_rBall.reset();
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
