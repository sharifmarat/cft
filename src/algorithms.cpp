#include "algorithms.h"

#include <boost/geometry/strategies/transform.hpp>
#include <boost/geometry/strategies/transform/matrix_transformers.hpp>
#include <boost/geometry/algorithms/transform.hpp>

namespace cft
{


Vector2D normalize(const Vector2D& to_normalize)
{
  double len = sqrt(to_normalize.x() * to_normalize.x() + to_normalize.y() * to_normalize.y());
  return (len > 1.0E-10) ? Vector2D(to_normalize.x() / len, to_normalize.y() / len) : Vector2D(1.0, 0.0);
}


Ring make_rectangle(double length, double width)
{
  Ring rectangle;
  boost::geometry::append(rectangle, Vector2D(length / 2., width / 2.));
  boost::geometry::append(rectangle, Vector2D(length / 2., -width / 2.));
  boost::geometry::append(rectangle, Vector2D(-length / 2., -width / 2.));
  boost::geometry::append(rectangle, Vector2D(-length / 2., width / 2.));

  return rectangle;
}

Vector2D rotate(const Vector2D& to_rotate, double degree)
{
  boost::geometry::strategy::transform::rotate_transformer<Vector2D, Vector2D, boost::geometry::degree> rotate(degree);
  Vector2D result;
  boost::geometry::transform(to_rotate, result, rotate);
  return result;
}

Ring rotate(const Ring& to_rotate, double degree)
{
  Ring result = to_rotate;
  boost::geometry::for_each_point(result, [degree](Vector2D &point)
      {
        point = rotate(point, degree);
      });
  return result;
}

Vector2D move_and_rotate(const Vector2D& to_move_and_rotate, const Vector2D& move, double degree)
{
  Vector2D result = rotate(to_move_and_rotate, degree);
  boost::geometry::add_point(result, move);
  return result;
}

Ring move_and_rotate(const Ring& to_move_and_rotate, const Vector2D& move, double degree)
{
  Ring result = to_move_and_rotate;
  boost::geometry::for_each_point(result, [&move, degree](Vector2D &point)
      {
        point = move_and_rotate(point, move, degree);
      });
  return result;
}


}
