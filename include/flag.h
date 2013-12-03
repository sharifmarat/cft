#ifndef CFT_FLAH_H
#define CFT_FLAH_H 1

#include <vector>

#include "types.h"
#include "unit.h"
#include "algorithms.h"

namespace cft
{

class Flag : public Unit<Ring>
{
public:
  Flag(int id, int team_id, const Point2D& position, double mass)
    : Unit<Ring>(id, team_id)
  {
    const double length = 1.0;
    const double width = 1.0;
    
    Ring geometry = make_rectangle(position, length, width);

    SetGeometry(geometry);

    SetMass(mass);
  }

private:
};


}

#endif //CFT_FLAH_H

