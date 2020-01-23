#include "stdafx.h"
#include "ShapeE.h"


//c-tor
ShapeE::ShapeE()
{
	m_position = { 10 * 60 / 2 +10 ,160 };
	this->setPosition();

	setOrigin();
}

ShapeE::~ShapeE()
{
}
//init origin
void ShapeE::setOrigin()
{
	m_shape[0]->setOrigin({ 60, 60 });
	m_shape[1]->setOrigin({ 0, 60 });
	m_shape[2]->setOrigin({ 60, 0 });
	m_shape[3]->setOrigin({ 60, -60 });
}

