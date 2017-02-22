#include "Game.h"

void Game::Initialize()
{
  _renderer.Initialize();


/*
  _pCA = new BCA::GenerationOuterTotalisticCA(480, 400, 4);
  _pStarwars = new InnerCAForStarwars(_pCA->GetSizeX(), _pCA->GetSizeY());
  _pCA->SetInnerCAInstance(_pStarwars);
  */
  _pCA = new WireworldCA(480, 400);

  for (int x = 10; x < 50; x ++)
    _pCA->SetCellState(x, 90, 1);
  for (int y = 0; y < 500; y ++)
    _pCA->SetCellState(49, y, 1);
  _pCA->SetCellState(9, 90, 2);

  //_pCA->Randomize();
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
      _renderer.DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE);
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
    case 1: return Color(127, 0, 0, 255);
    case 2: return Color(255, 0, 0, 255);
    case 3: return Color(255, 255, 0, 255);
  }
  return Color(0, 0, 0, 0);
}

Game::~Game()
{
  //delete _pStarwars;
  delete _pCA;
}