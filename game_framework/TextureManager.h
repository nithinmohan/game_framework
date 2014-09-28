#ifndef _TEXTUREMANAGER_
#define _TEXTUREMANAGER_
#include "SDL.h"
#include<iostream>
#include<map>
#include<string>
class TextureManager{
public:
	bool load(std::string filename,std::string id,SDL_Renderer* renderer);
	void draw(std::string id,int x,int y,int width,int height,SDL_Renderer* renderer,SDL_RendererFlip=SDL_FLIP_NONE);
	void drawFrame(std::string id,int x,int y,int width,int height,int currentRow,int currentFrame,SDL_Renderer* renderer,SDL_RendererFlip=SDL_FLIP_NONE);
	static TextureManager* Instance(){
		if(s_pInstance==0){
			s_pInstance=new TextureManager();
		}
		return s_pInstance;
	}
	void clearFromTextureMap(std::string id);
private:
	TextureManager(){};
	std::map <std::string,SDL_Texture*> m_textureMap;
	static TextureManager* s_pInstance;
};
typedef TextureManager TheTextureManager;
#endif