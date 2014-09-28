#include <iostream>
#include "Game.h"

bool Game::init(const char* title,int xpos,int ypos,int width,int height, bool fullscreen){
	int flags=0;
	if(fullscreen==true)
		flags=SDL_WINDOW_FULLSCREEN;
	if(SDL_Init(SDL_INIT_EVERYTHING)==0&&(m_pWindow=SDL_CreateWindow(title,xpos,ypos,width,height,flags))&&(m_pRenderer=SDL_CreateRenderer(m_pWindow,-1,0))){
		std::cout<< "success\n";
		SDL_SetRenderDrawColor(m_pRenderer,255,255,0,255);
		m_bRunning=true;
		m_pGameStateMachine = new GameStateMachine();
		m_pGameStateMachine->pushState(new MenuState());
		TheInputHandler::Instance()->initializeJoysticks();
		return true;
	}
	else{
		std::cout<<"failed\n";
		return false;
	}
}
void Game::render(){
	SDL_RenderClear(m_pRenderer);
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);
}
void Game::update(){
	m_pGameStateMachine->update();
}
void Game::clean(){
	std::cout<<"cleaning\n";
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
void Game::handleEvents(){
	InputHandler::Instance()->update();
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)){
		m_pGameStateMachine->changeState(new PlayState());
		
	}
}
Game* Game::s_pInstance=0;