#include "SystemEvent.h"
#include "Renderer.h"
#include "GenerationOuterTotalisticCA.h"
#include "CellularAutomataRules.h"
#include "Rules/IRule.h"
#include <memory>

namespace BCA = BitboardCA;

class Game : SystemEvent
{
private:
  bool _quit;
  std::unique_ptr<IRule> _rule;
  std::unique_ptr<BCA::IBasicBitboardCA> _ca;
  std::vector<Color> _colorScheme;

  void Update();
  void Render();
  void OnQuit();
  Color GetColor(int state);

public:
  Renderer _renderer;
  void Initialize();
  void MainLoop();

  Game(std::unique_ptr<IRule> rule);

  const static int CELL_SIZE = 2;
};
