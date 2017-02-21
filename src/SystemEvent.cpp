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
    }
  }
}
