#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"
using namespace sf;

class Game {
public:
	Game();
	void Run();
	void Draw();
	void Update();
	void ProcessEvents();
	void SetScene (Scene *new_scene);

private:
	RenderWindow m_window;
	Scene *m_scene;
	Scene *m_next_scene = nullptr;
};

#endif

