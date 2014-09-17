#include "GraphicsEngine.h"
#include "GameActor.h"

namespace engine
{
   GraphicsEngine* GraphicsEngine::CreateGraphicsEngine(){
        //if(pomme_graphEngine==NULL){
            return new GraphicsEngine();
        //}else{
          //  return pomme_graphEngine;
        //}
    }

  GraphicsEngine::GraphicsEngine()
  {
    window = new sf::RenderWindow(sf::VideoMode(800,600), "the game port : XXXX");
    //pomme_graphEngine = this;
  }

  int GraphicsEngine::update(const TFG::GameActor& bob)
  {
    window->clear();
    // tmp
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    // end tmp
    window->draw(shape);
    window->draw(bob);
    //window->display();
    return 0;
  }
}
