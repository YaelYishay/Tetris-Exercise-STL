#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

using namespace sf;

using std::make_unique;
using std::unique_ptr;

class Square
{
public:
	Square(Color);
	~Square();
	void setPosition(Vector2f v) { m_square->setPosition(v); }
	Vector2f getPosition()const { return m_square->getPosition(); }
	Color getFillColor()const { return m_square->getFillColor(); }
	void draw(RenderWindow&)const;
	FloatRect getGlobalBounds()const { return m_square->getGlobalBounds(); }

protected:
	unique_ptr<RectangleShape> m_square;
};
