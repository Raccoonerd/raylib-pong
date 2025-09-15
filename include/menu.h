#pragma once
#include <string>
#include <vector>

class Menu{
private:
  std::vector<std::string> m_options;
  int m_selectedIndex;

public:
  Menu();

  void update();
  void render() const;

  [[nodiscard]] auto getSelectedIndex() const -> int;
};
