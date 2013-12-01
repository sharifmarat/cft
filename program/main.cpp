#include <qapplication.h>
#include <qpushbutton.h>

#include "game.h"
#include "game_widget.h"
#include "game_config.h"

#include "intersection_exception.h"
#include "within_exception.h"

int main(int argc, char** argv)
{


  try
  {
    cft::GameConfig game_config;
    cft::Game game;
    game.CreateGame(game_config);

    QApplication app(argc, argv);
    cft::GameWidget game_widget(game);
    game_widget.show();

    return app.exec();
  }
  catch (cft::IntersectionException&)
  {
    std::cerr << "some objects intersect\n";
  }
  catch (cft::WithinException&)
  {
    std::cerr << "some object is outside the field\n";
  }
  catch (std::exception&)
  {
    std::cerr << "std::exception\n";
  }
  catch (...)
  {
    std::cerr << "unkknown exception\n";
  }

  return 1;
}
