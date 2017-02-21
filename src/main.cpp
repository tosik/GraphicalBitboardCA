#include <iostream>
#include <string>
#include <SDL.h>
#include "Game.h"

int main(int argc, char **argv)
{
  SDL_Delay(1000);

  Game game;
  game.Initialize();
  game.MainLoop();

  SDL_Quit();
  return 0;
}
