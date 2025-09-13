#include "../include/update.h"

Update::Update(Ball& r_ball, Bat& r_batR, Bat& r_batL, Logic& r_logic)
  :m_rBall(r_ball), m_rBatR(r_batR), m_rBatL(r_batL), m_rLogic(r_logic){}

void Update::update(){
  m_rBatL.update();
  m_rBatR.update();
  m_rBall.update();
  m_rLogic.update();
}

void Update::reset(){
  m_rLogic.reset();
}
