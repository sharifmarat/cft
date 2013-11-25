#ifndef CFT_UNIT_H
#define CFT_UNIT_H 1

#include "base_unit.h"
#include "geometry_and_orientation.h"

namespace cft
{

template <typename Form>
class Unit : public BaseUnit
{
public:

private:


private:
  int id_;
  int team_id_;

  GeometryAndOrientation<Form> geometry_;
  double mass_;
};


}

#endif //CFT_UNIT_H
