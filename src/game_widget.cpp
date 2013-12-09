#ifdef QT_CORE_LIB

#include "game_widget.h"

#include <boost/assign.hpp>
#include <boost/geometry/geometry.hpp> 
#include <boost/geometry/geometries/register/point.hpp>
#include <boost/geometry/geometries/register/ring.hpp>

#include "types.h"
#include "game.h"

// Adapt a QPointF such that it can be handled by Boost.Geometry
BOOST_GEOMETRY_REGISTER_POINT_2D_GET_SET(QPointF, double, cs::cartesian, x, y, setX, setY)

// Adapt a QPolygonF as well. 
// A QPolygonF has no holes (interiors) so it is similar to a Boost.Geometry ring
BOOST_GEOMETRY_REGISTER_RING(QPolygonF) 

namespace cft
{

typedef boost::geometry::strategy::transform::map_transformer
  < 
    Point2D, QPointF, 
    true, true 
  > MapTransformerType;


void GameWidget::paintEvent(QPaintEvent*) 
{ 
  MapTransformerType transformer(game_.GetField().GetGeometry(), this->width(), this->height()); 

  QPainter painter(this); 
  painter.setBrush(Qt::green); 

  const Game::UnitsContainer& units = game_.GetUnits();

  for (Game::UnitsContainer::const_iterator it = units.begin(); it != units.end(); ++it)
  {
    std::vector<Ring> geometries;
    (*it)->GetObjectGeometries(geometries);
    for (std::vector<Ring>::const_iterator geo_it = geometries.begin(); geo_it != geometries.end(); ++geo_it)
    {
      const Ring& geometry = *geo_it;
      //std::cout << "drawing object with id = " << (*it)->GetId() << ", geometry size = " << geometry.size() << "\n";
      QPolygonF qring; 
      boost::geometry::transform(geometry, qring, transformer); 
      painter.drawPolygon(qring); 
    }
  }
}


}

#endif
