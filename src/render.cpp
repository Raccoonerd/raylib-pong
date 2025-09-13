#include "../include/render.h"
#include <raylib.h>

Render::Render(Ball& r_ball, Bat& r_batR, Bat& r_batL, Logic& r_logic)
  :m_rBall(r_ball), m_rBatR(r_batR), m_rBatL(r_batL), m_rLogic(r_logic){}

void Render::drawCenterLine(){
  DrawLine(GetScreenWidth()/2, 0, GetScreenWidth()/2, GetScreenHeight(), RAYWHITE);
}

void Render::drawScore() const{
  auto t_scoreR = m_rLogic.getScoreRight();
  auto t_scoreL = m_rLogic.getScoreLeft();

  DrawText(TextFormat("%i", t_scoreR), 3*GetScreenWidth()/4, 20, 40, RAYWHITE);
  DrawText(TextFormat("%i", t_scoreL), GetScreenWidth()/4, 20, 40, RAYWHITE);
}

void Render::render() const{
  BeginDrawing();

  ClearBackground(BLACK);
  
  DrawRectangleRec(m_rBatR.getRectangle(), m_rBatR.getColor());
  DrawRectangleRec(m_rBatL.getRectangle(), m_rBatL.getColor());

  DrawCircleV(m_rBall.getPosition(), m_rBall.getRadius(), m_rBall.getColor());

  drawCenterLine();
  drawScore();

  EndDrawing();
}
