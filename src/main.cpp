#include "raylib.h"

auto main () -> int{
  InitWindow(800, 600, "Hello Raylib!");
  SetTargetFPS(60);

  Texture2D hero = LoadTexture("assets/textures/hero.png");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawTextureEx(hero, 
                {static_cast<float>((GetScreenWidth()/2) - (hero.width*2)),
                static_cast<float>((GetScreenWidth()/2) - (hero.width*2))},
                0.0F,
                4.0F,
                WHITE);
    
    DrawText("Hello Raylib!", 10, 10, 20, DARKGRAY);


    EndDrawing();
  }

  UnloadTexture(hero);
  CloseWindow();
  return 0;
}
