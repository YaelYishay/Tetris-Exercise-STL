#include "stdafx.h"
#include "Square.h"
//c-tor
Square::Square(Color  c)
{
	m_square = make_unique<RectangleShape>(sf::Vector2f(60, 60));
	m_square->setOutlineColor(Color(153,217,234));
	m_square->setOutlineThickness(1);
	m_square->setFillColor(c);
}

Square::~Square()
{
}
//draw Square
void Square::draw(RenderWindow& window)const {
	window.draw(*m_square);
}


