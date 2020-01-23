#pragma once
#include "Shape.h"
class ShapeB :
	public shape
{
public:
	ShapeB();
	~ShapeB();

private:
	virtual void setOrigin()override;

};

