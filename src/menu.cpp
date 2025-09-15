#include "../include/menu.h"
#include <raylib.h>

Menu::Menu()
  :m_options({"Singleplayer", "Multiplayer", "Exit"}),
  m_selectedIndex(0){}

void Menu::update(){
  if (IsKeyPressed(KEY_UP)) {
    if (m_selectedIndex == 0) {
      m_selectedIndex = 0;
    } else {
      m_selectedIndex--;
    }
  }

  if (IsKeyPressed(KEY_DOWN)) {
    if (m_selectedIndex == 2) {
      m_selectedIndex = 2;
    } else {
      m_selectedIndex++;
    }
  }

}

void Menu::render() const {
    int screenWidth  = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    int fontSize = 40;
    int spacing = 60;

    int startY = (screenHeight / 2) - ((static_cast<int>(m_options.size()) * spacing) / 2);

    for (int i = 0; i < (int)m_options.size(); i++) {
        Color color = (i == m_selectedIndex) ? YELLOW : RAYWHITE;

        int textWidth = MeasureText(m_options[i].c_str(), fontSize);
        int posX = (screenWidth / 2) - (textWidth / 2);
        int posY = startY + (i * spacing);

        DrawText(m_options[i].c_str(), posX, posY, fontSize, color);
    }
}

auto Menu::getSelectedIndex() const -> int {
  return m_selectedIndex;
}
