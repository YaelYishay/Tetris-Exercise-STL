#include "stdafx.h"
#include "ShapeB.h"
//c-tor
ShapeB::ShapeB(){

	m_position = { 10 * 60 / 2 +10  ,220 };
	this->setPosition();
	
	setOrigin();
}

ShapeB::~ShapeB()
{
}
//init origin
void ShapeB::setOrigin()
{
	m_shape[0]->setOrigin({ 60, 60 });
	m_shape[1]->setOrigin({ 60, 0 });
	m_shape[2]->setOrigin({ 0, 60 });
	m_shape[3]->setOrigin({ 0, 120 });
}

