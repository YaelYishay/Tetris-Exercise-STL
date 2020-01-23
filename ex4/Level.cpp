#include "stdafx.h"
#include "Level.h"

//c-tor
Level::Level(Bar& b) 
	:m_bar(b),
	m_board(make_unique<Board>()){
	randomShape();
}
//draw level
void Level::draw(RenderWindow& window)const{

	m_board->draw(window);
	m_shape->draw(window);
	m_bar.draw(window);
}
//run level function
void Level::run(RenderWindow & window)
{
	Event event;
	int time = 0; // time level
	m_clock.restart(); // restart clock
	float tempTime = 0;

	while (window.isOpen() && time < 80) {

		//get secondes clock
		time = m_clock.getElapsedTime().asSeconds();
		window.clear();

		//if not collision move shape
		if (!checkCollision())
			m_shape->move(m_clock.getElapsedTime().asSeconds(), tempTime);

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape)
					window.close();

				//user event
				switch (event.key.code) {
				case Keyboard::Up:
						m_shape->rotate(90);
					break;
				case Keyboard::Right:
					m_shape->setDirection(RIGHT);
					break;
				case Keyboard::Left:
					m_shape->setDirection(LEFT);
					break;
				case Keyboard::Down:
					m_shape->setDirection(DOWN);
					break;
				}
			}
		}
		this->draw(window);
		window.display();
	}
	window.clear();
}
//check collision
bool Level::checkCollision() 
{
	//collision with range board
	if (m_shape->collideWith(m_board->range())) {
		m_shape->updateLocation();
		return true;
	}
	//collision with bottom board
	if (m_shape->collideWith(m_board->bottomLine()) ||
		m_shape->collideWith(m_board)) {

		//update for last position
		m_shape->updateLocation();

		//insert shape to board
		m_shape->updateBoard(m_board);

		//erase function
		m_bar.increaseScore(m_board->eraseFunc());

		randomShape();

		return true;
	}
	return false;
}
//rand new shape
void Level::randomShape()
{
	switch (rand() % 7)
	{
	case 0:
		m_shape = make_unique<ShapeA>();
		break;
	case 1:
		m_shape = make_unique<ShapeB>();
		break;
	case 2:
		m_shape = make_unique<ShapeC>();
		break;
	case 3:
		m_shape = make_unique<ShapeD>();
		break;
	case 4:
		m_shape = make_unique<ShapeE>();
		break;
	case 5:
		m_shape = make_unique<ShapeF>();
		break;
	case 6:
		m_shape = make_unique<ShapeG>();
		break;
	default:
		break;
	}
}
