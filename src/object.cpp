#include "../include/object.h"

Object::Object(Vector2 pos, Size size)
  : m_pos(pos), m_size(size), m_velocity({.x=0,.y=0}), m_color(WHITE){}

void Object::updatePos(){
  m_pos.x += m_velocity.x;
  m_pos.y += m_velocity.y;
}

auto Object::getPosition() const -> Vector2{
  return m_pos;
}

auto Object::getSize() const -> Size{
  return m_size;
}

auto Object::getRectangle() const -> Rectangle{
  return {m_pos.x, m_pos.y, m_size.x, m_size.y};
}

auto Object::getColor() const -> Color{
  return m_color;
}

auto Object::getVelocity() const -> Vector2{
  return m_velocity;
}

void Object::setPosition(Vector2 pos){
  m_pos = pos;
}

void Object::setVelocity(Vector2 velocity){
  m_velocity = velocity;
}

void Object::setColor(Color color){
  m_color = color;
}

 void Object::update(){
  updatePos();
}
