#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H
#pragma once
#include <Box2D/Box2D.h>


namespace TFG
{

class PhysicsEngine
{
public:
	PhysicsEngine();
	~PhysicsEngine();
	void simulateWorld();
	b2Body* addToSimulation(const b2BodyDef*);

	static const float m_pxScale;
	static float meterToPx(float);
	static float pxToMeter(float);


private:
	//world
	b2Vec2 m_gravity; 
	b2World* m_world; 


	// ground 
	b2BodyDef m_groundBodyDef;
	b2Body* m_groundBody; 
	b2PolygonShape m_groundBox;

	// Box

	float32 m_timeStep; // just for tests
	int32 m_velocityIterations;
	int32 m_positionIterations;
		

};


}
#endif