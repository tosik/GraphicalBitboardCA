#include "SystemEvent.h"
#include "Renderer.h"
#include "GenerationOuterTotalisticCA.h"
#include "CellularAutomataRules.h"
#include <memory>

namespace BCA = BitboardCA;

class Game : SystemEvent
{
private:
  bool _quit;
  std::unique_ptr<BCA::GenerationOuterTotalisticCA> _pCA;
  std::shared_ptr<InnerCAForStarwars> _pStarwars;
  //std::unique_ptr<WireworldCA> _pCA;

#define _GAME_COL Color(0, 0, 0, 0)
  Color _colorScheme[16] = {
    _GAME_COL,_GAME_COL,_GAME_COL,_GAME_COL,
    _GAME_COL,_GAME_COL,_GAME_COL,_GAME_COL,
    _GAME_COL,_GAME_COL,_GAME_COL,_GAME_COL,
    _GAME_COL,_GAME_COL,_GAME_COL,_GAME_COL};
#undef _GAME_COL

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

  const static int CELL_SIZE = 2;
};
