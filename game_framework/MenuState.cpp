#include "MenuState.h"
void MenuState::update(){
	if(!m_gameObjects.empty()){
			for(int i = 0; i < m_gameObjects.size(); i++){
				if(!m_gameObjects.empty() && m_gameObjects[i] != 0){
					m_gameObjects[i]->update();
				}
			}
    }
}
void MenuState::render(){
	if(!m_gameObjects.empty()){
        for(int i = 0; i < m_gameObjects.size(); i++){
			if(m_gameObjects[i] != 0){
				m_gameObjects[i]->draw();
			}
        }
    }
}
bool MenuState::onEnter(){
	std::cout<<"Entering menustate\n";
	if(!TheTextureManager::Instance()->load("assets/button.png","playbutton", TheGame::Instance()->getRenderer())){
		return false;
	}
	if(!TheTextureManager::Instance()->load("assets/exit.png","exitbutton", TheGame::Instance()->getRenderer())){
		return false;
	}
	GameObject* button1 = new MenuButton(new LoaderParams(100, 100,400, 100, "playbutton"),s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(100, 300,400, 100, "exitbutton"),s_exitFromMenu);
	m_gameObjects.push_back(button2);
	m_gameObjects.push_back(button1);
	std::cout << "entering MenuState\n";
	return true;
}
bool MenuState::onExit(){
	std::cout<<"Exiting menustate\n";
	for(int i = 0; i < m_gameObjects.size(); i++){
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
	std::cout << "exiting MenuState\n";
	return true;
}
std::string MenuState::getStateID(){
	return s_menuID;
}
void MenuState::s_exitFromMenu(){
	TheGame::Instance()->quit();
}
void MenuState::s_menuToPlay(){
	std::cout<<"Entering menustate\n";
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}
const std::string MenuState::s_menuID="MENU";