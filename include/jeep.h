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
  Jeep(int id, int team_id, const Point2D& position, double orientation, double mass)
    : MovingUnit<Ring>(id, team_id)
  {
    const double length = 4.0;
    const double width = 2.0;

    // set mass
    SetMass(mass);
    
    // set geometry, position and orientation
    Ring geometry = make_rectangle(length, width);

    SetGeometry(geometry);

    SetPositionAndOrientation(position, orientation);

    // add sensors
    for (int degree = -40; degree <= 40; degree += 10)
    {
      AddSensor(10, static_cast<double>(degree));
    }
  }

private:

private:
};


}

#endif //CFT_JEEP_H
