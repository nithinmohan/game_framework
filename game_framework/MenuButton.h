#ifndef _MENUBUTTON_
#define _MENUBUTTON_
#include "SDLGameObject.h"
#include "InputHandler.h"
enum{
	MOUSE_OUT=0,
	MOUSE_OVER=1,
	CLICKED=2
};
class MenuButton:public SDLGameObject{
public:
	MenuButton(const LoaderParams* pParams, void (*callback)());
	void update();
	void draw();
	void clean();
	void handleInput();
	bool m_bReleased;
	void (*m_callback)();
};
#endif