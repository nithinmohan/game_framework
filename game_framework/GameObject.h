#ifndef _GAMEOBJECT_
#define _GAMEOBJECT_
#include <iostream>
#include <string>
#include "LoaderParams.h"
class GameObject{
public:
	virtual void draw()=0;
	virtual void update()=0;
	virtual void clean()=0;
protected:
	GameObject(const LoaderParams *pParams){};
	virtual ~GameObject(){};
};
#endif