#ifndef CFT_UNIT_H
#define CFT_UNIT_H 1

#include <deque>

#include <boost/geometry/algorithms/intersection.hpp>
#include <boost/geometry/algorithms/convert.hpp>

#include "types.h"
#include "algorithms.h"

namespace cft
{

template <typename Geometry>
class Unit
{
public:
  Unit(int id, int team_id) : id_(id), team_id_(team_id), orientation_(Vector2D(1, 0)), position_(Vector2D(0, 0)) { }

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

  // returns the whole geometry of object as a collection of rings
  void GetObjectGeometries(std::vector<Ring>& rings) const
  {
    rings.clear();
    // add main geometry
    Ring main_geometry_ring;
    boost::geometry::convert(geometry_, main_geometry_ring);
    rings.push_back(main_geometry_ring);

    // add orientation vector
    Ring orientation_ring;
    Point2D orientation_start = position_;
    boost::geometry::append(orientation_ring, orientation_start);
    Point2D orientation_end = position_;
    boost::geometry::add_point(orientation_end, normalize(orientation_));
    boost::geometry::append(orientation_ring, orientation_end);
    rings.push_back(orientation_ring);

    // add sensors
    for (std::vector<Vector2D>::const_iterator sensor_it = sensors_.begin(); sensor_it != sensors_.end(); ++sensor_it)
    {
      Ring sensor_ring;
      Point2D sensor_start = position_;
      boost::geometry::append(sensor_ring, sensor_start);
      Point2D sensor_end = *sensor_it;
      boost::geometry::append(sensor_ring, sensor_end);
      rings.push_back(sensor_ring);
    }
  }

protected:
  void SetMass(double mass) { mass = mass_; }

  void SetGeometry(const Geometry& geometry) { geometry_ = geometry; }

  inline void SetPositionAndOrientation(const Vector2D& position, const Vector2D& orientation) { position_ = position; orientation_ = orientation; }

  inline void SetPosition(const Vector2D& position) { position_ = position; }

  inline void AddSensor(double length, double degree)
  {
    Vector2D sensor_end = position_;
    Vector2D sensor_orientation = normalize(rotate(orientation_, degree));
    boost::geometry::multiply_value(sensor_orientation, length);
    boost::geometry::add_point(sensor_end, sensor_orientation);
    sensors_.push_back(sensor_end);
  }

private:


private:
  int id_;
  int team_id_;
  double mass_;
  std::vector<Vector2D> sensors_;
  Geometry geometry_;
  Vector2D position_;
  Vector2D orientation_;
};


}

#endif //CFT_UNIT_H
