#pragma once
#include "object.h"

constexpr float BALL_SPEED = 4.0F;

class Ball
  :public Object
{
private:
  float m_radius;

public:
  Ball(Vector2 pos, float radius);

  void update() override;

  void reset();

  [[nodiscard]] auto getRadius() const -> float;

  void invertX();
  void invertY();
};
