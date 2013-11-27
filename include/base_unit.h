#ifndef CFT_BASE_UNIT_H
#define CFT_BASE_UNIT_H 1

namespace cft
{

class BaseUnit
{
public:
  BaseUnit(int id, int team_id) : id_(id), team_id_(team_id) { }

  inline int GetId() const { return id_; }

  inline int GetTeamId() const { return team_id_; }

private:
  int id_;
  int team_id_;
};


}

#endif //CFT_BASE_UNIT_H

