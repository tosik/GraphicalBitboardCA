#include <SDL.h>

class SystemEvent
{
private:
  SDL_Event Event;

protected:
  void PollEvent();

  virtual void OnQuit() = 0;
  virtual void OnMouseButtonDown(const SDL_MouseButtonEvent button) = 0;
  virtual void OnMouseButtonUp(const SDL_MouseButtonEvent button) = 0;
  virtual void OnMouseMotion(const SDL_MouseMotionEvent motion) = 0;
};
