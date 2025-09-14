#pragma once
#include "object.h"
#include <raylib.h>

constexpr float BAT_SPEED = 6.0F;

class Bat
  :public Object
{
private:
  KeyboardKey m_upKey;
  KeyboardKey m_downKey;
  void handleInput();
public:
  Bat(Vector2 pos, Size size, KeyboardKey upKey, KeyboardKey downKey);

  void update() override;
};
