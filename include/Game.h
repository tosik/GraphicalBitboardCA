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
  bool _isMouseDown;

  std::unique_ptr<IRule> _rule;
  std::unique_ptr<BCA::IBasicBitboardCA> _ca;
  std::vector<Color> _colorScheme;

  void Update();
  void Render();
  void OnQuit();
  void OnMouseButtonDown(const SDL_MouseButtonEvent button) ;
  void OnMouseButtonUp(const SDL_MouseButtonEvent button) ;
  void OnMouseMotion(const SDL_MouseMotionEvent motion);
  Color GetColor(int state);

public:
  Renderer _renderer;
  void Initialize();
  void MainLoop();

  Game(std::unique_ptr<IRule> rule);

  const static int CELL_SIZE = 2;
};
