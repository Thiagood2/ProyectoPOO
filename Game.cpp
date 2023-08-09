#include "Game.h"
#include <SFML/Window/Event.hpp>
#include "Menu.h"
#include "Scene.h"
Game::Game(): m_window(VideoMode(800,600), "Akari Breackout"){
	m_window.setFramerateLimit(30);
	m_scene = new Menu();
}

void Game::Run (){
	while(m_window.isOpen()) {
		ProcessEvents();
		Update();
		Draw();
		if(m_next_scene){
			delete m_scene;
			m_scene = m_next_scene;
			m_next_scene = nullptr;
		}
	}
}

void Game::ProcessEvents (){
	Event e;
	while(m_window.pollEvent(e)) {
		if(e.type == Event::Closed)
			m_window.close();
	}
}

void Game::Draw (){
	m_scene ->Draw(m_window);
}

void Game::Update(){
	m_scene ->Update(*this);
}


void Game::SetScene (Scene *new_scene){
	delete m_scene;
	m_scene = new_scene;
}
