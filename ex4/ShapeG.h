#pragma once
#include "Shape.h"
class ShapeG :
	public shape
{
public:
	ShapeG();
	~ShapeG();
private:
	virtual void setOrigin()override;

};

