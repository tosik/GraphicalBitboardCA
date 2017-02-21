#include <SDL.h>

class SystemEvent
{
private:
  SDL_Event Event;

protected:
  void PollEvent();

  virtual void OnQuit() = 0;
};
