#ifndef CFT_MOVING_UNIT_H
#define CFT_MOVING_UNIT_H 1

#include <vector>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/segment.hpp>


#include "unit.h"
#include "sensor.h"

namespace cft
{

template <typename Geometry>
class MovingUnit : public Unit<Geometry>
{
public:
  typedef boost::geometry::model::segment<boost::geometry::model::d2::point_xy<double> > Segment;
  typedef Sensor<Segment> SensorSegment;

  MovingUnit(int id, int team_id, const Geometry& geometry, double mass) : Unit<Geometry>(id, team_id, geometry, mass) { }

private:

private:
  std::vector<SensorSegment> sensors_;
};


}

#endif //CFT_MOVING_UNIT_H
