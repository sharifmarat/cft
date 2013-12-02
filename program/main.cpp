#include <boost/thread.hpp>
#include <boost/function.hpp>

#include <qapplication.h>
#include <qpushbutton.h>

#include "game.h"
#include "game_widget.h"
#include "game_config.h"

#include "intersection_exception.h"
#include "within_exception.h"

class GameProcessing
{
public:
  GameProcessing(const boost::function<void(void)>& callback) : callback_(callback) { }

  void operator()()
  {
    while (true)
    {
      std::cout << "calling callback\n";
      callback_();
      boost::posix_time::seconds workTime(3);
      boost::this_thread::sleep(workTime);
    }
  }
private:
  boost::function<void(void)> callback_;
};

int main(int argc, char** argv)
{
  try
  {
    // create game
    cft::GameConfig game_config;
    cft::Game game;
    game.CreateGame(game_config);

    // create QT application
    QApplication app(argc, argv);
    cft::GameWidget game_widget(game);

    // create game processing object and thread
    auto callback = [&game_widget]() { game_widget.GameUpdated(); };
    GameProcessing game_processing(callback);
    boost::thread game_thread(game_processing);

    // run qt application
    game_widget.show();
    app.exec();

    // wait for thread
    game_thread.join();

    return 0;
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
