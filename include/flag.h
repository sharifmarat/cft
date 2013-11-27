#ifndef CFT_FLAH_H
#define CFT_FLAH_H 1

#include <vector>

#include "unit.h"
#include "rectangular.h"

namespace cft
{

class Flag : public Unit<Rectangular>
{
public:
  Flag(int id, int team_id, const Rectangular& form, double mass) : Unit<Rectangular>(id, team_id, form, mass) { }

private:
};


}

#endif //CFT_FLAH_H

