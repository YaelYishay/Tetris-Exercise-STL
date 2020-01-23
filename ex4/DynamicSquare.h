#pragma once
#include "Square.h"

class DynamicSquare :
	public Square
{
public:
	DynamicSquare(Color c) :Square(c) { ; }
	~DynamicSquare() { ; }
	void setOrigin(Vector2f v) { m_square->setOrigin(v); }
	Vector2f getOrigin() { return m_square->getOrigin(); }
	void rotate(int degRotate) { m_square->rotate(degRotate); }

};

