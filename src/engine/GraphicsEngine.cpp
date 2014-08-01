#include "GraphicsEngine.h"

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

  int GraphicsEngine::update()
  {
    window->clear();
    // tmp
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::RectangleShape bob(sf::Vector2f(50.f,50.f));
    bob.setFillColor(sf::Color::Red);
    bob.setPosition(75.f,75.f);
    // end tmp
    window->draw(shape);
    window->draw(bob);
    window->display();
    return 0;
  }
}
