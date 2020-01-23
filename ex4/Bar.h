#pragma once
#include <SFML/Graphics.hpp>
#include "DataBase.h"
#include <memory>

using std::to_string;
using std::unique_ptr;
using std::vector;

class Bar
{
public:
	Bar();
	~Bar() { ; }
	int getLevel()const { return m_level; } 
	void increaseLevel() {m_level++;}
	void increaseScore(int i) { m_score += 1000*i; }
	void draw(sf::RenderWindow&);

private:
	int m_level = 1; 
	int m_score = 0;
	sf::Font m_font;
	vector<unique_ptr<sf::Text>> m_data;
	sf::Text m_bar;

};

