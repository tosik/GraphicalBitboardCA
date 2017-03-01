#include "Game.h"

Game::Game(std::unique_ptr<IRule> rule)
    : _quit(false)
    , _rule(std::move(rule))
    , _ca(std::move(_rule->CreateCA()))
    , _colorScheme(std::move(_rule->GetColorScheme()))
{
}

void Game::Initialize()
{
    _renderer.Initialize("Graphical Bitboard CA");
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
    _ca->Step();
}

void Game::Render()
{
    _renderer.Clear();

    for (int y = 0; y < _ca->GetSizeY(); y++)
    {
        for (int x = 0; x < _ca->GetSizeX(); x++)
        {
            int state = _ca->GetCellState(x, y);
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

void Game::OnMouseButtonDown(const SDL_MouseButtonEvent button)
{
    _ca->SetCellState(button.x / CELL_SIZE, button.y / CELL_SIZE, 3);
    _isMouseDown = true;
}

void Game::OnMouseButtonUp(const SDL_MouseButtonEvent button)
{
    _isMouseDown = false;
}

void Game::OnMouseMotion(const SDL_MouseMotionEvent motion)
{
    if (_isMouseDown)
    {
        _ca->SetCellState(motion.x / CELL_SIZE, motion.y / CELL_SIZE, 3);
    }
}

Color Game::GetColor(int state)
{
    return _colorScheme[state];
}
