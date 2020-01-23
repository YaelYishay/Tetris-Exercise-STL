#include "stdafx.h"
#include "ShapeA.h"

//c-tor
ShapeA::ShapeA()
{
	m_position = { 10*60/2+10 ,160 };
	this->setPosition();

	setOrigin();
}

ShapeA::~ShapeA()
{
}
//init origin
void ShapeA::setOrigin(){

	m_shape[0]->setOrigin({ 120, 60 });
	m_shape[1]->setOrigin({ 60, 60 });
	m_shape[2]->setOrigin({ 0,60 });
	m_shape[3]->setOrigin({ -60,60 });
}
