#include "stdafx.h"
#include "ShapeG.h"

//c-tor
ShapeG::ShapeG()
{
	m_position = { 10 * 60 / 2+40,190 };

	this->setPosition();
	setOrigin();
}

ShapeG::~ShapeG()
{
}
//init origin
void ShapeG::setOrigin()
{
	m_shape[0]->setOrigin({ 90,30 });
	m_shape[1]->setOrigin({ 30, 30 });
	m_shape[2]->setOrigin({ 30, 90 });
	m_shape[3]->setOrigin({ -30,30  });
}


