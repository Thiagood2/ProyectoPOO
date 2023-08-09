#include "Menu.h"
#include <SFML/Window/Keyboard.hpp>
#include "MenuNivel.h"
#include <iostream>
using namespace std;

Menu::Menu() {
	t_logo.loadFromFile("logotipo.png");
	s_logo.setTexture(t_logo);
	s_logo.setPosition(170,150);
	
	m_font.loadFromFile("Baxoe.ttf");
	
	
	int Var_y = 300;
	option.resize(Max_Items_Menu);
	
	for(int i=0;i<Max_Items_Menu;i++){
		option[i].setFont(m_font);
		option[i].setCharacterSize(30);
		option[i].setPosition(350,Var_y);
		Var_y +=70;
	}
	
	option[0].setFillColor(Color::Green);
	option[1].setFillColor(Color::White);
	option[2].setFillColor(Color::White);
	
	option[0].setString("PLAY");
	option[1].setString("SCORES");
	option[2].setString("EXIT");
	
	
	selectItem = 0;
	
	
	
}

void Menu::Update(Game &g){
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Up)){
		MoveUp();
	}
	if(Keyboard::isKeyPressed(Keyboard::Key::Down)){
		MoveDown();
	}
	
	if((option[selectItem].getString()== option[0].getString()) and Keyboard::isKeyPressed(Keyboard::Return)){
		g.SetScene(new MenuNivel());
	}

}


void Menu::Draw(RenderWindow &window){
	window.clear({0,0,0});
	window.draw(s_logo);
	for(int i=0;i<Max_Items_Menu;i++){
		window.draw(option[i]);
	}
	window.display();
}

void Menu::MoveUp(){
	if(selectItem - 1 >= 0 ){
		option[selectItem].setFillColor(Color::White);
		selectItem--;
		option[selectItem].setFillColor(Color::Green);
	}
}


void Menu::MoveDown(){
	if(selectItem + 1 < Max_Items_Menu ){
		option[selectItem].setFillColor(Color::White);
		selectItem++;
		option[selectItem].setFillColor(Color::Green);
	}
}

