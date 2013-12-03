#ifndef CFT_UNIT_H
#define CFT_UNIT_H 1

#include <deque>

#include <boost/geometry/algorithms/intersection.hpp>

#include "types.h"

namespace cft
{

template <typename Geometry>
class Unit
{
public:
  Unit(int id, int team_id) : id_(id), team_id_(team_id) { }

  inline int GetId() const { return id_; }

  inline int GetTeamId() const { return team_id_; }

  const Geometry& GetGeometry() const { return geometry_; }

  template <typename AnotherGeometry>
  bool Intersects(const Unit<AnotherGeometry>& that) const
  {
    std::deque<Polygon> result;
    boost::geometry::intersection(geometry_, that.geometry_, result);
    return !result.empty();
  }

protected:
  void SetMass(double mass) { mass = mass_; }

  void SetGeometry(const Geometry& geometry) { geometry_ = geometry; }

  //inline void SetPosition(const Vector2D& position) { geometry_.SetPosition(position); }

  //inline void SetOrientation(double orientation) { geometry_.SetOrientation(orientation); }

  //inline void SetPositionAndOrientation(const Vector2D& position, double orientation) { geometry_.SetPosition(position); geometry_.SetOrientation(orientation); }

private:


private:
  int id_;
  int team_id_;
  Geometry geometry_;
  double mass_;
};


}

#endif //CFT_UNIT_H
