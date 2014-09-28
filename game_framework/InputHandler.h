#ifndef _INPUTHANDLER_
#define _INPUTHANDLER_
#include "SDL.h"
#include <vector>
#include <iostream>
#include "Vector2D.h"
enum mouse_buttons{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};
class InputHandler{
public:
	static InputHandler* Instance(){
		if(s_pInstance==0){
			s_pInstance=new InputHandler();
		}
		return s_pInstance;
	}
	bool initializeJoysticks();
	bool joystickInitialized(){
		return m_bJoysticksIntialized;
	}
	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);
	bool getButtonState(int joy, int buttonNumber);
	void clean();
	void update();
	static const int m_joystickDeadZone = 10000;
	bool getMouseButtonState(int buttonNumber){
		return m_mouseButtonStates[buttonNumber];
	}
	Vector2D* getMousePosition(){
		return m_mousePosition;
	}
	bool isKeyDown(SDL_Scancode key);
	void reset();
private:
	InputHandler();
	~InputHandler(){};
	static InputHandler* s_pInstance;
	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksIntialized;
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	std::vector<std::vector<bool>> m_buttonStates;
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;
	const Uint8* m_keystates;
};
typedef InputHandler TheInputHandler;
#endif