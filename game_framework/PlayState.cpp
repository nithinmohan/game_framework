#include "PlayState.h"
void PlayState::update(){
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)){
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}
	for(std::vector<GameObject*>::size_type i = 0; i !=m_gameObjects.size(); i++){
		m_gameObjects[i]->update();
	}
}
void PlayState::render(){
	for(std::vector<GameObject*>::size_type i = 0; i !=m_gameObjects.size(); i++){
		m_gameObjects[i]->draw();
	}
}
bool PlayState::onEnter(){
	std::cout<<"enter playstate";
	TheTextureManager::Instance()->load("assets/helicopter.png","helicopter",TheGame::Instance()->getRenderer());
	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 55,"helicopter")));
	return true;
}
bool PlayState::onExit(){
	for(int i = 0; i < m_gameObjects.size(); i++){
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting PlayState\n";
	return true;
}
std::string PlayState::getStateID(){
	return s_playID;
}
const std::string PlayState::s_playID="PLAY";