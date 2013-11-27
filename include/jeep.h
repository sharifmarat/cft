#ifndef CFT_JEEP_H
#define CFT_JEEP_H 1

#include "moving_unit.h"
#include "rectangular.h"


namespace cft
{

class Jeep : public MovingUnit<Rectangular>
{
public:
  Jeep(int id, int team_id, const Rectangular& rectangular, double mass) : MovingUnit<Rectangular>(id, team_id, rectangular, mass) { }

private:

private:
};


}

#endif //CFT_JEEP_H
