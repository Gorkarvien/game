#ifndef GAME_ACTOR_H
#define GAME_ACTOR_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <Box2D/Box2D.h>

namespace TFG{

	class PhysicsEngine;

	//a la place d'un element drawable game actor devrai heriter de drawable

	enum ActorState {SLEEP, JUMP};

	class GameActor : public sf::Drawable
	{
		public:
			GameActor(PhysicsEngine&);
			~GameActor();

			void update(int);
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

			void setmoveUp		(bool b){m_moveUp = b;}
			void setmoveDown	(bool b){m_moveDown = b;}
			void setmoveRight	(bool b){m_moveRight = b;}
			void setmoveLeft	(bool b){m_moveLeft = b;}

			sf::Drawable* m_shape;

		protected:

			bool	m_moveUp;
			bool	m_moveDown;
			bool	m_moveLeft;
			bool	m_moveRight;
			float	m_speed;
			ActorState m_state; 

		private:

			b2BodyDef m_bodyDef; // Is copied by box 2D into body so may not need to be a member (argument)
			b2Body* m_body;
			b2PolygonShape m_dynamicBox;
			b2FixtureDef m_fixtureDef;

	};


}

#endif