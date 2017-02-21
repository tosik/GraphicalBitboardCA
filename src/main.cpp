#include <iostream>
#include <string>
#include <SDL.h>
#include "Renderer.h"
#include "GenerationOuterTotalisticCa.h"
#include "Color.h"

namespace BCA = BitboardCA;

// your class
// define user rules on like this class.
class InnerCAForStarwars
  : public BCA::OuterTotalisticCA
{
  public:
    InnerCAForStarwars(std::size_t size_x, std::size_t size_y)
      : BCA::OuterTotalisticCA(size_x, size_y)
    {
    }

  protected:
    BCA::Bitboard Rule(
        BCA::Bitboard board,
        BCA::Bitboard s0, BCA::Bitboard s1, BCA::Bitboard s2,
        BCA::Bitboard s3, BCA::Bitboard s4, BCA::Bitboard s5,
        BCA::Bitboard s6, BCA::Bitboard s7, BCA::Bitboard s8 )
    {
      // starwars
      return ( board & ( s3 | s4 | s5 ) ) | ( ~board & s2 );
    }
};

Color GetColor(int state)
{
  switch (state)
  {
    case 0: return Color(0, 0, 0, 255);
    case 1: return Color(255, 0, 0, 255);
    case 2: return Color(255, 0, 0, 255);
    case 3: return Color(255, 255, 0, 255);
  }
  return Color(0, 0, 0, 0);
}

int main(int argc, char **argv)
{
  std::cout << "hello" << std::endl;

  Renderer renderer;
  int result = renderer.Initialize();
  if (result != 0) return result;

  SDL_Delay(1000);

  // create a ca with generation
  BCA::GenerationOuterTotalisticCA ca(480 * 1.3, 400 * 1.4, 4);
  // you need inner ca instance. create and set like below.
  InnerCAForStarwars starwars(ca.GetSizeX(), ca.GetSizeY());
  ca.SetInnerCAInstance(&starwars);

  ca.Randomize();

  bool quit = false;
  bool pressed = false;

  while (!quit)
  {
    ca.Step();

    SDL_Event event;
    SDL_WaitEvent(&event);

    switch (event.type)
    {
      case SDL_QUIT:
        quit = true;

    }

    renderer.Clear();

    for ( int y = 0 ; y < ca.GetSizeY() ; y ++ )
    {
      for ( int x = 0 ; x < ca.GetSizeX() ; x ++ )
      {
        int state = ca.GetCellState(x, y);
        renderer.SetColor(GetColor(state));
        renderer.DrawPoint(x, y);
      }
    }

    renderer.Present();
    SDL_Delay(1);
  }

  SDL_Quit();
  return 0;
}
