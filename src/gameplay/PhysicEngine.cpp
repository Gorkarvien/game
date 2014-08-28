#include "PhysicEngine.h"


namespace TFG
{
PhysicsEngine::PhysicsEngine()
{
	m_gravity.Set(0.0f,-10.0f);
	m_world = new b2World(m_gravity);

	m_groundBodyDef.position.Set(0.0f, -10.0f);
	m_groundBody = m_world->CreateBody(&m_groundBodyDef);
	m_groundBox.SetAsBox(50.0f, 10.0f); // Create a ground box that is 100.0f (50.0f *2 ) meters on x axis and 20 meters (10*2) on y axis 
	m_groundBody->CreateFixture(&m_groundBox, 0.0f); //this creates physics properties (density, mass...) of the object, here mass = 0 means not subjected to gravity and use default param for the other stuffs

	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(0.0f, 4.0f);
	m_body = m_world->CreateBody(&m_bodyDef);
	m_dynamicBox.SetAsBox(1.0f, 1.0f); // Box of 2m*2m apparently
	//Cannot use default fixture because we are creating a dynamic obj
	m_fixtureDef.shape = &m_dynamicBox;
	m_fixtureDef.density = 1.0f;
	m_fixtureDef.friction = 0.3f;
	m_body->CreateFixture(&m_fixtureDef);
	m_timeStep = 1.0f / 60.0f;  // 60hz

	m_velocityIterations = 6;
	m_positionIterations = 2;
}	


PhysicsEngine::~PhysicsEngine()
{
	// need to see if all memory is freed 
	delete m_world;
}

void PhysicsEngine::simulateWorld()
{
	m_world->Step(m_timeStep, m_velocityIterations, m_positionIterations);
	b2Vec2 position = m_body->GetPosition();
	float32 angle = m_body->GetAngle();
	printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
}
}