#include "game.h"

#include <boost/assign.hpp>
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
  field_.SetGeometry(Box(Point2D(0, 0), Point2D(20, 20)));

  // create jeeps
  double jeep_mass = 1e3;
  Ring jeep_geometry1;
  boost::geometry::append(jeep_geometry1, Point2D(0.1, 0.1));
  boost::geometry::append(jeep_geometry1, Point2D(0.1, 1.1));
  boost::geometry::append(jeep_geometry1, Point2D(1.1, 1.1));
  boost::geometry::append(jeep_geometry1, Point2D(1.1, 0.1));
  boost::shared_ptr<Jeep> jeep1(new Jeep(1, 1, jeep_geometry1, jeep_mass));
  units_.push_back(jeep1);

  Ring jeep_geometry2;
  boost::geometry::append(jeep_geometry2, Point2D(10, 10));
  boost::geometry::append(jeep_geometry2, Point2D(10, 11));
  boost::geometry::append(jeep_geometry2, Point2D(11, 11));
  boost::geometry::append(jeep_geometry2, Point2D(11, 10));
  boost::shared_ptr<Jeep> jeep2(new Jeep(2, 2, jeep_geometry2, jeep_mass));
  units_.push_back(jeep2);

  // create flags
  Ring flag_geometry;
  double flag_mass = 10;
  boost::geometry::append(flag_geometry, Point2D(1.1, 1.1));
  boost::geometry::append(flag_geometry, Point2D(1.1, 1.9));
  boost::geometry::append(flag_geometry, Point2D(1.9, 1.9));
  boost::geometry::append(flag_geometry, Point2D(1.9, 1.1));

  boost::shared_ptr<Flag> flag1(new Flag(3, 1, flag_geometry, flag_mass));
  units_.push_back(flag1);

  //boost::shared_ptr<Flag> flag2(new Flag(4, 2, flag_geometry, flag_mass));
  //units_.push_back(flag2);

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


}
