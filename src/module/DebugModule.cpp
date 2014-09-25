#include <stdio.h>
#include "DebugModule.h"
#include "GraphicsEngine.h"

namespace module
{
    DebugModule::DebugModule(engine::GraphicsEngine* _graphicsEngine):
    m_graphicsEngine(*_graphicsEngine),
    m_fpsTabIndex(0),
    m_averageFps(0.0f)
    {
        for(int i=0;i<m_nbFpsSample;i++)
        {
            m_fpsTab[i]=0;
        }
        m_fpsDisplay.setString("hello");

        std::cout<<"module init"<<std::endl;
        // Declare and load a font
if(!m_font.loadFromFile("F25_Bank_Printer.ttf")){
	std::cout<<"load font failled"<<std::endl;
	exit(666);
}
m_fpsDisplay.setFont(m_font);
// Create a text

m_fpsDisplay.setCharacterSize(14);
//m_fpsDisplay.setColor(sf::Color::Yellow);
m_fpsDisplay.setPosition(20,20);


_graphicsEngine->registerRenderable(*this);
        return;
    }
    int DebugModule::update(sf::Time _timeSinceLastFrame){
        float oldfps=m_fpsTab[m_fpsTabIndex];
        float newFps=1.0f/_timeSinceLastFrame.asSeconds();
		m_fpsTab[m_fpsTabIndex]=newFps;
        m_averageFps=m_averageFps - oldfps + newFps;
        m_fpsTabIndex= ++m_fpsTabIndex % m_nbFpsSample;
		//float fps= m_averageFps/30.0f;
		float fps= newFps;
		if (fps>999){
			fps=999;
		}
		char text[11];
		sprintf(text,"%.2f fps",fps);
		
		m_fpsDisplay.setString(text);

        //m_graphicsEngine.render_window()->draw(m_fpsDisplay);
       // m_graphicsEngine.render_window()->display();

        return 0;
    }

	void DebugModule::callToRender(engine::GraphicsEngine& _graphicsEngine, sf::Time _timeSinceGameUpdate)
	{
		_graphicsEngine.addToRenderQueue(m_fpsDisplay,0); 
	}
}
