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
