#pragma once
#include "Square.h"

class StaticSquare :public Square
{
public:
	StaticSquare() :Square(Color::White) { ; }
	~StaticSquare() { ; }
	bool lock()const { return m_lock; }
	void updateLock() { m_lock = true; }
	void setFillColor(Color c) { m_square->setFillColor(c); }

private:
	bool m_lock = false;
};

