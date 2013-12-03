#ifndef CFT_ALGORITHMS_H
#define CFT_ALGORITHMS_H

#include <boost/assign.hpp>
#include <boost/geometry/arithmetic/arithmetic.hpp>

#include "types.h"


namespace cft
{


Vector2D normalize(const Vector2D& to_normalize)
{
  double len = sqrt(to_normalize.x() * to_normalize.x() + to_normalize.y() * to_normalize.y());
  return (len > 1.0E-10) ? Vector2D(to_normalize.x() / len, to_normalize.y() / len) : Vector2D(1.0, 0.0);
}


Ring make_rectangle(const Vector2D& center, const Vector2D& orientation, double length, double width)
{
  Vector2D along_length_1 = normalize(orientation);
  boost::geometry::multiply_value(along_length_1, length / 2.0);

  Vector2D along_length_2 = normalize(orientation);
  boost::geometry::multiply_value(along_length_2, -length / 2.0);

  Vector2D perpendicular_1 = normalize(Vector2D(orientation.y(), -orientation.x()));
  boost::geometry::multiply_value(perpendicular_1, width / 2.0);

  Vector2D perpendicular_2 = normalize(Vector2D(-orientation.y(), orientation.x()));
  boost::geometry::multiply_value(perpendicular_2, width / 2.0);

  Point2D point1 = center;
  boost::geometry::add_point(point1, along_length_1);
  boost::geometry::add_point(point1, perpendicular_1);

  Point2D point2 = center;
  boost::geometry::add_point(point2, along_length_1);
  boost::geometry::add_point(point2, perpendicular_2);

  Point2D point3 = center;
  boost::geometry::add_point(point3, along_length_2);
  boost::geometry::add_point(point3, perpendicular_2);

  Point2D point4 = center;
  boost::geometry::add_point(point4, along_length_2);
  boost::geometry::add_point(point4, perpendicular_1);

  Ring rectangle;
  boost::geometry::append(rectangle, point1);
  boost::geometry::append(rectangle, point2);
  boost::geometry::append(rectangle, point3);
  boost::geometry::append(rectangle, point4);

  return rectangle;
}

Ring make_rectangle(const Vector2D& center, double length, double width)
{
  return make_rectangle(center, Vector2D(1, 0), length, width);
}

};


#endif //CFT_ALGORITHMS_H

