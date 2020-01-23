#pragma once
#include "Shape.h"
class ShapeE :
	public shape
{
public:
	ShapeE();
	~ShapeE();
private:
	virtual void setOrigin()override;


};

