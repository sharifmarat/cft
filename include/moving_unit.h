#ifndef CFT_MOVING_UNIT_H
#define CFT_MOVING_UNIT_H 1

#include <vector>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/segment.hpp>

#include "unit.h"

namespace cft
{

template <typename Geometry>
class MovingUnit : public Unit<Geometry>
{
public:
  MovingUnit(int id, int team_id) : Unit<Geometry>(id, team_id) { }

  virtual void MoveAndRotate(const Vector2D& shift, double degree)
  {
    Move(shift);
    Rotate(degree);
  }

  virtual void Move(const Vector2D& move)
  {
    boost::geometry::add_point(Unit<Geometry>::position_, move);
  }

  virtual void Rotate(double degree)
  {
    Unit<Geometry>::orientation_ = fmod(degree + Unit<Geometry>::orientation_, 360);
  }

protected:
  using Unit<Geometry>::SetGeometry;
  using Unit<Geometry>::SetMass;
  using Unit<Geometry>::SetPositionAndOrientation;
  using Unit<Geometry>::AddSensor;

private:

private:
};


}

#endif //CFT_MOVING_UNIT_H
