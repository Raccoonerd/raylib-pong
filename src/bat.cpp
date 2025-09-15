#include "../include/bat.h"

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
