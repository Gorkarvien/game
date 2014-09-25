#include "RenderOperation.h"

namespace engine
{

	RenderOperation::RenderOperation(sf::Drawable& _asset, unsigned short int _z):
	m_drawable(&_asset),
	m_z(_z)
	{
	}
}