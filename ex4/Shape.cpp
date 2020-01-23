#include "stdafx.h"
#include "Shape.h"
#include <iostream>
//c-tor
shape::shape()
	:m_speed(1/3.f)
{
	Color color = randomColor();
	for (size_t i = 0; i < 4; i++)
		m_shape.emplace_back(make_unique<DynamicSquare>(color));
}

//draw shape
void shape::draw(RenderWindow& window)const{
	for_each(m_shape.begin(), m_shape.end(),
		[&window](const auto& s) { s->draw(window); });
}
//rotate shape
void shape::rotate(int degRotate){
	for_each(m_shape.begin(), m_shape.end(),
		[degRotate](const auto& s) { s->rotate(degRotate); });
}
//move shape
void shape::move(float deltaTime, float& lastDeltaTime)
{
	if (deltaTime - lastDeltaTime < m_speed)
		return;

	lastDeltaTime = deltaTime;
	m_lastPosition = m_position;

	switch (m_direction)
	{
	case RIGHT:
		m_position.x += 60;
		break;
	case LEFT:
		m_position.x -= 60;
		break;
	case DOWN:
		incSpeed();
		break;
	case DEFULT:
		m_position.y += 60;
	default:
		break;
	}
	m_direction = DEFULT;
	setPosition();
}
//check colision with range board
bool shape::collideWith(const Vector2f & range)const
{
	return any_of(m_shape.begin(), m_shape.end(), [&range](const auto& d) {
		return d->getGlobalBounds().left > range.x
			|| d->getGlobalBounds().left < range.y; });
}
//check colision with bottom board 
bool shape::collideWith(float bottomLine)const
{
	return any_of(m_shape.begin(), m_shape.end(),[&bottomLine](const auto& d) {
		return d->getGlobalBounds().top > bottomLine; });
}

//if collide with board return true
bool shape::collideWith(unique_ptr<Board>& b) const{

	return any_of(m_shape.begin(), m_shape.end(),
		[&b](const auto& s) { return !b->isEmpty(s); });
}
//insert shape to board
void shape::updateBoard(unique_ptr<Board>& b)
{
	for_each(m_shape.begin(), m_shape.end(),
		[&b](const auto& s) {b->insert(s); });
}
//update shape location
void shape::updateLocation()
{
	m_position = m_lastPosition;
	m_direction = DEFULT;
	setPosition();
}
//set position square
void shape::setPosition()
{
	for_each(m_shape.begin(), m_shape.end(),
		[this](const auto& s)
	{s->setPosition(m_position); });
}
//rand color func
Color shape::randomColor()const
{
	const int threshold = 50;
	while (true)
	{
		Color c(std::rand(), std::rand(), std::rand());
		if (c.r + c.b + c.g >= threshold && c.a >= threshold)
			return c;
	}
}