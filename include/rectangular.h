#ifndef CFT_RECTANGULAR_H
#define CFT_RECTANGULAR_H 1

#include "vector2d.h"


namespace cft
{

struct Rectangular
{
  Rectangular() { }
  Rectangular(double width, double heigiht) : width(width), height(height) { }

  double width;
  double height;
};


}

#endif //CFT_RECTANGULAR_H

