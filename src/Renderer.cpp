#include <iostream>
#include <string>
#include <SDL.h>
#include "Renderer.h"

int Renderer::Initialize(std::string title)
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
    return 1;
  }

  SDL_Window *win = SDL_CreateWindow(title.c_str(), 100, 100, 640 * 2, 480 * 2, SDL_WINDOW_SHOWN);
  if (win == nullptr)
  {
    std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  _renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (_renderer == nullptr)
  {
    SDL_DestroyWindow(win);
    std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  return 0;
}

void Renderer::Clear()
{
  SDL_RenderClear(_renderer);
}

void Renderer::Present()
{
  SDL_RenderPresent(_renderer);
}

void Renderer::SetColor(Color color)
{
  SDL_SetRenderDrawColor(_renderer, color.R, color.G, color.B, color.A);
}

void Renderer::DrawPoint(int x, int y)
{
  SDL_RenderDrawPoint(_renderer, x, y);
}

void Renderer::DrawRectangle(int x, int y, int width, int height)
{
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = width;
  rect.h = height;
  SDL_RenderFillRect(_renderer, &rect);
}

