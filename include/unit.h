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
  Unit(int id, int team_id, const Form& form, double mass) : BaseUnit(id, team_id), geometry_(form), mass_(mass) { }

  inline void SetPosition(const Vector2D& position) { geometry_.SetPosition(position); }

  inline void SetOrientation(double orientation) { geometry_.SetOrientation(orientation); }

  inline void SetPositionAndOrientation(const Vector2D& position, double orientation) { geometry_.SetPosition(position); geometry_.SetOrientation(orientation); }

private:


private:
  GeometryAndOrientation<Form> geometry_;
  double mass_;
};


}

#endif //CFT_UNIT_H
