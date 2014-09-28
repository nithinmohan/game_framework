#include "PauseState.h"
void PauseState::update(){
	if(!m_gameObjects.empty()){
		for(std::vector<GameObject*>::size_type i = 0; i <m_gameObjects.size(); i++){
			std::cout<<"asa";
			m_gameObjects[i]->update();
			std::cout<<"asab";
		}
	}
}
void PauseState::render(){
	std::cout<<"render pausestate\n";
	for(std::vector<GameObject*>::size_type i = 0; i <m_gameObjects.size(); i++){
		m_gameObjects[i]->draw();
	}
}
bool PauseState::onEnter(){
	std::cout<<"enter pausestate\n";
	if(!TheTextureManager::Instance()->load("assets/resume.png","resumebutton", TheGame::Instance()->getRenderer())){
		return false;
	}
	if(!TheTextureManager::Instance()->load("assets/main.png","mainbutton", TheGame::Instance()->getRenderer())){
		return false;
	}
	GameObject* button1 = new MenuButton(new LoaderParams(200, 100,200, 80, "mainbutton"), s_pauseToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300,200, 80, "resumebutton"), s_resumePlay);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}
bool PauseState::onExit(){
	for(int i = 0; i < m_gameObjects.size(); i++){
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("resumebutton");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	TheInputHandler::Instance()->reset();
	std::cout << "exiting PauseState\n";
	return true;
}
std::string PauseState::getStateID(){
	return s_pauseID;
}
void PauseState::s_resumePlay(){
	TheGame::Instance()->getStateMachine()->popState();
}
void PauseState::s_pauseToMain(){
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}
const std::string PauseState::s_pauseID="PAUSE";