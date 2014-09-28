#ifndef _MENUSTATE_
#define _MENUSTATE_
#include "GameState.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "GameObject.h"
#include "Game.h"
class MenuState:public GameState{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID();

private:
		
	std::vector<GameObject*> m_gameObjects;
	const static std::string s_menuID;
	static void s_menuToPlay();
	static void s_exitFromMenu();
};
#endif