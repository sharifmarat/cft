#ifndef CFT_GAME_H
#define CFT_GAME_H 1

#include <list>

#include "config.h"
#include "game_config.h"
#include "field.h"
#include "rectangular.h"
#include "base_unit.h"

namespace cft
{

class CFT_LIB_DECLSPEC Game
{
public:
  Game();

  void CreateGame(const GameConfig& game_config);

private:
  Field<Rectangular> field_;
  std::list<BaseUnit> units_;
};


}


#endif //CFT_GAME_H
