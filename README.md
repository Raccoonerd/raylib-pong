# Pong (C++ & raylib)

A simple implementation of the classic **Pong** game in C++ using [raylib](https://www.raylib.com/).

## 🎮 Features
- **Singleplayer mode** – play against a basic AI opponent.  
- **Multiplayer mode** – two players on one keyboard.  
- Simple **main menu** with options: *Singleplayer*, *Multiplayer*, *Exit*.  
- Score tracking and ball reset after each goal.  

## 🕹️ Controls
### In Menu
- **Arrow Up / Down** – navigate options  
- **Enter** – select option  

### In Game
- **Left paddle (Player 1)**: `W` / `S`  
- **Right paddle (Player 2)**: `↑` / `↓`  

## ⚙️ Requirements
- C++17 or newer  
- [raylib](https://www.raylib.com/) (linked statically or dynamically)  
- [CMake](https://cmake.org/)  
- (optional) [Ninja](https://ninja-build.org/)  

## 🚀 Build & Run
Clone the repository and build the project:  

```bash
git clone https://github.com/Raccoonerd/raylib-pong.git
cd raylib-pong
mkdir build && cd build
cmake .. -G Ninja
ninja
./pong   # or .\pong.exe on Windows

