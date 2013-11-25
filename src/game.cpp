#include "game.h"

namespace cft
{

Game::Game()
{
}

void Game::CreateGame(const GameConfig& game_config)
{
  Geometry<Rectangular> field_geometry;
  field_geometry.SetForm(Rectangular(1e3, 1e3));
  field_geometry.SetPosition(Vector2D(0, 0));
  field_.SetGeometry(field_geometry);

}

}
