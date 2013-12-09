#ifndef CFT_FIELD_H
#define CFT_FIELD_H 1

#include <boost/geometry/algorithms/within.hpp> 
#include <boost/geometry/algorithms/for_each.hpp> 

#include "unit.h"

namespace cft
{

template <typename Geometry>
class Field
{
public:
  inline void SetGeometry(const Geometry& geometry) { geometry_ = geometry; }
  inline const Geometry& GetGeometry() const { return geometry_; }

  template <typename UnitGeometry>
  inline bool Within(const Unit<UnitGeometry>& unit) const
  {
    Ring unit_geometry = unit.GetAbsoluteGeometry();
    bool within = true;
    auto is_point_within = [this, &within](const Point2D& point) { within = within && boost::geometry::within(point, geometry_); };
    boost::geometry::for_each_point(unit_geometry, is_point_within);
    return within;
  }

private:

private:
  Geometry geometry_;
};


}

#endif //CFT_FIELD_H

