#include "stdafx.h"
#include "DataBase.h"

//c-tor
DataBase::DataBase(){

	//get background pic
	m_texture.loadFromFile("background.png");
	//get fonts
	m_font.loadFromFile("font.ttf");
}

DataBase::~DataBase()
{
}

DataBase & DataBase::instance()
{
	static DataBase inst;
	return inst;
}
