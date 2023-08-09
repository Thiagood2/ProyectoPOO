#include "MenuNivel.h"
#include <SFML/Window/Keyboard.hpp>
#include "Menu.h"

MenuNivel::MenuNivel() {
	m_font.loadFromFile("Baxoe.ttf");
	t_logo.loadFromFile("logotipo.png");
	s_logo.setTexture(t_logo);
	s_logo.setPosition(170,150);
	
	
	int Var_y = 300; // Variable auxiliar para el eje Y
	diffyculty.resize(Max_Items_Diffyculty);
	
	for(int i=0;i<Max_Items_Diffyculty;i++){
		diffyculty[i].setFont(m_font);
		diffyculty[i].setCharacterSize(25);
		diffyculty[i].setPosition(350,Var_y);
		Var_y += 70;
	}
	
	diffyculty[0].setFillColor(Color::Green);
	diffyculty[1].setFillColor(Color::White);
	diffyculty[2].setFillColor(Color::White);
	
	diffyculty[0].setString("Facil");
	diffyculty[1].setString("Intermedio");
	diffyculty[2].setString("Dificil");
	
	select_item = 0;
	
	
}

void MenuNivel::Update(Game &g){
	 // PARA VOLVER AL MENU 
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		g.SetScene( new Menu());
	}
	
	// MENU DE Seleccion de Nivel 
	if(Keyboard::isKeyPressed(Keyboard::Key::Up)){
		MoveUp();
	}else{
		if(Keyboard::isKeyPressed(Keyboard::Key::Down)){
			MoveDown();
		}
	}
	// Cuando se Presiona Enter, a que Escena Cambia
	if((diffyculty[select_item].getString()== diffyculty[0].getString()) and Keyboard::isKeyPressed(Keyboard::Return)){
		/*g.SetScene(new MatchEasy);*/
	}
	if((diffyculty[select_item].getString()== diffyculty[1].getString()) and Keyboard::isKeyPressed(Keyboard::Return)){
		/*g.SetScene(new MatchMedium);*/
	}
	if((diffyculty[select_item].getString()== diffyculty[2].getString()) and Keyboard::isKeyPressed(Keyboard::Return)){
		/*g.SetScene(new MatchHard);*/
	}
	
}


void MenuNivel::Draw(RenderWindow &window){
	window.clear({0,0,0});
	window.draw(s_logo);
	
	for(int i=0;i<Max_Items_Diffyculty;i++){
		window.draw(diffyculty[i]);
	}
	window.display();
}

void MenuNivel::MoveUp(){
	if(select_item - 1 >= 0 ){
		diffyculty[select_item].setFillColor(Color::White);
		select_item--;
		diffyculty[select_item].setFillColor(Color::Green);
	}
}


void MenuNivel::MoveDown(){
	if(select_item + 1 < Max_Items_Diffyculty ){
		diffyculty[select_item].setFillColor(Color::White);
		select_item++;
		diffyculty[select_item].setFillColor(Color::Green);
	}
}

