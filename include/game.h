#ifndef CFT_GAME_H
#define CFT_GAME_H 1

#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/variant.hpp>

#include "config.h"
#include "game_config.h"
#include "types.h"
#include "field.h"
#include "unit.h"


namespace cft
{

class CFT_LIB_DECLSPEC Game
{
public:
  typedef std::list<boost::shared_ptr<Unit<Ring> > > UnitsContainer;

  Game();

  void CreateGame(const GameConfig& game_config);

  const Field<Box>& GetField() const { return field_; }

  const UnitsContainer& GetUnits() const { return units_; }

private:
  void SelfCheck() const;

private:
  Field<Box> field_;
  UnitsContainer units_;
};


}


#endif //CFT_GAME_H
