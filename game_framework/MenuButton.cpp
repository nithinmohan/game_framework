#include "MenuButton.h"
#include "Game.h"
void MenuButton::draw(){
	SDLGameObject::draw();
}
void MenuButton::update(){
	handleInput();
	SDLGameObject::update();
}
void MenuButton::clean(){
	SDLGameObject::clean();
}
MenuButton::MenuButton(const LoaderParams* pParams,void (*callback)()):SDLGameObject(pParams), m_callback(callback),m_bReleased(true){
	m_currentFrame=MOUSE_OUT;
}
void MenuButton::handleInput(){
	Vector2D* pMousePos=TheInputHandler::Instance()->getMousePosition();
	if(pMousePos->getX()>m_position.getX()&&pMousePos->getX()<m_position.getX()+m_width&&pMousePos->getY()>m_position.getY()&&pMousePos->getY()<m_position.getY()+m_height){
		m_currentFrame=MOUSE_OVER;
		if(m_bReleased&&TheInputHandler::Instance()->getMouseButtonState(LEFT)){
			std::cout<<"clicked";
			m_bReleased=false;
			m_callback();
			m_currentFrame=CLICKED;			
		}
		else if(!TheInputHandler::Instance()->getMouseButtonState(LEFT)){
			m_bReleased=true;
			m_currentFrame=MOUSE_OVER;
		}
		else{
			m_currentFrame=MOUSE_OUT;
		}

	}
	else{
		m_currentFrame=MOUSE_OUT;
	}
}