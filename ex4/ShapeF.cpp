#include "stdafx.h"
#include "ShapeF.h"

//c-tor
ShapeF::ShapeF()
{
	m_position = { 10 * 60 / 2 +10,160 };
	this->setPosition();

	setOrigin();
}

ShapeF::~ShapeF()
{
}
//init origin
void ShapeF::setOrigin()
{
	m_shape[0]->setOrigin({ 60,60 });
	m_shape[1]->setOrigin({ 60, 0 });
	m_shape[2]->setOrigin({ 0, 0 });
	m_shape[3]->setOrigin({ 0, -60 });
}

