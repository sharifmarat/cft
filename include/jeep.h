#ifndef CFT_JEEP_H
#define CFT_JEEP_H 1

#include "moving_unit.h"
#include "algorithms.h"
#include "types.h"


namespace cft
{

class Jeep : public MovingUnit<Ring>
{
public:
  Jeep(int id, int team_id, const Point2D& position, const Vector2D& orientation, double mass)
    : MovingUnit<Ring>(id, team_id)
  {
    const double length = 4.0;
    const double width = 2.0;
    
    Ring geometry = make_rectangle(position, orientation, length, width);

    SetGeometry(geometry);

    SetMass(mass);
  }

private:

private:
};


}

#endif //CFT_JEEP_H
