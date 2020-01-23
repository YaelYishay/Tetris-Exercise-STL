#pragma once
#include <algorithm>
#include "StaticSquare.h"
#include "DynamicSquare.h"
#include "DataBase.h"
#include <memory>
#include <experimental/vector>
#include <numeric>
#include <deque>

using namespace std;


class Board
{
public:
	Board(float, float);
	Board();
	~Board() { ; }
	void draw(RenderWindow& )const;
	float bottomLine() const { return (m_size.y+1)*60; }
	Vector2f range()const { return { m_size.x*60,0 }; }
	void insert(const unique_ptr<DynamicSquare>&);
	bool isEmpty(const unique_ptr<DynamicSquare> &)const;
	int eraseFunc();
	bool isFull()const;

private:
	void initBoard();
	void setPosition();
	int count(const vector<unique_ptr<StaticSquare>>& v) const;
	deque<vector<unique_ptr<StaticSquare>>> m_board;
	Vector2f m_size = { 10,20 };
	Texture m_pic;
};
