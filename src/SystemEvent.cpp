#include "SystemEvent.h"

void SystemEvent::PollEvent()
{
  // process all events in the event queue
  while (SDL_PollEvent(&Event))
  {
    switch (Event.type)
    {
      case SDL_QUIT:
        OnQuit();
        break;
      case SDL_MOUSEBUTTONDOWN:
        OnMouseButtonDown(Event.button);
        break;
      case SDL_MOUSEBUTTONUP:
        OnMouseButtonUp(Event.button);
        break;
      case SDL_MOUSEMOTION:
        OnMouseMotion(Event.motion);
        break;
    }
  }
}
