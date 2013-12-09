#ifndef CFT_ALGORITHMS_H
#define CFT_ALGORITHMS_H

#include <boost/assign.hpp>
#include <boost/geometry/arithmetic/arithmetic.hpp>

#include "types.h"


namespace cft
{


Vector2D normalize(const Vector2D& to_normalize);

Ring make_rectangle(double length, double width);


Vector2D rotate(const Vector2D& to_rotate, double degree);

Ring rotate(const Ring& to_rotate, double degree);

Vector2D move_and_rotate(const Vector2D& to_move_and_rotate, const Vector2D& move, double degree);

Ring move_and_rotate(const Ring& to_move_and_rotate, const Vector2D& move, double degree);

};


#endif //CFT_ALGORITHMS_H

