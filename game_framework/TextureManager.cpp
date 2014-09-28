#include "TextureManager.h"
#include <SDL_image.h>
bool TextureManager::load(std::string filename,std::string id,SDL_Renderer* renderer){
	SDL_Surface* pTempSurface=IMG_Load(filename.c_str());
	if(pTempSurface)
		std::cout<<"image found\n";
	else{
		std::cout<<IMG_GetError();
		return false;
	}
	SDL_Texture* pTexture=SDL_CreateTextureFromSurface(renderer,pTempSurface);
	SDL_FreeSurface(pTempSurface);
	m_textureMap[id]=pTexture;
	return true;
}
void TextureManager::draw(std::string id,int x,int y,int width,int height,SDL_Renderer* renderer,SDL_RendererFlip flip){
	SDL_Texture* pTexture=m_textureMap[id];
	SDL_Rect destinationRectangle;
	SDL_Rect sourceRectangle;
	sourceRectangle.x = 0;
	sourceRectangle.y = 0;
	destinationRectangle.x = x;
	destinationRectangle.y = y;
	destinationRectangle.w = sourceRectangle.w=width;
	destinationRectangle.h = sourceRectangle.h=height;
	SDL_RenderCopyEx(renderer,pTexture,&sourceRectangle,&destinationRectangle,0,0,flip);
}
void TextureManager::drawFrame(std::string id,int x,int y,int width,int height,int currentRow,int currentFrame,SDL_Renderer* renderer,SDL_RendererFlip flip){
	SDL_Texture* pTexture=m_textureMap[id];
	SDL_Rect destinationRectangle;
	SDL_Rect sourceRectangle;
	sourceRectangle.x = currentFrame*width;
	sourceRectangle.y = (currentRow-1)*height;
	destinationRectangle.x = x;
	destinationRectangle.y = y;
	destinationRectangle.w = sourceRectangle.w=width;
	destinationRectangle.h = sourceRectangle.h=height;
	SDL_RenderCopyEx(renderer,pTexture,&sourceRectangle,&destinationRectangle,0,0,flip);
}
void TextureManager::clearFromTextureMap(std::string id){
	m_textureMap.erase(id);
}
TextureManager* TextureManager::s_pInstance=0;