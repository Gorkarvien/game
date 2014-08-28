#include "PhysicsEngine.h"


namespace TFG
{

const float PhysicsEngine::m_pxScale = 50.0f;

PhysicsEngine::PhysicsEngine()
{
	m_gravity.Set(0.0f,10.0f);
	m_world = new b2World(m_gravity);

	m_groundBodyDef.position.Set(0.0f, 22.0f);
	m_groundBody = m_world->CreateBody(&m_groundBodyDef);
	m_groundBox.SetAsBox(50.0f, 10.0f); // Create a ground box that is 100.0f (50.0f *2 ) meters on x axis and 20 meters (10*2) on y axis 
	m_groundBody->CreateFixture(&m_groundBox, 0.0f); //this creates physics properties (density, mass...) of the object, here mass = 0 means not subjected to gravity and use default param for the other stuffs

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
	//b2Vec2 position = m_body->GetPosition();
	//float32 angle = m_body->GetAngle();
	//printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
}

float PhysicsEngine::meterToPx(float _x)
{
	return _x*m_pxScale;
}

float PhysicsEngine::pxToMeter(float _x)
{
	return _x/m_pxScale;
}

b2Body* PhysicsEngine::addToSimulation(const b2BodyDef* _bodyDef)
{
		return m_world->CreateBody(_bodyDef);
}


}