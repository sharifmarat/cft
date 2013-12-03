#ifndef CFT_ALGORITHMS_H
#define CFT_ALGORITHMS_H

#include <boost/assign.hpp>
#include <boost/geometry/arithmetic/arithmetic.hpp>

#include "types.h"


namespace cft
{


Vector2D normalize(const Vector2D& to_normalize);

Ring make_rectangle(const Vector2D& center, const Vector2D& orientation, double length, double width);

Ring make_rectangle(const Vector2D& center, double length, double width);

Vector2D rotate(const Vector2D& to_rotate, double degree);

};


#endif //CFT_ALGORITHMS_H

