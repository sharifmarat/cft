#ifndef CFT_GAME_WIDGET_H
#define CFT_GAME_WIDGET_H 1

#include <iostream>

#include <QObject> 
#include <QWidget> 
#include <QPainter> 

namespace cft
{

class Game;

class GameWidget : public QWidget
{ 
  Q_OBJECT
public:
  GameWidget(const Game& game)
    : game_(game)
  { 
    setPalette(QPalette(QColor(200, 250, 250)));
    setAutoFillBackground(true); 
    connect(this, SIGNAL(GameUpdatedSig()), SLOT(Repaint()), Qt::QueuedConnection);
  } 

  void GameUpdated()
  {
    emit GameUpdatedSig();
  }

public slots:
  void Repaint()
  {
    repaint();
  }

signals:
  void GameUpdatedSig();

protected: 
  void paintEvent(QPaintEvent*);

private:
  const Game& game_;
};

}

#endif //CFT_GAME_WIDGET_H

