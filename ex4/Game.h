#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Bar.h"

using sf::VideoMode;
using sf::RenderWindow;

class Game
{
public:
	Game();
	~Game() { ; }
	void run();

private:
	RenderWindow m_window;
	Bar m_bar;
	unique_ptr<Level> m_level;
};

