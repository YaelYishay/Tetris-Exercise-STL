#pragma once
#include "ShapeA.h"
#include "ShapeB.h"
#include "ShapeC.h"
#include "ShapeD.h"
#include "ShapeE.h"
#include "ShapeF.h"
#include "ShapeG.h"
#include "Bar.h"
#include "Board.h"
#include <memory>

using std::unique_ptr;
using std::make_unique;

class Level
{
public:
	Level(Bar&);
	~Level() { ; }
	void draw(RenderWindow&) const;
	void run(RenderWindow&);
	bool checkCollision();
	void randomShape();
	void updateSpeed() { m_shape->incSpeed(); }

private:
	unique_ptr<Board> m_board;
	Clock m_clock;
	unique_ptr<shape> m_shape;
	Bar &m_bar;

};

