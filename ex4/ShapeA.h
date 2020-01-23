#pragma once
#include "Shape.h"

class ShapeA :
	public shape
{
public:
	ShapeA();
	~ShapeA();
private:
	virtual void setOrigin()override;


};

