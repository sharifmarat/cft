#ifndef CFT_GAME_H
#define CFT_GAME_H 1

#include <list>
#include <boost/shared_ptr.hpp>

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

  void SelfCheck() const;

private:
  Field<Rectangular> field_;
  std::list<boost::shared_ptr<BaseUnit> > units_;
};


}


#endif //CFT_GAME_H
