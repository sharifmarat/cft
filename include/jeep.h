#ifndef CFT_JEEP_H
#define CFT_JEEP_H 1

#include "moving_unit.h"
#include "types.h"


namespace cft
{

class Jeep : public MovingUnit<Ring>
{
public:
  Jeep(int id, int team_id, const Ring &ring, double mass) : MovingUnit<Ring>(id, team_id, ring, mass) { }

private:

private:
};


}

#endif //CFT_JEEP_H
