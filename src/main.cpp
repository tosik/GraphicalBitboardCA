#include <iostream>
#include <string>
#include <SDL.h>
#include "Game.h"
#include "Rules/Starwars.h"
#include "Rules/Wireworld.h"

int main(int argc, char **argv)
{
  SDL_Delay(1000);

  // rules
  std::unique_ptr<IRule> starwars(new Starwars);
  std::unique_ptr<IRule> wireworld(new Wireworld);

  Game game(std::move(starwars));
  //Game game(wireworld);

  game.Initialize();
  game.MainLoop();

  SDL_Quit();
  return 0;
}
