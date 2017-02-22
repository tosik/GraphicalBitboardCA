#include "Game.h"

void Game::Initialize()
{
  _renderer.Initialize("Graphical Bitboard CA");

  {
    _pCA.reset(new BCA::GenerationOuterTotalisticCA(480, 400, 4));
    _pStarwars.reset(new InnerCAForStarwars(_pCA->GetSizeX(), _pCA->GetSizeY()));
    _pCA->SetInnerCAInstance(_pStarwars.get());
    _pCA->Randomize();

    _colorScheme[0] = Color(0, 0, 0, 255); // space
    _colorScheme[1] = Color(127, 0, 0, 255); // 1
    _colorScheme[2] = Color(255, 0, 0, 255); // 2
    _colorScheme[3] = Color(255, 255, 0, 255); // 3
  }

/*
  {
    _pCA.reset(new WireworldCA(480, 400));
    for (int x = 10; x < 50; x ++)
      _pCA->SetCellState(x, 90, 1);
    for (int y = 0; y < 500; y ++)
      _pCA->SetCellState(49, y, 1);
    _pCA->SetCellState(9, 90, 2);

    _colorScheme[0] = Color(0, 0, 0, 255); // space
    _colorScheme[1] = Color(255, 255, 0, 255); // cable
    _colorScheme[2] = Color(0, 0, 255, 255); // electron head
    _colorScheme[3] = Color(255, 0, 0, 255); // electron tail
  }
  */
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
  return _colorScheme[state];
}

Game::~Game()
{
}