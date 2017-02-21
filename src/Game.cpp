#include "Game.h"

void Game::Initialize()
{
  _renderer.Initialize();


  _pCA = new BCA::GenerationOuterTotalisticCA(480, 400, 4);
  _pStarwars = new InnerCAForStarwars(_pCA->GetSizeX(), _pCA->GetSizeY());
  _pCA->SetInnerCAInstance(_pStarwars);
//  _pCA = new CodsCA(480, 400, 4);

  _pCA->Randomize();
}

void Game::MainLoop()
{
  while (!_quit)
  {
    PollEvent();
    Update();
    Render();
  }
}

void Game::Update()
{
  _pCA->Step();
  //SDL_Delay(1);
}

void Game::Render()
{
  _renderer.Clear();

  for ( int y = 0 ; y < _pCA->GetSizeY() ; y ++ )
  {
    for ( int x = 0 ; x < _pCA->GetSizeX() ; x ++ )
    {
      int state = _pCA->GetCellState(x, y);
      _renderer.SetColor(GetColor(state));
      _renderer.DrawPoint(x, y);
    }
  }

  _renderer.Present();
}

void Game::OnQuit()
{
  _quit = true;
}

Color Game::GetColor(int state)
{
  switch (state)
  {
    case 0: return Color(0, 0, 0, 255);
    case 1: return Color(255, 0, 0, 255);
    case 2: return Color(255, 0, 0, 255);
    case 3: return Color(255, 255, 0, 255);
  }
  return Color(0, 0, 0, 0);
}

Game::~Game()
{
  delete _pStarwars;
  delete _pCA;
  //delete _pCodd;
}