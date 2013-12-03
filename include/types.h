#ifndef CFT_TYPES_H
#define CFT_TYPES_H 1


#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/box.hpp>
#include <boost/geometry/geometries/ring.hpp>
#include <boost/geometry/geometries/polygon.hpp>


namespace cft
{
typedef boost::geometry::model::d2::point_xy<double> Point2D;
typedef boost::geometry::model::d2::point_xy<double> Vector2D;
typedef boost::geometry::model::box<Point2D> Box;
typedef boost::geometry::model::ring<Point2D> Ring;
typedef boost::geometry::model::polygon<Point2D> Polygon;

}

#endif //CFT_TYPES_H

