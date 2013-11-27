#ifndef CFT_MOVING_UNIT_H
#define CFT_MOVING_UNIT_H 1

#include <vector>

#include "unit.h"
#include "line.h"
#include "sensor.h"

namespace cft
{

template <typename Form>
class MovingUnit : public Unit<Form>
{
public:
  typedef Sensor<Line> SensorLine;

  MovingUnit(int id, int team_id, const Form& form, double mass) : Unit<Form>(id, team_id, form, mass) { }

private:

private:
  std::vector<SensorLine> sensors_;
};


}

#endif //CFT_MOVING_UNIT_H
