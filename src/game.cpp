#include "game.h"

#include "jeep.h"
#include "flag.h"

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
  
  // create jeeps
  Rectangular jeep_form(2, 3);
  double jeep_mass = 1e3;

  boost::shared_ptr<Jeep> jeep1(new Jeep(1, 1, jeep_form, jeep_mass));
  jeep1->SetPositionAndOrientation(Vector2D(0, 0), 0);
  units_.push_back(jeep1);

  boost::shared_ptr<Jeep> jeep2(new Jeep(2, 2, jeep_form, jeep_mass));
  jeep2->SetPositionAndOrientation(Vector2D(0, 0), 0);
  units_.push_back(jeep2);

  // create flags
  Rectangular flag_form(0.5, 0.5);
  double flag_mass = 10;
  boost::shared_ptr<Flag> flag1(new Flag(3, 1, flag_form, flag_mass));
  flag1->SetPositionAndOrientation(Vector2D(0, 0), 0);
  units_.push_back(flag1);

  boost::shared_ptr<Flag> flag2(new Flag(4, 2, flag_form, flag_mass));
  flag2->SetPositionAndOrientation(Vector2D(0, 0), 0);
  units_.push_back(flag2);

  SelfCheck();
}
  
void Game::SelfCheck() const
{
  // check intersections between objects
  
  // check objects are inside the field
}


}
