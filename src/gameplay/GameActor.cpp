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
		m_shape = new sf::RectangleShape(sf::Vector2f(50.f,50.f));
		dynamic_cast<sf::RectangleShape*>(m_shape)->setFillColor(sf::Color::Red);
		dynamic_cast<sf::RectangleShape*>(m_shape)->setPosition(75.f,75.f);
	}

	void GameActor::update(int _elasped_time)
	{
		float offsetX=0,offsetY=0;
		if(m_moveUp){
			offsetY-=m_speed*_elasped_time/1000;
		}
		if(m_moveDown){
			offsetY+=m_speed*_elasped_time/1000;
		}
		if(m_moveLeft){
			offsetX-=m_speed*_elasped_time/1000;
		}
		if(m_moveRight){
			offsetX+=m_speed*_elasped_time/1000;
		}
		dynamic_cast<sf::RectangleShape*>(m_shape)->move(offsetX, offsetY);

	}

	void GameActor::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(*m_shape, states);
	}


	GameActor::~GameActor()
	{
		delete m_shape;
	}
	
}