#ifndef CFT_FLAH_H
#define CFT_FLAH_H 1

#include <vector>

#include "types.h"
#include "unit.h"

namespace cft
{

class Flag : public Unit<Ring>
{
public:
  Flag(int id, int team_id, const Ring& ring, double mass) : Unit<Ring>(id, team_id, ring, mass) { }

private:
};


}

#endif //CFT_FLAH_H

