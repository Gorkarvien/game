#ifndef GAME_ACTOR_H
#define GAME_ACTOR_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace TFG{


	//a la place d'un element drawable game actor devrai heriter de drawable

	class GameActor : public sf::Drawable
	{
		public:
			GameActor();
			~GameActor();

			void update(sf::Time);
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

		private:
	};


}

#endif