#include "InputHandler.h"
#include "Game.h"
bool InputHandler::initializeJoysticks(){
	std::cout<<"asdsd";
	if(SDL_WasInit(SDL_INIT_JOYSTICK)==0){
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}
	int numOfJoysticks=SDL_NumJoysticks();
	int i=0;
	while(numOfJoysticks>i){
		SDL_Joystick* joy= SDL_JoystickOpen(i);
		if(joy){
			m_joysticks.push_back(joy);	     
            m_joystickValues.push_back(std::make_pair(new Vector2D(0,0),new Vector2D(0,0)));
            std::vector<bool> tempButtons;
            for(int j = 0; j <  SDL_JoystickNumButtons(joy); j++){
                tempButtons.push_back(false);
            }
            m_buttonStates.push_back(tempButtons);
		}
		else{
			std::cout<<SDL_GetError();
			m_bJoysticksIntialized=false;
			return false;
		}
		i++;
	}
	m_bJoysticksIntialized=true;
	std::cout<<"Initialized"<<m_joysticks.size()<<"joystick(s)";
	return true;
}
void InputHandler::clean(){
	if(m_bJoysticksIntialized){
		for(unsigned int i = 0; i < SDL_NumJoysticks(); i++){
			SDL_JoystickClose(m_joysticks[i]);
		}
	}
}
void InputHandler::update(){
	m_keystates = SDL_GetKeyboardState(0);
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
		TheGame::Instance()->quit();
		}
		if(event.type == SDL_JOYAXISMOTION){
			int whichOne = event.jaxis.which;
			if(event.jaxis.axis == 0){
				if (event.jaxis.value > m_joystickDeadZone){
					m_joystickValues[whichOne].first->setX(1);
				}
				else if(event.jaxis.value < -m_joystickDeadZone){
					m_joystickValues[whichOne].first->setX(-1);
				}
				else{
					m_joystickValues[whichOne].first->setX(0);
				}
			}
			if(event.jaxis.axis == 1){
				if (event.jaxis.value > m_joystickDeadZone){
					m_joystickValues[whichOne].first->setY(1);
				}
				else if(event.jaxis.value < -m_joystickDeadZone){
					m_joystickValues[whichOne].first->setY(-1);
				}
				else{
					m_joystickValues[whichOne].first->setY(0);
				}
			}
			if(event.jaxis.axis == 3){
				if (event.jaxis.value > m_joystickDeadZone){
					m_joystickValues[whichOne].second->setX(1);
				}
				else if(event.jaxis.value < -m_joystickDeadZone){
					m_joystickValues[whichOne].second->setX(-1);
				}
			}
		}
		if(event.type == SDL_JOYBUTTONDOWN){
			int whichOne = event.jaxis.which;
			m_buttonStates[whichOne][event.jbutton.button] = true;
		}
		if(event.type == SDL_JOYBUTTONUP){
			int whichOne = event.jaxis.which;
			m_buttonStates[whichOne][event.jbutton.button] = false;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN){
			if(event.button.button == SDL_BUTTON_LEFT){
				m_mouseButtonStates[LEFT] = true;
			}
			if(event.button.button == SDL_BUTTON_MIDDLE){
				m_mouseButtonStates[MIDDLE] = true;
			}
			if(event.button.button == SDL_BUTTON_RIGHT){
				m_mouseButtonStates[RIGHT] = true;
			}
		}
		if(event.type == SDL_MOUSEBUTTONUP){
			if(event.button.button == SDL_BUTTON_LEFT){
				m_mouseButtonStates[LEFT] = false;
			}
			if(event.button.button == SDL_BUTTON_MIDDLE){
				m_mouseButtonStates[MIDDLE] = false;
			}
			if(event.button.button == SDL_BUTTON_RIGHT){
				m_mouseButtonStates[RIGHT] = false;
			}
		}
		if(event.type == SDL_MOUSEMOTION){
			/* these lines causes the error*/
			m_mousePosition->setX(event.motion.x);
			m_mousePosition->setY(event.motion.y);
		}
	}
}
int InputHandler::xvalue(int joy,int stick){
	if(m_joysticks.size()<(joy+1))
		return 0;
	if(stick==1){
		return m_joystickValues[joy].first->getX();
	}
	if(stick==2){
		return m_joystickValues[joy].second->getX();
	}
	return 0;
}

int InputHandler::yvalue(int joy,int stick){
	if(m_joysticks.size()<(joy+1))
		return 0;
	if(stick==1){
		return m_joystickValues[joy].first->getY();
	}
	if(stick==2){
		return m_joystickValues[joy].second->getY();
	}
	return 0;
}
bool InputHandler::getButtonState(int joy, int buttonNumber){
	if(m_joysticks.size()<(joy+1))
		return false;
	return m_buttonStates[joy][buttonNumber];
}
bool InputHandler::isKeyDown(SDL_Scancode key){
	if(m_keystates != 0){
		if(m_keystates[key] == 1){
			return true;
		}
		else{
			return false;
		}
	}
return false;
}
InputHandler::InputHandler(){
	for(int i = 0; i < 3; i++){
		m_mouseButtonStates.push_back(false);
	}
	m_mousePosition=new Vector2D();
};
void InputHandler::reset(){
    m_mouseButtonStates[LEFT] = false;
    m_mouseButtonStates[RIGHT] = false;
    m_mouseButtonStates[MIDDLE] = false;
}
InputHandler* InputHandler::s_pInstance=0;