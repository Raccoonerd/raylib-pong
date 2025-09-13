#pragma once
#include <raylib.h>

struct Size {
  float x;
  float y;
};

class Object{
private:
  Vector2 m_pos;
  Size m_size;
  Vector2 m_velocity;
  Color m_color;
  
  void updatePos();
public:
  // Constructors/Destructors
  Object(Vector2 pos, Size size);
  virtual ~Object() = default;
  Object(const Object &) = default;
  Object(Object &&) = delete;
  auto operator=(const Object &) -> Object & = default;
  auto operator=(Object &&) -> Object & = delete;

  // Getters
  [[nodiscard]] auto getPosition() const -> Vector2;
  [[nodiscard]] auto getSize() const -> Size;
  [[nodiscard]] auto getRectangle() const -> Rectangle;
  [[nodiscard]] auto getColor() const -> Color;

  // Setters
  void setPosition(Vector2 pos);
  void setVelocity(Vector2 velocity);
  void setColor(Color color);

  //Update
  virtual void update();
};
