#pragma once
#include <SFML/Graphics.hpp>

class DataBase
{
public:
	~DataBase();
	static DataBase& instance();
	sf::Texture& loadPic() { return m_texture; }
	sf::Font loadFont()const { return m_font; }

private:
	DataBase();
	sf::Texture m_texture;
	sf::Font m_font;

};

