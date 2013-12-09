#include "game.h"

#include <boost/assign.hpp>
#include <boost/foreach.hpp>
#include <boost/geometry.hpp>
#include <boost/fusion/iterator/next.hpp>

#include "jeep.h"
#include "flag.h"
#include "intersection_exception.h"
#include "within_exception.h"

namespace cft
{

Game::Game()
{
}

void Game::CreateGame(const GameConfig& game_config)
{
  //field_.SetGeometry(Box(Point2D(0, 0), Point2D(1e3, 1e3)));
  field_.SetGeometry(Box(Point2D(0, 0), Point2D(50, 50)));

  // create jeeps
  double jeep_mass = 1e3;
  boost::shared_ptr<Jeep> jeep1(new Jeep(1, 1, Point2D(10, 10), 13, jeep_mass));
  units_.push_back(jeep1);

  Ring jeep_geometry2;
  boost::shared_ptr<Jeep> jeep2(new Jeep(2, 2, Point2D(30, 30), 116, jeep_mass));
  units_.push_back(jeep2);

  // create flags
  double flag_mass = 10;

  boost::shared_ptr<Flag> flag1(new Flag(3, 1, Point2D(2, 25), flag_mass));
  units_.push_back(flag1);

  boost::shared_ptr<Flag> flag2(new Flag(4, 2, Point2D(48, 25), flag_mass));
  units_.push_back(flag2);

  SelfCheck();
}

void Game::SelfCheck() const
{
  for (UnitsContainer::const_iterator it1 = units_.begin(); it1 != units_.end(); ++it1)
  {
    // check no intersections between objects
    for (UnitsContainer::const_iterator it2 = boost::next(it1); it2 != units_.end(); ++it2)
    {
      //std::cout << (*it1)->GetId() << " " << (*it2)->GetId() << "\n";
      if ((*it1)->Intersects(*(*it2))) throw IntersectionException();
    }

    // check all objects are inside the field
    if (!field_.Within(**it1)) throw WithinException();
  }
}

bool Game::MakeMove(double deltaT)
{
  BOOST_FOREACH (boost::shared_ptr<Unit<Ring> >& unit, units_)
  {
    unit->MoveAndRotate(Vector2D(1, 0), 0);
  }
}


}
