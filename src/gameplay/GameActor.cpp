#include "GameActor.h"
#include "PhysicsEngine.h"
#include <iostream>



namespace TFG
{
	GameActor::GameActor(PhysicsEngine& _physicsEngine) :
		m_moveUp(false),
		m_moveDown(false),
		m_moveLeft(false),
		m_moveRight(false),
	m_speed	(25)//px/s ?  if box2d must be in m/s
	{
		m_state = SLEEP;
		m_shape = new sf::RectangleShape(sf::Vector2f(PhysicsEngine::meterToPx(1),PhysicsEngine::meterToPx(1)));
		dynamic_cast<sf::RectangleShape*>(m_shape)->setFillColor(sf::Color::Red);
		dynamic_cast<sf::RectangleShape*>(m_shape)->setPosition(PhysicsEngine::meterToPx(5),PhysicsEngine::meterToPx(4));

		//box2dstuf
		m_bodyDef.type = b2_dynamicBody;  // Will respond to forces and colisions
		m_bodyDef.position.Set(5.0f, 4.0f);  // Caution from the lib doc : "Do not create a body at the origin and then move it. If you create several bodies at the origin, then performance will suffer." 
		m_body = _physicsEngine.addToSimulation(&m_bodyDef);
		m_dynamicBox.SetAsBox(1.0f, 1.0f); // Box of 2m*2m apparently
		//Cannot use default fixture because we are creating a dynamic obj
		m_fixtureDef.shape = &m_dynamicBox;
		m_fixtureDef.density = 1.0f;
		m_fixtureDef.friction = 0.3f;
		m_body->CreateFixture(&m_fixtureDef);

	}

	void GameActor::update(int _elasped_time)
	{
		
		float offsetX=0,offsetY=0;
		if (m_moveUp && m_state != JUMP){
			m_body->ApplyLinearImpulse(b2Vec2(0.0f, -10.0f),m_body->GetWorldCenter(),true);
			m_state = JUMP;
		}
		
		if(m_moveLeft){
			m_body->ApplyForceToCenter(b2Vec2(-50.0f,0.0f),true); 
		}
		
		if(m_moveRight){
			m_body->ApplyForceToCenter(b2Vec2(50.0f, 0.0f), true);
		}
		//dynamic_cast<sf::RectangleShape*>(m_shape)->move(offsetX, offsetY);
		
		b2Vec2 position = m_body->GetPosition();
		dynamic_cast<sf::RectangleShape*>(m_shape)->setPosition(PhysicsEngine::meterToPx(position.x),PhysicsEngine::meterToPx(position.y));
		if (m_body->GetLinearVelocity().y == 0.0f)
			m_state = SLEEP;

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