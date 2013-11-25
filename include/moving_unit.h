#ifndef CFT_MOVING_UNIT_H
#define CFT_MOVING_UNIT_H 1

#include <vector>

#include "unit.h"
#include "line.h"
#include "sensor.h"

namespace cft
{

template <typename Form>
class MovingUnit : Unit<Form>
{
public:
  typedef Sensor<Line> SensorLine;

private:

private:
  std::vector<SensorLine> sensors_;
};


}

#endif //CFT_MOVING_UNIT_H
