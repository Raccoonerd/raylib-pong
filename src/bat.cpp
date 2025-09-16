#include "../include/bat.h"
#include <raylib.h>

Bat::Bat(Vector2 pos, Size size, KeyboardKey upKey, KeyboardKey downKey)
  :Object(pos, size), m_upKey(upKey), m_downKey(downKey){}

void Bat::handleInput(){
  if (IsKeyDown(m_upKey)) {
    setVelocity({0, -BAT_SPEED});
  } else if (IsKeyDown(m_downKey)) {
    setVelocity({0, BAT_SPEED});
  } else {
    setVelocity({0, 0});
  }
}

void Bat::updateAI(const Ball& t_rBall, int t_frameCounter){
  if (t_frameCounter % 2 != 0) {
   return;
  }

  auto t_ballPos = t_rBall.getPosition();
  auto t_ballCenterY = t_ballPos.y + t_rBall.getRadius();

  auto t_batPos = getPosition();
  auto t_batCenterY = t_batPos.y + (getSize().y / 2.0F);

  const float aiSpeed = BAT_SPEED * 0.99F;

  if (t_ballCenterY < t_batCenterY - 5) {
    setVelocity({0, -aiSpeed});
  } else if(t_ballCenterY > t_batCenterY + 5) {
    setVelocity({0, aiSpeed});
  } else {
    setVelocity({0,0});
  }

  Object::update();

  if (t_batPos.y < 0) {
    t_batPos.y = 0;
    setPosition(t_batPos);
  }
  if (t_batPos.y + getSize().y > static_cast<float>(GetScreenHeight())) {
    t_batPos.y = static_cast<float>(GetScreenHeight()) - getSize().y;
    setPosition(t_batPos);
  }
}

void Bat::update() {
  handleInput();
  Object::update();

  auto t_pos = getPosition();
  auto t_size = getSize();

  if (t_pos.y < 0) {
    t_pos.y = 0;
    setPosition(t_pos);
  }

  if (t_pos.y + t_size.y > static_cast<float>(GetScreenHeight())) {
    t_pos.y = static_cast<float>(GetScreenHeight()) - t_size.y;
    setPosition(t_pos);
  }
}

void Bat::reset(Vector2 pos){
  setPosition(pos);
}
