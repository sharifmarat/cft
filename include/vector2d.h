#ifndef CFT_VECTOR2D_H
#define CFT_VECTOR2D_H 1

namespace cft
{

struct Vector2D
{
  Vector2D() { }

  Vector2D(double x, double y) : x(x), y(y) { }

  double x;
  double y;
};


}

#endif //CFT_VECTOR2D_H
