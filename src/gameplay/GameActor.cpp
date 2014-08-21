#include "GameActor.h"


namespace TFG
{
	GameActor::GameActor():
	m_moveUp	(false),
	m_moveDown	(false),
	m_moveLeft	(false),
	m_moveRight	(false),
	m_speed	(25)//px/s ?
	{
		gablou = new sf::RectangleShape(sf::Vector2f(50.f,50.f));
		dynamic_cast<sf::RectangleShape*>(gablou)->setFillColor(sf::Color::Red);
		dynamic_cast<sf::RectangleShape*>(gablou)->setPosition(75.f,75.f);
	}

	void GameActor::update(sf::Time _elasped_time)
	{
		sf::RectangleShape* gab=dynamic_cast<sf::RectangleShape*>(gablou);
		float offsetX=0,offsetY=0;
		if(m_moveUp){
			offsetY-=m_speed*_elasped_time.asSeconds();
		}
		if(m_moveDown){
			offsetY+=m_speed*_elasped_time.asSeconds();
		}
		if(m_moveLeft){
			offsetX-=m_speed*_elasped_time.asSeconds();
		}
		if(m_moveRight){
			offsetX+=m_speed*_elasped_time.asSeconds();
		}
		gab->move(offsetX, offsetY);

	}

	GameActor::~GameActor()
	{
		delete gablou;
	}
	
}