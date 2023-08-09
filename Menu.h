#ifndef MENU_H
#define MENU_H
#include "Game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>

using namespace std;

class Menu : public Scene {
public:
	Menu();
	void Update(Game &g) override;
	void Draw(RenderWindow &window) override;
	void MoveUp();
	void MoveDown();
private:
	vector<Text>option;
	int Max_Items_Menu;
	int selectItem;
	Sprite s_logo;
	Texture t_logo;
	Font m_font;
};

#endif

