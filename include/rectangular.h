#ifndef CFT_RECTANGULAR_H
#define CFT_RECTANGULAR_H 1

#include "vector2d.h"


namespace cft
{

struct Rectangular
{
  Rectangular() { }
  Rectangular(double width, double length) : width(width), length(length) { }

  double width;
  double length;
};


}

#endif //CFT_RECTANGULAR_H

