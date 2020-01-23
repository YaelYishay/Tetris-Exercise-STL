#include "stdafx.h"
#include "Bar.h"

//c-tor
Bar::Bar()
	: m_font(DataBase::instance().loadFont()),
	m_bar("Score:            Level:    ", m_font, 40)
{
	//set bar position
	m_bar.setFillColor(sf::Color::Black);
	m_bar.setPosition(10, 10);

	//init m_date
	for (size_t i = 0; i < 2; i++) {
		m_data.emplace_back(std::make_unique<sf::Text>());
		m_data[i]->setFont(m_font);
		m_data[i]->setCharacterSize(40);
		m_data[i]->setFillColor(sf::Color::Black);
		m_data[i]->setPosition((float)(130 + i * 220), 10);
	}
}
//draw bar
void Bar::draw(sf::RenderWindow & window) 
{
	m_data[0]->setString(to_string(m_score));
	m_data[1]->setString(to_string(m_level));

	window.draw(m_bar);
	for (size_t i = 0; i < m_data.size(); i++)
		window.draw(*m_data[i]);
}
