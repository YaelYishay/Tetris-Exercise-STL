#include "stdafx.h"
#include "ShapeC.h"
//c-tor
ShapeC::ShapeC()
{
	m_position = { 10 * 60 / 2 +10 ,160 };
	this->setPosition();

	setOrigin();
}

ShapeC::~ShapeC()
{
}
// //init origin
void ShapeC::setOrigin()
{
	m_shape[0]->setOrigin({ 0,60 });
	m_shape[1]->setOrigin({ 60, 0 });
	m_shape[2]->setOrigin({ 60,60 });
	m_shape[3]->setOrigin({ 0, 0 });
}


