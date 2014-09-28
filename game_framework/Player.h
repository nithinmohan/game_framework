#ifndef _PLAYER_
#define _PLAYER_
#include "SDLGameObject.h"
#include "InputHandler.h"
class Player : public SDLGameObject{
public:
	Player(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
	void handleInput();
};
#endif