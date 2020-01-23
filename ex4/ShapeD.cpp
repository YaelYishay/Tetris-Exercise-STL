#include "stdafx.h"
#include "ShapeD.h"
//c-tor
ShapeD::ShapeD()
{
	m_position = { 10 * 60 / 2 +10 ,160 };
	this->setPosition();

	setOrigin();
}

ShapeD::~ShapeD()
{
}
//init origin
void ShapeD::setOrigin()
{
	m_shape[0]->setOrigin({ 60, 60 });
	m_shape[1]->setOrigin({ 0, 60 });
	m_shape[2]->setOrigin({ 0, -60 });
	m_shape[3]->setOrigin({ 0, 0 });
}
