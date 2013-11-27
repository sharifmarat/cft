#ifndef CFT_GEOMETRY_AND_ORIENTATION_H
#define CFT_GEOMETRY_AND_ORIENTATION_H 1

#include "vector2d.h"


namespace cft
{

template <typename Form>
class GeometryAndOrientation
{
public:
  GeometryAndOrientation(const Form& form) : form_(form) { }

  inline void SetPosition(const Vector2D& position) { position_ = position; }

  inline void SetOrientation(double orientation) { orientation_ = orientation; }

private:

private:
  Form form_;
  Vector2D position_;
  double orientation_;  // 0 - x, pi/2 - y
};


}

#endif //CFT_GEOMETRY_AND_ORIENTATION_H

