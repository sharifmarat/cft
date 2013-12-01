#ifndef CFT_GAME_WIDGET_H
#define CFT_GAME_WIDGET_H 1

#include <iostream>

#include <boost/assign.hpp>
#include <boost/geometry/geometry.hpp> 
#include <boost/geometry/geometries/register/point.hpp>
#include <boost/geometry/geometries/register/ring.hpp>

#include <QObject> 
#include <QWidget> 
#include <QPainter> 

#include "types.h"
#include "game.h"

// Adapt a QPointF such that it can be handled by Boost.Geometry
BOOST_GEOMETRY_REGISTER_POINT_2D_GET_SET(QPointF, double, cs::cartesian, x, y, setX, setY)

// Adapt a QPolygonF as well. 
// A QPolygonF has no holes (interiors) so it is similar to a Boost.Geometry ring
BOOST_GEOMETRY_REGISTER_RING(QPolygonF) 

namespace cft
{

class GameWidget : public QWidget
{ 
public:
  GameWidget(const Game& game)
    : game_(game)
  { 
    setPalette(QPalette(QColor(200, 250, 250)));
    setAutoFillBackground(true); 
    DELME = 1;
  } 

protected: 
  void paintEvent(QPaintEvent*) 
  { 
    MapTransformerType transformer(game_.GetField().GetGeometry(), this->width(), this->height()); 

    QPainter painter(this); 
    painter.setBrush(Qt::green); 

    const Game::UnitsContainer& units = game_.GetUnits();
  
    for (Game::UnitsContainer::const_iterator it = units.begin(); it != units.end(); ++it)
    {
      const Ring& geometry = (*it)->GetGeometry();
      QPolygonF qring; 
      boost::geometry::transform(geometry, qring, transformer); 
      painter.drawPolygon(qring); 
    }

    Ring delme;
    boost::geometry::append(delme, Point2D(DELME, DELME));
    boost::geometry::append(delme, Point2D(DELME, DELME+1));
    boost::geometry::append(delme, Point2D(DELME+1, DELME+1));
    boost::geometry::append(delme, Point2D(DELME+1, DELME));
    QPolygonF qring; 
    boost::geometry::transform(delme, qring, transformer); 
    painter.drawPolygon(qring); 
    DELME = DELME + 1;
  }

private:
  typedef boost::geometry::strategy::transform::map_transformer
    < 
      Point2D, QPointF, 
      true, true 
    > MapTransformerType;
  const Game& game_;
  double DELME;
};

}

#endif //CFT_GAME_WIDGET_H

