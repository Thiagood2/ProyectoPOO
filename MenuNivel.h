#ifndef MENUNIVEL_H
#define MENUNIVEL_H
#include "Scene.h"
#include "Game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <vector>
#include <SFML/Graphics/Sprite.hpp>
using namespace std;

class MenuNivel : public Scene{
public:
	MenuNivel();
	void Update(Game &g) override;
	void Draw(RenderWindow &window) override;
	void MoveUp();
	void MoveDown();
private:
	Font m_font;
	vector<Text>diffyculty;
	int select_item;
	int Max_Items_Diffyculty = 3;
	Sprite s_logo;
	Texture t_logo;
	
};

#endif

