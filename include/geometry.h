#ifndef CFT_GEOMETRY_H
#define CFT_GEOMETRY_H 1

#include "vector2d.h"


namespace cft
{

template <typename Form>
class Geometry
{
public:
  inline void SetForm(const Form& form) { form_ = form; }

  inline void SetPosition(const Vector2D& poisition) { position_ = poisition; }

private:

private:
  Form form_;
  Vector2D position_;
};


}

#endif //CFT_GEOMETRY_H

