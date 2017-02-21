#include "Color.h"

class Renderer
{
private:
  SDL_Renderer * _renderer;

public:
  int Initialize();
  void SetColor(Color color);
  void DrawPoint(int x, int y);

  void Clear();
  void Present();
};
