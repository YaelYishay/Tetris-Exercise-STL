#pragma once
#include "DynamicSquare.h"
#include <vector>
#include "Board.h"

using std::vector;
enum Direction {RIGHT, LEFT ,DOWN, UP,DEFULT};

class shape
{
public:
	shape();
	~shape() { ; }
	void draw(RenderWindow&)const;
	void rotate(int);
	void move(float,float&);
	void setDirection(Direction d) { m_direction = d; }
	bool collideWith(const Vector2f & range) const;
	bool collideWith(float bottomLine) const;
	bool collideWith(unique_ptr<Board>&) const;
	void updateBoard(unique_ptr<Board>&);
	void updateLocation();
	void incSpeed() { m_speed -= 1 / 15.f; }

protected:
	virtual void setOrigin() = 0;
	void setPosition();
	Color randomColor()const;

	vector<unique_ptr<DynamicSquare>> m_shape;
	Vector2f m_position;
	Vector2f m_lastPosition;
	Direction m_direction = DEFULT;
	float m_speed;
};
