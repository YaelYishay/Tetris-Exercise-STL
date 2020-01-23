#include "stdafx.h"
#include "Board.h"

//c-tor get width and heught
Board::Board(float width, float height)
	:m_size({ width,height }),
	m_pic(DataBase::instance().loadPic()){
	initBoard();
}
//defult c-tor 
Board::Board()
	:m_pic(DataBase::instance().loadPic()) {
	initBoard();
}

//initialization board 
void Board::initBoard()
{
	vector<unique_ptr<StaticSquare>> v;

	//create board
	for (auto j = 0; j < m_size.y; j++) {
		for (auto i = 0; i < m_size.x; i++)
			v.emplace_back(make_unique<StaticSquare>());
		m_board.emplace_back(move(v));
	}
	//update position of squares
	this->setPosition();
}

//update position of squares
void Board::setPosition()
{
	sf::Vector2f v = { 10.f,100 };

	for (size_t i = 0; i < m_size.y; i++) {
		v.x = 10.f;
		for (size_t j = 0; j < m_size.x; j++) {
			m_board[i][j]->setPosition(v);
			v.x += 60;
		}
		v.y += 60;
	}
}
//draw board
void Board::draw(RenderWindow& window)const
{
	Sprite sp;
	sp.setTexture(m_pic);
	window.draw(sp);

	//for each algo
	for_each(m_board.begin(), m_board.end(), [&window](const auto& v){
		for_each(v.begin(), v.end(), [&window, &v](const auto& s) 
		{ s->draw(window); });
	});
}

//calculate square position and insert new square
//update color square and update boolean m_lock to be true
void Board::insert(const unique_ptr<DynamicSquare> &s)
{
	//real square position 
	Vector2f v = { s->getGlobalBounds().top,s->getGlobalBounds().left };

	//calc position in board
	int row = (v.x / 60) -1, 
        col = v.y / 60; 

	//update color and lock
	m_board[row][col]->setFillColor(s->getFillColor());
	m_board[row][col]->updateLock();
}

//get square and return if his position is empty
//check if boolean m_lock is false ,which means square is empty
bool Board::isEmpty(const unique_ptr<DynamicSquare> &s) const
{
	Vector2f v = { s->getGlobalBounds().top,s->getGlobalBounds().left };

	//calc position
	int row = (v.x / 60) - 1,
		col = v.y / 60;

	//check m_lock
	if (m_board[row][col]->lock())
		return false;
	return true;
}

//get vector and count if all of squares has lock == true
//which means square is not empty using count_if algo
int Board::count(const vector<unique_ptr<StaticSquare>>& v) const{
	return count_if(v.begin(), v.end(),[](const auto& s) { return s->lock(); });
}

//check if board is full if one of the squares in the first line is true
//using any_of algo
bool Board::isFull() const
{
	return any_of(m_board[0].begin(), m_board[0].end(), [](const auto & i) {
		return i->lock() == true; });
}

//deletes a full row from the board using the erase algorithm
//and insert new row to board 
int Board::eraseFunc(){

	//erase algo
	m_board.erase(std::remove_if(m_board.begin(), m_board.end(),
		[this](const auto& i) { return this->count(i) == m_size.x; }),
		m_board.end());

	//the lines deleted
	int deleteCount = m_size.y - m_board.size();

	//insert new lines
	vector<unique_ptr<StaticSquare>> v;
	for (size_t j = 0; j < deleteCount; j++){
		for (auto i = 0; i < m_size.x; i++)
			v.emplace_back(make_unique<StaticSquare>());

		//insert algo
		m_board.insert(m_board.begin(),move(v));
	}
	//update position
	setPosition();

	return deleteCount;
}

