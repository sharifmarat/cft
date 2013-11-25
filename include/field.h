#ifndef CFT_FIELD_H
#define CFT_FIELD_H 1

#include "geometry.h"

namespace cft
{

template <typename Form>
class Field
{
public:
  inline void SetGeometry(const Geometry<Form>& geometry) { geometry_ = geometry; }
  inline const Geometry<Form> GetGeometry() const { return geometry_; }

private:

private:
  Geometry<Form> geometry_;
};


}

#endif //CFT_FIELD_H

