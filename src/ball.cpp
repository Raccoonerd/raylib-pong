#include "../include/ball.h"
#include <raylib.h>

Ball::Ball(Vector2 pos, float radius)
  :Object(pos, Size{.x=radius*2, .y=radius*2}), m_radius(radius){}

void Ball::update() {
  Object::update();

  auto t_pos = getPosition();

  if (t_pos.y - m_radius < 0) {
    t_pos.y = m_radius;
    setPosition(t_pos);
    invertY();
  }

  if (t_pos.y + m_radius > static_cast<float>(GetScreenHeight())) {
    t_pos.y = static_cast<float>(GetScreenHeight()) - m_radius;
    setPosition(t_pos);
    invertY();
  }
}

void Ball::reset(){
  float t_dirX = (GetRandomValue(0, 1) != 0) ? 1.0F : -1.0F;
  float t_dirY = (GetRandomValue(0, 1) != 0) ? 1.0F : -1.0F;


  setPosition({
    (static_cast<float>(GetScreenWidth())/2) - m_radius,
    (static_cast<float>(GetScreenHeight())/2) - m_radius
  });
  setVelocity({t_dirX * BALL_SPEED, t_dirY * BALL_SPEED});
}

void Ball::invertY(){
  auto t_vel = getVelocity();
  t_vel.y *= -1;
  setVelocity(t_vel);
}

void Ball::invertX(){
  auto t_vel = getVelocity();
  t_vel.x *= -1;
  setVelocity(t_vel);
}

auto Ball::getRadius() const -> float {
  return m_radius;
}
