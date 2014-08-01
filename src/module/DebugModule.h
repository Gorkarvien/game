#ifndef DEBUG_MODULE_H
#define DEBUG_MODULE_H

#include <SFML/System.hpp>

namespace module
{
  class DebugModule
  {
  protected:

  public:
    DebugModule();
    ~DebugModule();
    int update(sf::Time);
  };
}
#endif
