#ifndef _PLAYSTATE_
#define _PLAYSTATE_
#include "GameState.h"
#include "Player.h"
#include "TextureManager.h"
#include "Game.h"
#include "PauseState.h"
class PlayState:public GameState{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID();
private:
	std::vector<GameObject*> m_gameObjects;
	const static std::string s_playID;
};
#endif