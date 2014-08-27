#pragma once
#include <Box2D/Box2D.h>
class PhysicEngine
{
public:
	PhysicEngine();
	~PhysicEngine();
	void simulateWorld();

private:
	//world
	b2Vec2 m_gravity; 
	b2World* m_world; 


	// ground 
	b2BodyDef m_groundBodyDef;
	b2Body* m_groundBody; 
	b2PolygonShape m_groundBox;

	// Box
	b2BodyDef m_bodyDef;
	b2Body* m_body;
	b2PolygonShape m_dynamicBox;
	b2FixtureDef m_fixtureDef;

	float32 m_timeStep; // just for tests
	int32 m_velocityIterations;
	int32 m_positionIterations;
		

};

