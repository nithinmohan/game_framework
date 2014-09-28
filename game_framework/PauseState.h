#ifndef _PAUSESTATE_
#define _PAUSESTATE_
#include "GameState.h"
#include "Player.h"
#include "TextureManager.h"
#include "Game.h"
class PauseState:public GameState{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID();
private:
	std::vector<GameObject*> m_gameObjects;
	const static std::string s_pauseID;
	static void s_resumePlay();
	static void s_pauseToMain();
};
#endif