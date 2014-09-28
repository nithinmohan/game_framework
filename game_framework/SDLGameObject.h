#ifndef _SDLGAMEOBJECT_
#define _SDLGAMEOBJECT_
#include "SDL.h"
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject:public GameObject{
public:
	SDLGameObject(const LoaderParams *pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
protected:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	int m_width;
	int m_height;
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
};
#endif