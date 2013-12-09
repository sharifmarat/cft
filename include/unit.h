#ifndef CFT_UNIT_H
#define CFT_UNIT_H 1

#include <deque>

#include <boost/foreach.hpp>
#include <boost/geometry/algorithms/intersection.hpp>
#include <boost/geometry/algorithms/convert.hpp>
#include <boost/geometry/strategies/transform.hpp>
#include <boost/geometry/strategies/transform/matrix_transformers.hpp>
#include <boost/geometry/algorithms/transform.hpp>

#include "types.h"
#include "algorithms.h"

namespace cft
{

template <typename Geometry>
class Unit
{
public:
  Unit(int id, int team_id) : id_(id), team_id_(team_id), orientation_(0), position_(Vector2D(0, 0)) { }

  virtual ~Unit() {}

  inline int GetId() const { return id_; }

  inline int GetTeamId() const { return team_id_; }

  Ring GetAbsoluteGeometry() const
  {
    return move_and_rotate(geometry_, position_, orientation_);
  }

  template <typename AnotherGeometry>
  bool Intersects(const Unit<AnotherGeometry>& that) const
  {
    std::deque<Polygon> result;
    boost::geometry::intersection(GetAbsoluteGeometry(), that.GetAbsoluteGeometry(), result);
    return !result.empty();
  }

  // returns the whole geometry of object as a collection of rings
  void GetObjectGeometries(std::vector<Ring>& rings) const
  {
    rings.clear();
    // add main geometry
    //boost::geometry::convert(geometry_, main_geometry_ring);
    rings.push_back(GetAbsoluteGeometry());

    // add orientation vector
    Ring orientation_ring;
    boost::geometry::append(orientation_ring, position_);
    boost::geometry::append(orientation_ring, move_and_rotate(Vector2D(1, 0), position_, orientation_));
    rings.push_back(orientation_ring);

    // add sensors
    for (std::vector<Vector2D>::const_iterator sensor_it = sensors_.begin(); sensor_it != sensors_.end(); ++sensor_it)
    {
      Ring sensor_ring;
      boost::geometry::append(sensor_ring, position_);
      boost::geometry::append(sensor_ring, move_and_rotate(*sensor_it, position_, orientation_));
      rings.push_back(sensor_ring);
    }
  }

  virtual void MoveAndRotate(const Vector2D& shift, double degree)
  {
  }

  virtual void Move(const Vector2D& move)
  {
  }

  virtual void Rotate(double degree)
  {
  }


protected:
  void SetMass(double mass) { mass = mass_; }

  void SetGeometry(const Geometry& geometry) { geometry_ = geometry; }

  inline void SetPositionAndOrientation(const Vector2D& position, double orientation) { position_ = position; orientation_ = orientation; }

  inline void SetPosition(const Vector2D& position) { position_ = position; }

  inline void AddSensor(double length, double degree)
  {
    sensors_.push_back(rotate(Vector2D(length, 0), degree));
  }

private:


protected:
  Vector2D position_;
  double orientation_;
private:
  int id_;
  int team_id_;
  double mass_;
  std::vector<Vector2D> sensors_;
  Geometry geometry_;
};


}

#endif //CFT_UNIT_H
