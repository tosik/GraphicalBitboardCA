#include "Game.h"
#include "Bresenham.h"

Game::Game(std::unique_ptr<IRule> rule)
    : _quit(false)
    , _rule(std::move(rule))
    , _ca(std::move(_rule->CreateCA()))
    , _colorScheme(std::move(_rule->GetColorScheme()))
    , _lastDrawnLineEnd(Position(0, 0))
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

    for (unsigned int y = 0; y < _ca->GetSizeY(); y++)
    {
        for (unsigned int x = 0; x < _ca->GetSizeX(); x++)
        {
            int state = _ca->GetCellState(x, y);
            _renderer.SetColor(GetColor(state));
            //_renderer.DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE);
            _renderer.DrawPoint(x, y);
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
    _lastDrawnLineEnd = Position(button.x / CELL_SIZE, button.y / CELL_SIZE);
    _ca->SetCellState(_lastDrawnLineEnd.X, _lastDrawnLineEnd.Y, 3);
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
        auto pos = Position(motion.x / CELL_SIZE, motion.y / CELL_SIZE);
        auto line = Bresenham::GetPoints(_lastDrawnLineEnd.X, _lastDrawnLineEnd.Y, pos.X, pos.Y);
        _lastDrawnLineEnd = pos;

        for (auto pos : line)
        {
            _ca->SetCellState(pos.X, pos.Y, 3);
        }
    }
}

Color Game::GetColor(int state)
{
    return _colorScheme[state];
}
