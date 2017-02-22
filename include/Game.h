#include "SystemEvent.h"
#include "Renderer.h"
#include "GenerationOuterTotalisticCA.h"
#include "CellularAutomataRules.h"

namespace BCA = BitboardCA;

class Game : SystemEvent
{
private:
  bool _quit;
  //BCA::GenerationOuterTotalisticCA * _pCA;
  //InnerCAForStarwars * _pStarwars;
  WireworldCA * _pCA;

  void Update();
  void Render();
  void OnQuit();
  Color GetColor(int state);

public:
  Renderer _renderer;
  void Initialize();
  void MainLoop();

  Game() : _quit(false) {}
  ~Game();

  const int CELL_SIZE = 2;
};
